#include "shell.h"

/**
 * tokenize_command - tokenizes the command into arguments.
 * Description: This function tokenizes the command into individual
 *	arguments seperated by whitespace characters (tab, space, newline)
 *	it then uses strtok to split the command into tokens, then
 *	stores themin the args array.
 *
 * @command: Command string that should be tokenized.
 * @args: The array where command arguments will be stored.
 * Return: The number of arguments.
 */

int tokenize_command(char *command, char **args)
{
	int arg_count = 0;
	char *token;
	char *command_cpy = strdup(command); /* copy of command */
	int i;

	if (command_cpy == NULL)
	{
		perror("Error (strdup\n");
		exit(EXIT_SUCCESS);
	}

	token = strtok(command_cpy, " \t\n");

	while (token != NULL)
	{
		/* Allocate memory for each argument */
		args[arg_count++] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	args[arg_count] = NULL;

	free(command_cpy); /* Free copied cmd string */

	for (i = 0; i < arg_count; i++)
	{
		free(args[i]);
	}
	return (arg_count);
}
