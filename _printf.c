#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
* _printf - Function that prints anything formated
* @format: list of types of arguments passed to the function
*
* Return: the result
*/

int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0;

	if(format == NULL)
	return (-1);

	va_start(ap, format);

	while (format[i] != '\0')
	{
		if(format[i] == '%')
		{
			i++;
			if(format[i] == '%')
			{
				print_percent(ap);
				continue;
			}

			if(format[i] == 'c')
			{
				print_c(ap);
				continue;
			}

			if(format[i] == 's')
			{
				print_s(ap);
				continue;
			}
		}
		else
		{
			write(format[i]);
			i++;
		}
	}

	va_end(ap);
	return (count);
}
