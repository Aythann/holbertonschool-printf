#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 *
 * Return: 1 on success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - prints a character
 * @c: character to print
 *
 * Return: number of characters printed
 */
int print_char(char c)
{
	return (_putchar(c));
}

/**
 * print_string - prints a string
 * @s: string to print
 *
 * Return: number of characters printed
 */
int print_string(char *s)
{
	int i = 0;

	if (s == NULL)
		s = "(null)";

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}

	return (i);
}

/**
 * print_percent - prints a percent sign
 *
 * Return: number of characters printed
 */
int print_percent(void)
{
	return (_putchar('%'));
}

/**
 * print_int - prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_int(long n)
{
	int result = 0;

	if (n < 0)
	{
		result += _putchar('-');
		n = -n;
	}

	if (n / 10)
		result += print_int(n / 10);

	result += _putchar((n % 10) + '0');

	return (result);
}
