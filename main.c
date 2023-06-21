
#include "headers.c"

#include  "f_execute.c"
#include  "f_cd.c"
#include  "f_help.c"
#include  "f_history.c"
#include  "f_exit_bg.c"
#include  "f_launch.c"
#include  "parse.c"

void loop(void)
{
  char *line;
  char **args;
  int status;
  do
  {
    printf("> ");
    line = read_line();
    args = split_line(line);
          add_to_hist(args);
    status = execute(args);

    free(line);
    free(args);
  } while (status);
}

int main(int argc, char **argv)
{
  loop();
  return EXIT_SUCCESS;
}