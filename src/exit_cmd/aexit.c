/*
EXIT : commande ashell permettant d'arrêter le processus parent (ici ashell)
Déroulement : exit demande le PID du processus parent puis lui envoi un signal qui doit être interprété par celui-ci comme un signal d'arrêt
*/

#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define SIG 16 //signal à envoyer au processus père


int main()
{
  int ppid = getppid();
  kill(ppid,SIG);
  return EXIT_SUCCESS;
}
