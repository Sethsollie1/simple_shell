#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

/**
 * unsetenv_shell - this function remove an environment variable
 * @args: an array of arguments
 *
 * Return: 0 on success, -1 on failure
 */

int unsetenv_shell(char **args)
{
	if (args[1] == NULL)
	{
		write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
		return (-1);
	}

	if (getenv(args[1]) == NULL)
	{
		return (0);
	}
	unsetenv(args[1]);

	return (0);
}

/**
 * handle_env_cmds - this handle setenv, unsetenv, and echo commands
 * @args: an array of arguments
 *
 * Return: 1 if successful, 0 if not successful
 */

int handle_env_cmds(char **args)
{
	char *value;

	if (_strcmp(args[0], "setenv") == 0)
	{
		if (args[1] == NULL || args[2] == NULL)
			return (-1);
		if (setenv_shell(args) == -1)
			print_error(args, "Erroe: unable to set environment variable\n");
		return (1);
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		if (args[1] == NULL)
		{
			write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
			return (-1);
		}
		if (unsetenv(args[1]) == -1)
		{	write(STDERR_FILENO, "Unable to unset environment variable\n", 37);
			return (-1);
		}
		unsetenv_shell(args);
		return (1);
	}
	else if (_strcmp(args[0], "echo") == 0)
	{
		if (args[1] == NULL)
		{	write(STDERR_FILENO, "Usage: echo VARIABLE\n", 21);
			return (-1);
		}
		value = getenv(args[1]);
		if (value != NULL)
		{	write(STDOUT_FILENO, value, strlen(value));
			write(STDOUT_FILENO, "\n", 1);
		}
		else
			write(STDOUT_FILENO, "$\n", 2);
		return (1);
	}
	return (0);
}

/**
 * setenv_shell - sets a new environment variable or modify an existing one
 * @args: Array of arguments
 *
 * Return: 0 if success, -1 not successful
 */

int setenv_shell(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		write(STDERR_FILENO, "Usage: setenv VARIABLE\n", 29);
		return (-1);
	}

	if (setenv(args[1], args[2], 1) == -1)
	{
		print_error(args, "Failed to set environment variable\n");
		return (-1);
	}

	return (0);
}
