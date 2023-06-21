#ifndef __LOG_H
#define __LOG_h
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h> // for inbuilt chdir(),fork(),exec(),pid_t functions
#include <stdlib.h> // for malloc(),realloc(),free(),exit(),execvp(),EXIT_SUCCESS, EXIT_FAILURE
#include <stdio.h>
#include <string.h> //strcmp(),strtok()
#define TOK_DELIM " \t\r\n\a"
#define TOK_BUFSIZE 64

int cd(char **args);
int num_builtins();
int execute(char **args);
int shell_exit(char** args);
int sh_bg(char **args);
int help(char **args);
int history(char **args);
int launch(char **args);
char *read_line(void);
char **split_line(char *line);


#endif