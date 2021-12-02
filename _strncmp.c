#include "main.h"

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
