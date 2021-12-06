#include "main.h"
#include "string.h"

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
 *main - main
 * @argc: argument counter
 * @argv: argument lis
 *Return: succesfully 0
 */
int main(__attribute__ ((unused))int argc, char **argv)
{
	char *buffer;
	char **array = NULL;
	size_t size = 0;
	ssize_t chars = 0;
	int inte = 1, status;

	signal(SIGINT, INTERRUPT_MANAGER);
	while (inte)
	{
		(void)argv;
		inte = isatty(0);
		if (inte)
			write(1, "$ ", 2);
		chars = getline(&buffer, &size, stdin);
		if (chars == -1)
			break;
		buffer[chars - 1] = 0;
		array = split_str(buffer, ' ');
		status = search(array, argv[0]);
		_free_array(array);
	}
	if (buffer)
		free(buffer);
	if (inte)
		write(1, "\n", 1);
	return (0);
}

/**
 * search - searches for the command
 * @args: array of strings
 * @shell_name: name of my shell
 * Return: status
 */

int search(char **args, char *shell_name)
{
	int status;

	status = search_built_in(args, shell_name);
	if (!status)
		return (status);
	status = search_path(args, shell_name);
	if (!status)
		return (status);
	status = search_executable(args, shell_name);
	if (!status)
		return (status);
	perror(shell_name);
	perror("1: no such file or directory\n");
	return (status);
}
