#include "main.h"

/**
 * split_str - splits string
 * @str: string
 * @sep: separator
 * Return: array of each word of the string
 */
char **split_str(char *str, char sep)
{
	char **out = NULL;
	char *token = NULL, *cpy = NULL;
	int amnt = 1, c;
	char sep_s[2] = ".";

	sep_s[0] = sep;

	for (c = 0; str[c]; c++)
	{
		if (str[c] == sep)
			if (str[c + 1] != sep && str[c + 1])
				amnt++;
	}
	cpy = _strdup(str);
	if (!cpy)
		return (NULL);
	out = malloc(sizeof(char *) * (amnt + 1));
	if (!out)
	{
		free(cpy);
		return (NULL);
	}
	out[amnt] = NULL;
	token = strtok(cpy, sep_s);
	for (c = 0; token; c++)
	{
		out[c] = _strdup(token);
		token = strtok(NULL, sep_s);
	}
	free(cpy);
	return (out);
}
