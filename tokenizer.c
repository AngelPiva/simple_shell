#include "main.h"

/**
 *save_tok - takes a string and separates it by tokens
 *@buffer: string
 *@sep: string separator
 *Return:
 */

char **save_tok(char *buffer, char sep)
{
	char **array;
	char *token;
	int run = 0, count = 1;
	char *aux = malloc(1024);

	aux[0] = sep;

	while (buffer[run])
	{
		if (buffer[run] == sep && buffer[run + 1] != sep && buffer[run + 1])
		{
			count++;
		}
		run++;
	}
	array = malloc(sizeof(char *) * count);
	if (!array)
		return (NULL);

	token = strtok(buffer, aux);
	array[0] = token;
	run = 0;

	while (token)
	{
		token = strtok(NULL, aux);
		array[0] = token;
	}
	return (array);
}
