#include ""
/**
 *print_char - prints a character.
 *@ap: List of arguments containing the character to print
 *return: 1 (number of characters printed).
 */
int print_char(va_list ap)
{
	char c = (char)va_arg(ap, int);
	return (_putchar(c));
}
