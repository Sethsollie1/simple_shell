#include "shell.h"
#include <unistd.h>

/**
 * execute_command - Execute a command using execve.
 * Description - This function creates a child process using fork and
 * execute the command using execve. It also handles error.
 *
 * @args: an array of strings that represent the commands and arguments.
 * @command: The command to execute.
 * @environ: The array of environment variable.
 * Return: void
 */

void execute_command(char *command, char **args, char **environ)
{
	pid_t pid;

	(void)args;

	pid = fork();

	if (pid == -1)

	{
		perror("Error (fork)\n");
		exit(EXIT_SUCCESS);
	}
	else if (pid == 0)
	{
		/* Child process */
		char *args[2];

		args[0] = command;
		args[1] = NULL;

		execve(command, args, environ);


		/* If execve returns, an error occured */
		perror("Error (execve)\n");
		exit(EXIT_SUCCESS);
	}
	else
	{

		/* Parent process */
		int status;

		if (waitpid(pid, &status, 0) == -1)

		{
			perror("Error - (waitpid)\n");
			exit(EXIT_SUCCESS);
		}
	}
}
