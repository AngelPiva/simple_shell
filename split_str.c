#include "main.h"
/**
 * _strdup - duplicates a string
 * @s: string
 * Return: pointer to new string (z)
 */
char *_strdup(const char *s)
{
	char *z;
	int a;

	if (!s)
		return (NULL);
	for (a = 0; s[a]; a++)
		;
	z = malloc(sizeof(char *) * (a + 1));
	if (!z)
		return (NULL);
	for (a = 0; s[a]; a++)
		z[a] = s[a];
	return (z);
}

/**
 * split_str - splits string
 * @str: string
 * @sep: separator
 * Return: array of each word of the string
 */
char **split_str(char *str, char sep)
{
	char **out;
	char *token, *cpy;
	int amnt = 1, c;

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
	token = strtok(cpy, " ");
	for (c = 0; c < amnt; c++)
	{
		out[c] = _strdup(token);
		token = strtok(NULL, " ");
	}
	free(cpy);
	return (out);
}

/**
 * free_array - frees an array of strings
 * @arr: array
 */
void free_array(char **arr)
{
	int a;

	for (a = 0; arr[a]; a++)
		free(arr[a]);
	free(arr);
}
