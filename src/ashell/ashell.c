#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include "traitement_signal.h"
#include "traitement_erreur.h"

#include "commande.h"

#define MAX_BUFFER 1000
#define PROMPT "\n$"
#define BIN_DIR "./"
#define TAILLE_BIN_DIR 2

void afficher_vecteur(char *vecteur,int taille);
void afficher_matrice(char **matrice,int longeur,int largeur);

int bool = 1;

int main()
{
  //DECLARATION DES VARIABLES
  //compteur
  int i = 0;
  //tableaux
  char buffer[MAX_BUFFER];//buffer temporaire pour la saisie
  char ** parametres = NULL;//tableaux des paramètres
  char * path = NULL;//tableau contenant le chemin d'exécution de la commande
  //compteur utilisé dans la fonction compte_argument
  int nb_param = 0;
  int taille_param = 0;
  int taille_nom = 0;
  //variable utilisé lors du fork
  int status;
  //TRAITEMENT DU SIGNAL
  traitement_signal();

  while(bool){
    //SAISIE DE LA COMMANDE ET COMPTAGE DES ARGUMENTS
    printf("%s",PROMPT);//affichage du prompt
    saisie_commande(buffer);
    taille_nom = compte_nom(buffer);
    compte_arguments(buffer,&nb_param,&taille_param,&taille_nom);
    if(taille_nom > taille_param)//si la valeur de taille_nom est supérieur à celle de taille_param, on utilise celle de taille_nom
      taille_param = taille_nom;

    

    //RÉSERVATION MÉMOIRE ET INITIALISATION DES TABLEAUX
    
    parametres = calloc((nb_param+2),sizeof(char*));
    for (i = 0;i < (nb_param+2);i ++)
      parametres[i] = calloc((taille_param+1),sizeof(char));
    path = calloc((taille_nom+1+TAILLE_BIN_DIR),sizeof(char));
    init_param(buffer,parametres);
    strcpy(path,BIN_DIR);//on ajoute le chemin du bin en début de commande
    strcat(path,parametres[0]);//on ajoute à la suite le nom de la commande

    
    //FORK
    if (fork() != 0)
      wait(&status);
    else {
      if(execve(path,parametres,0) == -1){
	erreur_execve();
	exit(EXIT_FAILURE);
      }
    }   

    //LIBÉRATION DE LA MÉMOIRE
    for (i = 0;i < (nb_param+2);i ++)
      free(parametres[i]);
    free(parametres);
    free(path);
    //RÉ-INITIALISATION DES VARIABLES
    nb_param = 0;
    taille_param = 0;
    taille_nom = 0;
    }
  exit(EXIT_SUCCESS);
}

void afficher_vecteur(char *vecteur,int taille)
{
  int i = 0;
  printf("vecteur : |");
  for(i = 0;i < taille;i++)
    printf("%c|",vecteur[i]);
  printf("\n");
}
void afficher_matrice(char **matrice,int longeur,int largeur)
{
  int i;
  for(i = 0;i < longeur;i++)
    afficher_vecteur(matrice[i],largeur);
}
