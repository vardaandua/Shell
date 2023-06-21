#include "headers.c"

// some processes such as all the builtins just change the properties of
// spawned child and not of the parent process.For them I have builtins and for
// rest, I have following:
int launch(char **args)
{
  pid_t pid;
  int status;

  pid = fork();
  if (pid == 0)
  {
    // Child process
    if (execvp(args[0], args) == -1)
    {
      perror("Shell");
    }
    shell_exit((char** )EXIT_FAILURE);
  }
  else if (pid < 0)
  {
    // Error forking
    perror("Shell");
  }
  else
  {
    // Parent process
    do
    {
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}