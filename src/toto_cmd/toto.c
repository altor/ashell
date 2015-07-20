#include <stdio.h>
#include <stdlib.h>


void parametre(char * argument);

int main(int argc,char ** argv)
{
  int i;
  for(i = 1;i < argc;i ++)
    {
      parametre(argv[i]);
    }
  exit(EXIT_SUCCESS);
    
}

void parametre(char * argument)
{
  if(argument[0] == '1')
    printf("toto\n");
  else if(argument[0] == '2')
    printf("titi\n");
  else if(argument[0] == '3')
    printf("tata\n");
  else {
    printf("mauvais argument\n");
    exit(EXIT_FAILURE);
  }
}
