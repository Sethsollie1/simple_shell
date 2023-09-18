#include "shell.h"


int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);

}


void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		putchar(str[i]);
	putchar('\n');
}

int _putchar(char c)
{
	return (write(1, &c, 1));
}


char *_strcpy_src(char *dest, char *src, int n)
{
	int ct;

	for (ct = 0 ; src[ct] != '\0' ; ct++, n++)
		dest[ct] = src[n];
	dest[ct] = '\0';
	return (dest);
}
