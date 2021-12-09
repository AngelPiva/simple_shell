# Simple Shell


## Description

This programm was created as the end of trimester project. It is a command language interpreter that executes commands it reads from the standar input. For this project we had to recreate how the Unix Shell works, and be able to make our own Shell based on it. The simple_shell uses system calls and functions to execute programs.

## Components

	| Files               | Functions          | System / Library Calls | Libraries  |
	|---------------------|--------------------|------------------------|------------|
	| _cd.c               | _cd                | chdir                  | main.h     |
	|	              |		           | perror                 |            |
	|---------------------|--------------------|------------------------|------------|
	| _env_functions.c    | _getenv            |                        | mani.h     |
	|		      | _printenv          | write                  |            |
	|---------------------|--------------------|------------------------|------------|
	| _search_functions.c | search             | perror                 | main.h     |
	|                     | search_executable  | access                 |            |
	|                     | search_path        | access                 |            |
	|                     |                    | free                   |            |
	|                     | search_built_in    |                        |            |
	|---------------------|--------------------|------------------------|------------|
	| _str_functions.c    | cmnd_concat        | malloc                 | main.h     |
	|                     | _free_array        | free                   |            |
	|                     | _strdup            | malloc                 |            |
	|                     | _strlen            |                        |            |
	|                     | _strncmp           |                        |            |
	|---------------------|--------------------|------------------------|------------|
	| execute.c           | execute            | fork                   | main.h     |
	|                     |                    | execve                 |            |
	|                     |                    | exit                   |            |
	|                     |                    | wait                   |            |
	| hsh                 |                    |                        |            |
	|---------------------|--------------------|------------------------|------------|
	| main.c              | main               | signal                 | main.h     |
	|                     |                    | write                  |            |
	|                     |                    | malloc                 |            |
	|                     |                    | isatty                 |            |
	|                     |                    | getline                |            |
	|                     |                    | read                   |            |
	|                     |                    | free                   |            |
	|                     | separate           | free                   |            |
	|                     | INTERRUPT_MANAGER  | signal                 |            |
	|                     |                    | write                  |            |
	|---------------------|--------------------|------------------------|------------|
	| main.h              |                    |                        | stdio.h    |
	|                     |                    |                        | stdlib.h   |
	|                     |                    |                        | string.h   |
	|                     |                    |                        | unistd.h   |
	|                     |                    |                        | sys/wait.h |
	|                     |                    |                        | signal.h   |
	|---------------------|--------------------|------------------------|------------|
	| split_str.c         | split_str          | malloc                 | main.h     |
	|                     |                    | free                   |            |
	|                     |                    | strtok                 |            |
	|---------------------|--------------------|------------------------|------------|
	| AUTHORS             |                    |                        |            |
	|---------------------|--------------------|------------------------|------------|
	| README.md           |                    |                        |            |
	|---------------------|--------------------|------------------------|------------|
	| man_1_simple_shell  |                    |                        |            |

## Features
	* PATH
	* Built-ins
		* cd
		* env
		* exit
	* Command line arguments

## Example

```
root@d8524d64916d:~/simple_shell# ./hsh
$ pwd
/root/simple_shell
$ ls
AUTHORS  _cd.c  _env_functions.c  execute.c  hsh  main.c  main.h  man_1_simple_shell  README.md  _search_functions.c  split_str.c  _str_functions.c  text
$ mkdir new_dir
$ ls
AUTHORS  _cd.c  _env_functions.c  execute.c  hsh  main.c  main.h  man_1_simple_shell  new_dir  README.md  _search_functions.c  split_str.c  _str_functions.c  text
$ cd new_dir
$ ls
$ vi new.file
$ cat new.file
Hello!
$ rm new.file
$ ls
$ cd ..
$ ls
AUTHORS  _cd.c  _env_functions.c  execute.c  hsh  main.c  main.h  man_1_simple_shell  new_dir  README.md  _search_functions.c  split_str.c  _str_functions.c  text
$ rmdir new_dir
$ ls
AUTHORS  _cd.c  _env_functions.c  execute.c  hsh  main.c  main.h  man_1_simple_shell  README.md  _search_functions.c  split_str.c  _str_functions.c  text
$ exit

root@d8524d64916d:~/simple_shell#
```

## Functions Description
	* _printenv: prints all the environment variables
	* _getenv: gets an environment variable
	* _cd: change directory
	* search: searches for the command
	* search_executable: searches for executable
	* search_path: searches for path
	* search_built_in: searches for a built-in
	* cmnd_concat: concatenates 2 strs for path
	* _free_array: frees an array of strings
	* _strdup: duplicates a string
	* _strlen: returns the length of a string
	* _strncmp: compares two strings
	* execute: executes a programm
	* INTERRUPT_MANAGER: interrupts programm
	* separate: parses a string
	* main: main function of the programm
	* split_str: splits string

## Other Files

* main.h: header
* AUTHORS: contributors
* man_1_simple_shell: manual

## Staff
	Manuela Ríos Sosa - 3954@holbertonschool.com
	Ángel Piva - 3965@holbertonschool.com
