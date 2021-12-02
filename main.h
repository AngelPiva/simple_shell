#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char **split_str(char *str, char sep);
void free_array(char **arr);
char *_strdup(const char *s);
char *_getenv(const char *name);
int _printenv(void);
extern char **environ;
int _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *s);

#endif
