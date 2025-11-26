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
		return (TYPE_CHAR);
	else if (c == 's')
		return (TYPE_STRING);
	else if (c == '%')
		return (TYPE_PERCENT);
	else if (c == 'd' || c == 'i')
		return (TYPE_INT);

	return (-1);
}
