#include "main.h"

/**
  *
  */

int checkSpecifier(const char *format, int i, va_list arglist)
{
	int count = 0;

	if (get_specifier_func(format[i + 1]))
	{
		count += get_specifier_func(format[i + 1])(arglist);
		i++;
	}
	else if (format[i + 1] == '%')
	{
		write(1, &format[i + 1], 1);
		count++, i++;
	}
	else
	{
		write(1, &format[i], 1);
		write(1, &format[i + 1], 1);
		count += 2, i++;
	}

	return (count);
}
