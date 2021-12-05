#include "main.h"
#include "string.h"

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

	while (inte)
	{
		array = NULL;
		write(1, "$ ", 3);
		chars = getline(&buffer, &size, stdin);
		built_ins(buffer);
		if (chars == -1)
			break;
		buffer[chars - 1] = 0;
		array = split_str(buffer, ' ');
		_free_array(array);
	}
	if (buffer)
		free(buffer);
	return (0);
}
