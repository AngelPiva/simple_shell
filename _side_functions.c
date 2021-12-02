#include "main.h"
/**
 * free_array - frees an array of strings
 * @arr: array
 */
void free_array(char **arr)
{
	int a;

	if (!arr)
		return;
	for (a = 0; arr[a]; a++)
	{
		free(arr[a]);
	}
	free(arr);
}

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
 * _getenv - gets an environment variable
 * @name: name of the env variable
 * Return: pointer to the env varable
 */

char *_getenv(const char *name)
{
	int n = 0, run = 0;
	int size = 0;
	char *str = NULL;

	while (name[size])
		size++;

	while (environ[n])
	{
		if (strncmp(name, environ[n], size) == 0)
		{
			str = _strdup(environ[n]);
			while (str[run] != '=')
			{
				run++;
				++str;
			}
			return (str + 3);
		}
		n++;
	}
	return (0);
}
