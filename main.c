#include "main.h"
#include "string.h"


void INTERRUPT_MANAGER(int signal)
{
	if (signal)
		write(1, "\n$ ", 4);
}
/**
 *main - main
 *Return: succesfully 0
 */
int main(void)
{
	char *buffer = '\0';
	char **array = NULL;
	size_t size = 0;
	ssize_t chars = 0;
	int inte = 1;
	int exit_status;

	signal(SIGINT, INTERRUPT_MANAGER);
	while (inte)
	{
		array = NULL;
		write(1, "$ ", 3);
		chars = getline(&buffer, &size, stdin);
		if (chars == -1)
			break;
		buffer[chars - 1] = 0;
		array = split_str(buffer, ' ');
		exit_status = execute(array[0], array);
		printf("exit status:%d\n", exit_status);
		_free_array(array);
	}
	if (buffer)
		free(buffer);
	write(1, "\n", 1);
	return (0);
}
