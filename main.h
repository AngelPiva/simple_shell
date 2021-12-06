#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

char **split_str(char *str, char sep);
void _free_array(char **arr);
char *_strdup(const char *s);
char *_getenv(const char *name);
char _printenv(void);
int built_ins(char *buffer);
extern char **environ;
int _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *s);
int execute(char *cmnd, char **args);
int search_executable(char **args, char *shell_name);
int search_path(char **args, char *shell_name);
int search_built_in(char **args, char *shell_name);

#endif
