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
