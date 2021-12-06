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
		inte = isatty(0), status = 0;
		if (inte)
			write(1, "$ ", 2);
		chars = getline(&buffer, &size, stdin);
		if (chars == -1)
			break;
		if (buffer[chars - 1] == '\n')
			buffer[chars - 1] = 0;
		if (buffer[0] == 0)
			continue;
		array = split_str(buffer, ' ');
		if (!array)
			continue;
		if (array[0])
			status = search(array, argv[0]);
		_free_array(array);
		if (status == -1)
			break;
	}
	if (buffer)
		free(buffer);
	if (inte)
		write(1, "\n", 1);
	return (0);
}
