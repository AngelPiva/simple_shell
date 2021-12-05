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
*_strlen - returns the length of a string
*@s: pointer
*Return: 0
*/

int _strlen(char *s)
{
	int c = 0;

	while (s[c] != '\0')
		c++;
	return (c);
}

/**
*_strncmp - compares two strings
*@s1: string 1
*@s2: string 2
*@n: first n bytes
*Return: t
*/

int _strncmp(char *s1, char *s2, size_t n)
{
	size_t r = 0, t = 0;

	while (s1[r] == s2[r] && s1[r] != '\0' && s2[r] != '\0' && r < n)
		r++;
	if (s1[r] != s2[r])
		t = s1[r] - s2[r];
	return (t);
}
