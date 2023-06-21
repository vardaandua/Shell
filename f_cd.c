#include<stdio.h>
#include "headers.c"
int cd(char **args)
{
  if (!args[1])
  {
    fprintf(stderr, "Shell: expected argument to \"cd\"\n");
  }
  else
  {
    if (chdir(args[1]) != 0)
    {
      perror("Shell");
    }
  }
  return 1;
}