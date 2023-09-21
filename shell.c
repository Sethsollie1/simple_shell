#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

/**
 * main - entry point of shell
 * @argc: argument count
 * @argv: array of pointer to strings
 * Return: 0 or 1
 */

int main(int argc, char **argv)
{
	char *user_input, **_get_argv;
	ssize_t byte_read;
	int i, exec_status = 0;
	data_shell shell_data;

	shell_data._environ = environ;
	(void)argc;
	(void)argv;

	while (1 == 1)
	{
		user_input = NULL, byte_read = 0;
		user_input = read_prompt(&byte_read);
		_get_argv = tokenize(user_input, _get_argv, byte_read);
		if (_get_argv[0] == NULL)
			continue;
		if (_strcmp(_get_argv[0], "env") == 0)
		{	free(user_input);
			_env(&shell_data);
			free_array(_get_argv);
			continue;	}
		if (_strcmp(_get_argv[0], "exit") == 0)
		{	free(user_input);
			_exit_shell(_get_argv, exec_status);
			free_array(_get_argv);
			continue;
		}
		i = handle_env_cmds(_get_argv);
		if (i != 0)
		{	free(user_input);
			free_array(_get_argv);
			continue;
		}
		exec_status = execute_cmd(_get_argv);
		if (exec_status == 1)
			print_error(_get_argv, "Error: not found\n");
		free(user_input);
		free_array(_get_argv);
	}
	return (0);
}
