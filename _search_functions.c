#include "main.h"

/**
 * search_excutable - searches for executable
 * @args: argv
 * @shell_name: name of my shell
 * Return: status
 */

int search_excutable(char **args, char *shell_name)
{
	int exists, exit_status;

	(void)shell_name;
	exists = access(args[0], F_OK);
	if (exists == -1)
		return (1);
	exit_status = execute(args[0], args);
	return (exit_status);
}
