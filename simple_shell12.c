#include "main.h"

/**
 * 
 */

int checkBuiltins(char **av, char *buff, int count)
{

	if (av && *av && buff)
	{
		if (_strcmp("env", av[0]) == 0 && _strlen(av[0]) == 3)
		{
			printenv();
			return (0);
		}
		else if (_strcmp("exit", av[0]) == 0 && _strlen(av[0]) == 4)
			return (2);
		else if (_strcmp("cd", av[0]) == 0 && _strlen(av[0]) == 2)
		{
			_cd(av, count);
			return (0);
		}
		else if (_strcmp("help", av[0]) == 0 && _strlen(av[0]) == 4)
		{
			_help(av);
			return (0);
		}
		else if (_strcmp("echo", av[0]) == 0 && _strlen(av[0]) == 4)
		{
			_echo(av);
			return (0);
		}
	}
	return (1);
}


void printenv(void)
{
	int i = 0;

	while (environ[i])
	{
		_printf("%s\n", environ[i]);
		i++;
	}
}
