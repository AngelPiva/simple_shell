#include "main.h"
#include "string.h"

/**
 *main - main
 *Return: succesfully 0
 */

int main(void)
{
	char *buffer;
	char **array;
	size_t size;
	ssize_t chars = 0;
	int inte = 1;
	int run = 0;


	while (inte)
	{
		write(1, "$ ", 3);
		chars = getline(&buffer, &size, stdin);
		if (chars == -1)
			break;
		array = save_tok(buffer, ' ');
		run = 0;
		while (array[run])
		{
			printf("<%s>\n", array[run]);
			run++;
		}
	}
	return (0);
}
