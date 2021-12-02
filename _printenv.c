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
