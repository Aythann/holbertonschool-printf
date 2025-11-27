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
	int type;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(ap);
				return (-1);
			}
			type = parse_format(format[i]);
			if (type == TYPE_CHAR)
				result += print_char(va_arg(ap, int));
			else if (type == TYPE_STRING)
				result += print_string(va_arg(ap, char *));
			else if (type == TYPE_PERCENT)
				result += print_percent();
			else if (type == TYPE_INT)
				result += print_int(va_arg(ap, int));
			else
			{
				result += _putchar('%');
				result += _putchar(format[i]);
			}
		}
		else
			result += _putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (result);
}
