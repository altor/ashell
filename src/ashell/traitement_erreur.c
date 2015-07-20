#include <stdio.h>
#include <errno.h>
#include "traitement_erreur.h"

void erreur_execve()
{
  if(errno ==  EACCES)
    printf("ERREUR : Accès refusé\n");
  else if(errno == EAGAIN)
    printf("ERREUR : Ressource temporairement indisponible\n");
  else if(errno == EINVAL)
    printf("ERREUR : Argument invalide\n");
  else if(errno == ENOENT)
    printf("ERREUR : Fichier ou répertoire inexistant\n");
  else if(errno == ENOEXEC)
    printf("ERREUR : Exécution impossible\n");
  else if(errno == ENOMEM)
    printf("ERREUR : Pas assez de mémoire\n");
  else
    printf("ERREUR : Type d'erreur inconnue\n");
}
