#include "main.h"


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
	if (status != 1)
		return (status);
	status = search_path(args);
	if (status != 1)
		return (status);
	status = search_executable(args);
	if (status != 1)
		return (status);
	perror(shell_name);
	return (status);
}

/**
 * search_executable - searches for executable
 * @args: argv
 * Return: status
 */

int search_executable(char **args)
{
	int exists, exit_status;

	exists = access(args[0], F_OK);
	if (exists == -1)
		return (1);
	exit_status = execute(args[0], args);
	return (exit_status);
}

/**
 * cmnd_concat - concatenates 2 strs for path
 * @path: path of file
 * @cmnd: command to search
 * Return: "<path>/<cmnd>"
 */
char *cmnd_concat(char *path, char *cmnd)
{
	char *out;
	int c, s;

	if (!path || !cmnd)
		return (NULL);
	out = malloc(strlen(path) + strlen(cmnd) + 2);
	if (!out)
		return (NULL);
	for (c = 0; path[c]; c++)
		out[c] = path[c];
	out[c] = '/';
	for (s = 0; cmnd[s]; s++)
		out[c + (s + 1)] = cmnd[s];
	out[c + (s + 1)] = 0;
	return (out);
}

/**
 * search_path - searches for path
 * @args: argv
 * Return: status
 */

int search_path(char **args)
{
	char *path, *cmnd;
	char **paths;
	int i, exists, exit_status;

	path = _getenv("PATH");
	paths = split_str(path, ':');
	for (i = 0; paths[i]; i++)
	{
		cmnd = cmnd_concat(paths[i], args[0]);
		if (!cmnd)
			break;
		exists = access(cmnd, F_OK);
		if (exists == -1)
		{
			free(cmnd);
			continue;
		}
		exit_status = execute(cmnd, args);
		free(cmnd);
		_free_array(paths);
		return (exit_status);
	}
	_free_array(paths);
	return (1);
}

/**
 * search_built_in - searches for a built-in
 * @args: argv
 * @shell_name: name of my shell
 * Return: staus
 */
int search_built_in(char **args, char *shell_name)
{
	int c, s, found;

	char *builtins[] = {
		"exit",
		"cd",
		"env",
		NULL};
	for (c = 0; builtins[c]; c++)
	{
		found = 0;
		for (s = 0; args[0][s]; s++)
			if (args[0][s] != builtins[c][s] || !builtins[c][s])
			{
				found = 1;
				break;
			}
		if (!found)
			break;
	}
	switch (c)
	{
		case 0:
			return (-1);
		case 1:
			return (_cd(args, shell_name));
		case 2:
			_printenv();
			return (0);
	}
	return (1);
}
