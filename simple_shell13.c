#include "main.h"

/**
 * 
 */
 
int prompt(char **buff)
{
	ssize_t numbers_characters = 0;
	size_t n = 0;

	if (isatty(STDIN_FILENO) == 1)
		_printf("($) ");
	numbers_characters = getline(buff, &n, stdin);

	return (numbers_characters);
}
