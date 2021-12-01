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

#endif