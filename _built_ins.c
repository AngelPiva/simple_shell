#include "main.h"

/**
 *built_ins - executes built ins
 *@buffer: string that represents the built_ins
 *Return: 0
 *
 */

int built_ins(char *buffer)
{
	char *_exit = "exit", *env = "env";

	if (buffer == _exit)
	{
		exit(0);
	}
	else if (buffer == env)
	{
		_printenv();
	}
	return (1);
}
