#include "main.h"

/**
 *_getenv - gets an environment variable
 *@name: name of the env variable
 *Return: pointer to the env varable
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
