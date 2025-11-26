#include "main.h"

/**
 * _print_number - prints a number recursively
 * @n: number to print
 *
 * Return: number of chars printed
 */
int _print_number(long n)
{
	int count = 0;
	char digit;

	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}

	if (n / 10)
		count += _print_number(n / 10);

	digit = (n % 10) + '0';
	count += write(1, &digit, 1);

	return (count);
}

/**
 * _print_int - prints an integer (%d, %i)
 * @ap: argument list
 *
 * Return: number of chars printed
 */
int _print_int(va_list ap)
{
	long n = va_arg(ap, int);

	return (_print_number(n));
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
