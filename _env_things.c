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
 *_getenv - gets an environment variable
 *@name: name of the env variable
 *Return: pointer to the env varable
 */

char *_getenv(const char *name)
{
	int n = 0;
	int size = 0;
	char *str = NULL, *token = NULL;

	while (name[size])
		size++;

	while (environ[n])
	{
		if (strncmp(name, environ[n], size) == 0)
		{
			str = _strdup(environ[n]);
			token = strtok(str, "=");
			token = strtok(NULL, "=");
			return (token);
		}
		n++;
	}
	return (0);
}
