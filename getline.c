#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _getline - Read a line of input from standard input
 *
 * Return: The line of input (without the newline character) or NULL on failure
 */
char *_getline(void)
{
	static char buf[BUFFER_SIZE];
	static size_t buf_length;
	static size_t point;

	char *line = NULL;
	size_t line_length = 0;
	size_t newline_index = 0;
	size_t chunk_length, i;

	while (1)
	{
		if (point >= buf_length)
		{
			buf_length = read(0, buf, BUFFER_SIZE);
			if (buf_length == 0)
				break;
			if (buf_length == (size_t)-1)
				return (NULL);
			point = 0;
		}

		newline_index = point;
		while (newline_index < buf_length && buf[newline_index] != '\n')
			newline_index++;
		chunk_length = newline_index - point;
		line = realloc(line, (line_length + chunk_length + 1) * sizeof(char));
		if (line == NULL)
			return (NULL);
		for (i = 0; i < chunk_length; i++)
			line[line_length + i] = buf[point + i];
		line_length += chunk_length;
		point = newline_index + 1;
		if (newline_index < buf_length && buf[newline_index] == '\n')
		{
			line[line_length] = '\0';
			return (line);
		}
	}

	return (line);
}
