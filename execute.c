#include "main.h"

/**
 * execute - executes a programm
 * @cmnd: address of executable
 * @args: argv
 * Return: exit_status of programm
 */
int execute(char *cmnd, char **args)
{
	int pid;

	pid = fork();
	if (pid == 0)
	{
		execve(cmnd, args, environ);
		exit(0);
	}
	else
		wait(&exit_status);
	return (exit_status);
}
