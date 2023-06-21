#include "headers.c"


 char *builtin_str[] = {
        "cd",
        "help",
        "shell_exit",
        "bg",
        "history"
    };
    // pointers to respective functions
    int (*builtin_func[])(char **) = {
    &cd,
    &help,
    &shell_exit,
    &sh_bg,
    &history
    };

int num_builtins()
{
  return sizeof(builtin_str) / sizeof(char *);
}

// executing the builtins and calling launch() for rest.
int execute(char **args)
{

  int i;

  if (!args[0])
  {
    // An empty command was entered.
    return 1;
  }
  // search for builtins
  for (i = 0; i < num_builtins(); i++)
  {
    if (strcmp(args[0], builtin_str[i]) == 0)
    {
      return (*builtin_func[i])(args);
    }
  }

  return launch(args);
}