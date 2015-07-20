#include <stdio.h>
#include "commande.h"

#define FIN_BUFFER 0
#define ESPACE 32
#define RET 10


//fonction chargé de lire la commande et de l'enregistrer dans un buffer temporaire
void saisie_commande(char * buffer)
{
  int lettre;//variable utilisée pour stocker les caractères de sortie
  int i = 0;//compteur
  while ((lettre = getchar()) != RET)
    buffer[i++] = lettre;
  buffer[i] = 0;
}


//compte la taille du nom de la commande et la renvoie dans taille_nom

int compte_nom(char *buffer)
{
  int i;
  for(i = 0;buffer[i] != ESPACE && buffer[i] != FIN_BUFFER;i ++);
  return i;
}
//fonction chargée de compter le nombre d'argument et de calculer la taille du plus grand 
//Ces opérations sont effectuées à partir du tableaux buffer et enregistrées dans les variables nb_param et taille_param taille_nom
void compte_arguments(char *buffer,int * nb_param,int * taille_param,int * taille_nom)
{
  int i = *taille_nom;
  int mot = 0;

  if(buffer[i] == FIN_BUFFER){
    *nb_param = 0;
    *taille_param = *taille_nom;
  }

  else{
    for(i = ((*taille_nom)+1);buffer[i-1] != FIN_BUFFER;i ++)
      {
	if(buffer[i] != ESPACE && buffer[i] != FIN_BUFFER){
	  mot ++;
	}
	else {
	  *nb_param +=1 ;
	  if (mot > *taille_param)
	    *taille_param = mot;
	  mot = 0;
	}
      }
  }
}
//initialise le tableau paramètres avec les donnés contenues dans le buffer temporaire
void init_param(char * buffer,char ** parametres)
{

  int i = 0;
  int j = 0;
  int k = 0;
  for (i = 0;buffer[i] != FIN_BUFFER;i ++) {
    if (buffer[i] != ESPACE) {
      parametres[j][k] = buffer[i];
      k ++;
    } else {
      k = 0;
      j ++;
    }
  }
  //le dernier pointeur doit être initialisé a NULL
  j++;
  parametres[j] = NULL;
}
