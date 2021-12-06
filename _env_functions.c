#include "main.h"

/**
 *_printenv - prints all the environment variables
 *Return: 0
 */

char _printenv(void)
{
	int n = 0;

	while (environ[n])
	{
		write(1, environ[n], _strlen(environ[n]));
		write(1, "\n", 2);
		n++;
	}
	return (0);
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
		{
			if (name[s] != environ[c][s])
			{
				found = 1;
				break;
			}
		}
		if (!found)
			break;
	}
	if (!environ[c])
		return (NULL);
	return (environ[c] + (s + 1));
}
