#include "headers.c"

// gives list of available builtins and how to operate
int help(char **args)
{
   
  int i;
  printf("Welcome to Shell by Vardaan : \n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  printf("cd\n");
  printf("help\n");
  printf("shell_exit\n"),
  printf("bg\n"),
  printf("history\n");

  return 1;
}