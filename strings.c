#include "shell.h"
#include <string.h>

/**
 * _atoi - this function changes a string to an integer
 * @s: the string to changed
 *
 * Return: the converted int
 */

int _atoi(char *s)
{
	unsigned int n = 0;

	do {
		if (*s == '-')
		{
			return (-1);
		}
		else if ((*s < '0' || *s > '9') && *s != '\0')
		{
			return (-1);
		}
		else if (*s >= '0'  && *s <= '9')
		{
			n = (n * 10) + (*s - '0');
		}
		else if (n > 0)
		{
			break;
		}
	} while (*s++);

	return (n);
}

/**
 * _strchr - this function locates a char in a string
 * @s: the string to be searched
 * @c: the character to be checked
 *
 * Return: pointer to the first `c` in `s`
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] != c && s[i] != '\0'; i++)
		;

	if (s[i] == c)
	{
		return (s + i);
	}
	else
	{
		return (NULL);
	}
}

/**
 * _strcspn - this function computes strings segments
 * @s: the string to be searched
 * @charset: the string to be used
 *
 * Return: index at which a char in `s` exists in `charset`
 */

int _strcspn(char *s, char *charset)
{
	int count = 0, i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (_strchr(charset, s[i]) != NULL)
		{
			break;
		}
		count++;
	}

	return (count);
}


/**
 * _strcmp - this function compares two strings
 * @s: the first string to compare
 * @c: the second string to compare
 *
 * Return: return 1 when strings match
 */

int _strcmp(char *s, char *c)
{
	int i;

	for (i = 0; s[i] != '\0' && c[i] != '\0'; i++)
	{
		if (s[i] != c[i])
		{
			return (s[i] - c[i]);
		}
	}

	return (s[i] - c[i]);
}
