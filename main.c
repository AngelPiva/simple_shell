#include "main.h"
#include "string.h"

/**
 *main - main
 *Return: succesfully 0
 */

int main(void)
{
	char *buffer = NULL;
	char **array = NULL;
	size_t size = 0;
	ssize_t chars = 0;
	int inte = 1;


	while (inte)
	{
		write(1, "$ ", 3);
		chars = getline(&buffer, &size, stdin);
		if (chars == -1)
			break;
		buffer[chars - 1] = 0;
		array = split_str(buffer, ' ');
		free_array(array);
	}
	if (buffer)
		free(buffer);
	return (0);
}
