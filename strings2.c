#include "shell.h"


/**
 * free_array - Frees a dynamically allocated array of strings.
 * @argv: The array of strings to be freed.
 *
 */
void free_array(char **argv)
{
	char **temp = argv;

	for (; *temp != NULL; temp++)
	{
		free(*temp);
		*temp = NULL;
	}
	free(argv);
}

/**
 * str_len - this function counts the length of a string
 * @string: string whose length is to be counted
 *
 * Return: the length of the string
 */

int str_len(char *string)
{
	int i;
	int num;

	num = 0;

	for (i = 0; string[i] != '\0'; i++)
		num++;

	return (num);
}


/**
 * str_copy - this function copies strings
 * @to: string destination
 * @from: string origin
 *
 * Return: void
 */

void str_copy(char *to, char *from)
{
	int i;

	for (i = 0; from[i] != '\0'; i++)
		to[i] = from[i];

	to[i] = '\0';
}


/**
 * str_cat - this function cat two strings
 * @text_add: where is it adding to
 * @text: where it is adding from
 *
 * Return: void
 */
void str_cat(char *text_add, char *text)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (text_add[i] != '\0')
		i++;
	for (num = 0; text[num] != '\0'; num++)
		text_add[i++] = text[num];
	text_add[i] = '\0';
}
