#include "shell.h"

/**
 * display_prompt - Display the shell prompt.
 */

void display_prompt(void)
{
	write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
}

/**
 * read_execute_commands - Read and execute commands.
 */

void read_execute_commands(void)
{
	char command[MAX_COMMAND_LENGTH];
	ssize_t num_read;
	char *cmd;

	while (true)
	{
		display_prompt();

		num_read = read(STDIN_FILENO, command, sizeof(command));

		if (num_read == -1)
		{
			perror("Error (read)");
			exit(EXIT_SUCCESS);
		}
		else if (num_read == 0)
		{
			break;
		}
		command[strcspn(command, "\n")] = '\0';

		if (strlen(command) == 0 || strspn(command, " \t") == strlen(command))
		{
			continue;
		}

		cmd = strtok(command, " \t");

		execute_command(cmd, environ);
	}
}

/**
 * main - main function of shell.
 * @argc: The number of command line arguments.
 * @argv: The array of command line arguments.
 * Return:  Always return 0.
 */

int main(int argc, char *argv[])
{
	int file;
	ssize_t num_read;
	char *cmd;
	char line[MAX_COMMAND_LENGTH];

	if (argc > 1)
	{
		file = open(argv[1], O_RDONLY);
		if (file == -1)
		{
			perror("Error (open)");
			exit(EXIT_SUCCESS);
		}

		while ((num_read = read(file, line, sizeof(line))) > 0)
		{
			line[strcspn(line, "\n")] = '\0';

			if (strlen(line) == 0 || strspn(line, " \t") == strlen(line))
			{
				continue;
			}

			cmd = strtok(line, " \t");

			execute_command(cmd, environ);
		}
		close(file);
	}
	else
	{
		read_execute_commands();
	}
	return (0);
}
