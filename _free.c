#include "main.h"

/**
 * free_array - frees an array of strings
 * @arr: array
 */
void free_array(char **arr)
{
	int a = 0;

	if (!arr)
		return;
	for (a = 0; arr[a]; a++)
	{
		free(arr[a]);
	}
	free(arr);
}
