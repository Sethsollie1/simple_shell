#include "main.h"
/**
 *
 */
void free_p(const unsigned int n, ...)
{
	va_list arglist;
	unsigned int i;
	char *arg;

	va_start(arglist, n);
	for (i = 0; i < n; i++)
	{
		arg = va_arg(arglist, char *);
		free(arg);
	}
}


void free_a(char **arr)
{
	free(arr);
}
