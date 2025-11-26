#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

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
	printf("%d", va_arg(ap, int));
}

/**
 * print_f - print float
 * @ap: argument list
 */
void print_f(va_list ap)
{
	printf("%f", va_arg(ap, double));
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

	printf("%s", s);
}

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	int i = 0, j;
	char *types = "cifs";
	char *sep = "";

	void (*funcs[])(va_list) = {print_c, print_i, print_f, print_s};

	va_start(ap, format);

	while (format && format[i])
	{
		j = 0;

		while (types[j] && types[j] != format[i])
			j++;

		if (types[j])
		{
			printf("%s", sep);
			funcs[j](ap);
			sep = ", ";
		}

		i++;
	}

	va_end(ap);
	printf("\n");
}
