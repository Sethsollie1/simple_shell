#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

/**
 * execute_cmd - this function executes user's command
 * @_get_argv: an array to the pointer of strings
 * Return: no return value
 */
int execute_cmd(char **_get_argv)
{
	char *initial_cmd, *final_cmd;
	pid_t child_process;
	int status = 0;

	initial_cmd = NULL;
	final_cmd = NULL;
	child_process = -1;
	initial_cmd = _get_argv[0];
	final_cmd = _get_path(initial_cmd);

	if (final_cmd == NULL)
		return (1);
	if (_get_argv && access(final_cmd, X_OK) != -1)
	{
		child_process = fork();

		if (child_process == -1)
		{
			print_error(_get_argv, "Error: command not found\n");
		}
		else if (child_process == 0)
		{

			if (execve(final_cmd, _get_argv, NULL) == -1)
				print_error(_get_argv, "Error: command not found\n");

		}
		else
		{
			if (waitpid(child_process, &status, 0) == -1)
				print_error(_get_argv, "Error: command not found\n");
		}
		if (_strcmp(final_cmd, initial_cmd) != 0)
			free(final_cmd);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		return (status);
	}
	free(final_cmd);
	return (1);
}
