#include "main.h"

/**
 * _cd - change directory
 * @args: args
 * @shell_name: name of my shell
 * Return: 0 on success
 */
int _cd(char **args, char *shell_name)
{
	int status;

	status = chdir(args[1]);
	if (status == -1)
		perror(shell_name);
	return (0);
}
