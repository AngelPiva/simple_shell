#include "main.h"
/**
 * _free_array - frees an array of strings
 * @arr: array
 */
void _free_array(char **arr)
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
	int c, s, found;

	if (!name)
		return (NULL);
	for (c = 0; environ[c]; c++)
	{
		found = 0;
		for (s = 0; name[s]; s++)
			if (name[s] != environ[c][s])
			{
				found = 1;
				break;
			}
		if (!found)
			break;
	}
	if (!environ[c])
		return (NULL);
	return (environ[c] + (s + 1));
}
