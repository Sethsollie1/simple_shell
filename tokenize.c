#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

/**
 * tokenize - this function split user's command strings
 * @get_user_input: pointer to user input
 * @argv: array of pointer to strings
 * @byte_read: gets the size of user input in bytes
 *
 * Return: array of pointer to strings
 */

char **tokenize(char *get_user_input, char **argv, ssize_t byte_read)
{
	char *user_input_copy, *parse_token;
	const char *delimiter;
	int token_count = 0, num = 0;
	int token_length;

	delimiter = " \n";

	user_input_copy = malloc(sizeof(char) * (byte_read + 2));
	if (user_input_copy == NULL)
	{
		perror("Error: unable to allocate memory");
		return (NULL);
	}
	str_copy(user_input_copy, get_user_input);
	parse_token = _strtok(get_user_input, delimiter);

	while (parse_token != NULL)
	{
		token_count++;
		free(parse_token);
		parse_token = _strtok(NULL, delimiter);
	}
	token_count++;

	argv = malloc(sizeof(char *) * token_count);
	parse_token = _strtok(user_input_copy, delimiter);
	for (num = 0; parse_token != NULL; num++)
	{
		token_length = str_len(parse_token);
		argv[num] = malloc(sizeof(char) * token_length + 1);
		argv[num][token_length] = '\0';
		str_copy(argv[num], parse_token);
		free(parse_token);
		parse_token = _strtok(NULL, delimiter);
	}
	/*free(parse_token);*/
	argv[num] = NULL;
	free(user_input_copy);
	return (argv);

}
