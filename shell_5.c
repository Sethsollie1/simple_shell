#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

extern char **environ;

/**
 * print_env - Print the current environment.
 */
void print_env(void)
{
	int j = 0;
	char *env_var;

	while (environ[j] != NULL)
	{
		env_var = environ[j];
		printf("%s\n", env_var);
		j++;
	}
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	print_env();
	return (0);
}
