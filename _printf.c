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
	int i = 0, count = 0, type;

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
			{
				va_end(ap);
				return (-1);
			}

			type = parse_format(format[i]);

			if (type == 1)
				count += print_char(va_arg(ap, int));
			else if (type == 2)
				count += print_string(va_arg(ap, char *));
			else if (type == 3)
				count += print_percent();
			else if (type == 4)
				count += print_int(va_arg(ap, int));
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
			count += _putchar(format[i]);

		i++;
	}

	va_end(ap);
	return (count);
}
