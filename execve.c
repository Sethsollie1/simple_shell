#include "shell.h"
#include <unistd.h>

/**
 * execute_command - Execute a command using execve.
 * Description - This function creates a child process using fork and
 * execute the command using execve. It also handles error.
 *
 * @command: The command to execute.
 * @environ: The array of environment variable.
 * Return: void
 */

void execute_command(char *command, char **environ)
{
	pid_t pid = fork();

	if (pid == -1)

	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */
		char *args[2];

		args[0] = command;
		args[1] = NULL;

		execve(command, args, environ);


		/* If execve returns, an error occured */
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		int status;

		if (waitpid(pid, &status, 0) == -1)

		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
}
