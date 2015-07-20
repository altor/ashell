#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "traitement_signal.h"


extern int bool;


void traitement_signal()
{
  //  void (*Preponse) (void) = &reponse;
  void (*Pexit) (void) = &exit_parent;

  
  signal(1,SIG_DFL);
  signal(2,SIG_DFL);
  signal(3,SIG_DFL);
  signal(4,SIG_DFL);
  signal(5,SIG_DFL);
  signal(6,SIG_DFL);
  signal(7,SIG_DFL);
  signal(8,SIG_DFL);
  signal(10,SIG_DFL);
  signal(11,SIG_DFL);
  signal(12,SIG_DFL);
  signal(13,SIG_DFL);
  signal(14,SIG_DFL);
  signal(15,SIG_DFL);
  signal(16,*Pexit);
}

  


void exit_parent(void)
{
  bool = 0;
}
