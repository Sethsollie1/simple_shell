#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _exit_shell - this function exits the shell
 * @_get_argv: the command entered
 * @exec_status: this is the status of the exit function
 *
 * Return: returns nothing when the shell is exited
 */

void _exit_shell(char **_get_argv, int exec_status)
{
	char **commands = NULL;
	/*int status = 0;*/
	int i = 0, arg;
	const char *error_msg = "Error: too many arguments\n";

	while (_get_argv[i] != NULL)
		i++;
	{

		if (i == 1)
		{
			free_array(_get_argv);
			free(commands);
			exit(exec_status);
		}
		else if (i == 2)
		{
			arg = _atoi(_get_argv[1]);
			if (arg < 0)
			{
				print_error(_get_argv, "Error: wrong input: ");
				_errputs(_get_argv[1]);
				_errputs("\n");
				/*status = 2;*/
			}
			else
			{
				free_array(_get_argv);
				free(commands);
				exit(arg);
			}
		}
		else
		write(STDERR_FILENO, error_msg, strlen(error_msg));
	}
}
