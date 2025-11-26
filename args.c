#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_c - print char
 * @ap: argument list
 */
void print_c(va_list ap)
{
	char c = (char)va_arg(ap, int);
	return (_putchar(c));
}

/**
 * print_i - print int
 * @ap: argument list
 */
void print_i(va_list ap)
{
	int i = (int)va_arg(ap, int);
	return (_putchar(i));
}

/**
 * print_d - print int
 * @ap: argument list
 */
void print_d(va_list ap)
{
	int d = (int)va_arg(ap, int);
	return (_putchar(d));
}

/**
 * print_percent - print int
 * @ap: argument list
 */
void print_percent(va_list ap)
{
	char percent = (char)va_arg(ap, int);
	return (_putchar(percent));
}

/**
 * print_s - print string
 * @ap: argument list
 */
void print_s(va_list ap)
{
	char *s = va_arg(ap, char *);

	if (!s)
		s = "(nil)";

	return(*s);
}