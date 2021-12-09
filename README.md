# Simple Shell


## Description

This programm was created as the end of trimester project. It is a command language interpreter that executes commands it reads from the standar input. For this project we had to recreate how the Unix Shell works, and be able to make our own Shell based on it. The simple_shell uses system calls and functions to execute programs.

## Components

	| Files               | Original Functions | System / Library Calls | Libraries  |
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
	|---------------------|--------------------|------------------------|------------|
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

## Staff
	Manuela Ríos Sosa - 3954@holbertonschool.com
	Ángel Piva - 3965@holbertonschool.com
