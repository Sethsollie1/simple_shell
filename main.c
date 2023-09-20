#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * read_input - this function reads user input
 * @interactive_mode: this indicates what mode the program is run
 *
 * Return: A pointer to the string read.
 */
char *read_input(int interactive_mode)
{
	char *input_str = NULL, *prompt = "Setjoy$ ";
	size_t input_size = 0;
	ssize_t input_len;

	if (interactive_mode)
		write(STDIN_FILENO, prompt, 8);
	input_len = getline(&input_str, &input_size, stdin);

	if (input_len == -1)
	{
		/* Handle end-of-file (Ctrl+D) or error */
		printf("\n");
		free(input_str);
		return (NULL);
	}

	/* Remove newline character from input */
	while (input_len > 0 && (input_str[input_len - 1] == '\n' ||
				input_str[input_len - 1] == ' ' ||
				input_str[input_len - 1] == '\t'))
	{
		input_str[--input_len] = '\0';
	}
	return (input_str);
}

/**
 * _tokenize_input - this function tokenize user input
 * @input: pointer to the string read
 * @tokens: an array of pointers to the tokenized string
 *
 * Return: Number of arguments parsed.
 */
int _tokenize_input(char *input, char *tokens[])
{
	char *token;
	int argc = 0;

	token = strtok(input, " \t");
	while (token != NULL)
	{
		tokens[argc++] = token;
		token = strtok(NULL, " \t");
	}

	return (argc);
}

/**
 * _execute_cmd - this function executes a command
 * @cmd: the command to execute
 * @args: an array of strings to be passed to the command
 * @envp: environment variables that will be available to the executed command
 * @app: pointer to the initial app
 */
void _execute_cmd(char *cmd, char *args[], char *envp[], char *app)
{
	struct stat file_stat;
	pid_t pid;
	int argc = 0;

	while (args[argc] != NULL)
		argc++;
	pid = fork();
	if (pid == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */
		if (argc > 1)
		{
			_print_error(app, ": No such file or directory\n");
			exit(EXIT_FAILURE);
		}
		if (stat(cmd, &file_stat) == -1)
		{
			perror(app);
			exit(EXIT_FAILURE);
		}

		if (execve(cmd, args, envp) < -1)
		{
			/* Command execution failed */
			perror(app);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		int status;

		waitpid(pid, &status, 0);
	}
}

/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 *
 * Return: Always 0.
 */
int main(int ac __attribute__((unused)), char *av[])
{
	char *input;
	char *tokens[MAX_INPUT_LENGTH];
	int argc;
	char *envp[] = {
		"HOME=/home/user",
		"PATH=/usr/local/bin:/usr/bin:/bin",
		NULL
	};
	int interactive_mode = 1;

	while (1 && interactive_mode)
	{
		interactive_mode = isatty(STDIN_FILENO);
		input = read_input(interactive_mode);
		if (input == NULL)
		{
			/* End of file or error */
			break;
		}

		if (_strlen(input) == 0)
		{
			free(input);
			continue;
		}

		argc = _tokenize_input(input, tokens);

		if (argc > 0)
		{
			/* Execute the command if no arguments are provided */
			_execute_cmd(tokens[0], tokens, envp, av[0]);
		}
		free(input);
	}
	return (0);
}
