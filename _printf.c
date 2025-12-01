#include <stdarg.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: a character string
 *
 * Return: number of characters printed or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0;
	int result = 0;

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				va_end(ap);
				return (-1);
			}

			if (format[i + 1] == 'c')
				result += print_char(va_arg(ap, int));

			else if (format[i + 1] == 's')
				result += print_string(va_arg(ap, char *));

			else if (format[i + 1] == '%')
				result += print_percent();

			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
				result += print_int(va_arg(ap, int));
			else
			{
				result += _putchar('%');
				result += _putchar(format[i + 1]);
			}
			i += 2;
		}

		else
		{
			result += _putchar(format[i]);
			i++;
		}
	}
	va_end(ap);
	return (result);
}
