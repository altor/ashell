#ifndef COMMANDE_H
#define COMMANDE_H

void saisie_commande(char * buffer);
int compte_nom(char *buffer);
void compte_arguments(char * buffer,int * nb_param,int * taille_param,int * taille_nom);
void init_param(char * buffer,char ** parametres);


#endif
