#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _print_int - Prints a signed integer (d or i)
 * @ap: List of arguments containing the integer to print
 *
 * Return: Number of characters printed
 */

int _print_int(va_list ap)
{
	long n = va_arg(ap, int);
	long num = n;
	int count = 0;
	char digit;

	/* Handle negative numbers */
	if (num < 0)
	{
	count += write(1, "-", 1);
	num = -num;
	}

	/* Recursive printing of digits */
 	if (num / 10)
	{
	long temp = num / 10;
	va_list fake;
	va_start(fake, temp);
	*((long *)&fake) = temp;
	count += _print_int(fake);
 	va_end(fake);
 	}

	/* Print last digit */
	digit = (num % 10) + '0';
	count += write(1, &digit, 1);

	return (count);
}

/**
 * _print_char - Prints a single character (c)
 * @ap: List of arguments containing the character
 *
 * Return: Number of characters printed (1)
 */

int _print_char(va_list ap)
{
	char c = (char)va_arg(ap, int);

	return (write(1, &c, 1));
}

/**
 * _print_string - Prints a string (s)
 * @ap: List of arguments containing the string
 *
 * Return: Number of characters printed
 */

int _print_string(va_list ap)
{
	char *str = va_arg(ap, char *);
	int count = 0;

	if (str == NULL)
	str = "(null)";

	while (*str)
	count += write(1, str++, 1);

	return (count);
}

/**
 * _print_percent - Prints a percent sign (%)
 * @ap: Unused parameter
 *
 * Return: Always 1
 */

int _print_percent(__attribute__((unused)) va_list ap)
{
	return (write(1, "%", 1));
}

