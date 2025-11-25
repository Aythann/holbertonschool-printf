#include "main.h"

/**
 * parse_format - checks which format specifier is used
 * @c: the character after '%'
 *
 * Return: a code corresponding to the format type
 */
int parse_format(char c)
{
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (2);
	else if (c == '%')
		return (3);
	else if (c == 'd' || c == 'i')
		return (4);

	return (-1);
}
