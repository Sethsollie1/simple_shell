#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

/**
 * _get_path - this function gets the path of each command
 * @initial_cmd: the user input
 *
 * Return: return the command path
 */

char *_get_path(char *initial_cmd)
{
	struct stat path_test;
	char *cmd_path, *cmd_path_copy = NULL, *delimiter;
	char *path_to_file, *parse_token;
	int dir_len, user_command_length, path_to_file_len, i;

	delimiter = ":";
	cmd_path = _getenv("PATH");

	if (stat(initial_cmd, &path_test) == 0)
		return (initial_cmd);

	if (cmd_path)
	{	cmd_path_copy = _strdup(cmd_path_copy, cmd_path);
		user_command_length = str_len(initial_cmd);
		parse_token = _strtok(cmd_path_copy, delimiter);

		while (parse_token != NULL)
		{
			dir_len = str_len(parse_token);
			path_to_file_len = user_command_length + dir_len + 2;
			path_to_file = malloc(path_to_file_len);
			path_to_file[0] = '\0';
			for (i = 0; i < path_to_file_len; i++)
				path_to_file[i] = '\0';
			str_copy(path_to_file, parse_token);
			str_cat(path_to_file, "/");
			str_cat(path_to_file, initial_cmd);
			str_cat(path_to_file, "\0");
			if (stat(path_to_file, &path_test) == 0)
			{	free(cmd_path_copy);
				free(parse_token);
				return (path_to_file);
			}
			free(path_to_file);
			free(parse_token);
			parse_token = _strtok(NULL, delimiter);
		}
	}
	free(cmd_path_copy);
	return (NULL);
}
