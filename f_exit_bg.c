#include "headers.c"


int shell_exit(char** args)
{
  return 0;
}
// bg command
int sh_bg(char **args)
{
  ++args;
  char *firstCmd = args[0]; // echo
  int childpid = fork();
  if (childpid >= 0)
  {
    if (childpid == 0)
    {
      if (execvp(firstCmd, args) < 0)
      {
        perror("Error on execvp\n");
        exit(0);
      }
    }
  }
  else
  {
    perror("fork() error");
  }
  return 1;
}
