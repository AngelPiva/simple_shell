#include "main.h"

/**
 * INTERRUPT_MANAGER - interrupts programm
 * @signal: Ctrl c
 */

void INTERRUPT_MANAGER(int signal)
{
	if (signal)
		write(1, "\n$ ", 4);
}

/**
 * separate - parses a string
 * @buffer: string
 * @shell_name: string
 * Return: status
 */
int separate(char *buffer, char *shell_name)
{
	char **args, **times, **semicolons;
	int status = 0, a, lines, semic;

	times = split_str(buffer, '\n');
	for (lines = 0; times[lines]; lines++)
	{
		semicolons = split_str(times[lines], ';');
		if (times[lines])
			free(times[lines]);
		for (semic = 0; semicolons[semic]; semic++)
		{
			args = split_str(semicolons[semic], ' ');
			if (semicolons[semic])
				free(semicolons[semic]);
			if (!args)
				return (-1);
			status = search(args, shell_name);
			for (a = 0; args[a]; a++)
			{
				if (args[a])
					free(args[a]);
			}
			if (args)
				free(args);
			if (status == -1)
				break;
		}
		if (semicolons)
			free(semicolons);
		if (status == -1)
			break;
	}
	if (times)
		free(times);
	return (status);
}

/**
 *main - main
 * @argc: argument counter
 * @argv: argument lis
 *Return: succesfully 0
 */
int main(__attribute__ ((unused))int argc, char **argv)
{
	char *buffer = NULL;
	size_t size = 0;
	ssize_t chars = 0;
	int inte = 1, status;

	signal(SIGINT, INTERRUPT_MANAGER);
	while (inte)
	{
		inte = isatty(0), status = 0;
		if (inte)
			write(1, "$ ", 2);
		if (inte)
			chars = getline(&buffer, &size, stdin);
		else
		{
			buffer = malloc(1025);
			chars = read(0, buffer, 1024);
			buffer[chars - 1] = 0;
		}
		if (chars == -1)
			break;
		if (buffer[chars - 1] == '\n')
			buffer[chars - 1] = 0;
		if (buffer[0] == 0)
			continue;
		status = separate(buffer, argv[0]);
		if (buffer)
		if (status == -1)
			break;
	}
	free(buffer);
	if (inte)
		write(1, "\n", 1);
	return (0);
}
