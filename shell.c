#include "shell.h"

/**
 * main - main function of shell.
 * Return:  Always return 0.
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	bool is_terminal = isatty(STDIN_FILENO);
	ssize_t num_read;

	char *args[MAX_COMMAND_LENGTH / 2 + 1];

	while (true)
	{
		if (is_terminal)
		{
			/* Display the prompt "$ " */
			write(STDOUT_FILENO, "$ ", 2);
		}

		num_read = read(STDIN_FILENO, command, sizeof(command));

		if (num_read == -1)
		{
			perror("Error (read\n)");
			exit(EXIT_SUCCESS);
		}
		else if (num_read == 0)
		{
			/* End of file (Ctrl+D) */
			break;
		}
		/* Remove trailing newline character */
		if (command[num_read - 1] == '\n')
			command[num_read - 1] = '\0';

		tokenize_command(command, args);

		execute_command(args[0], args, environ);

	}
	return (0);
}

