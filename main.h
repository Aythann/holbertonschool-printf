#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define TYPE_CHAR 1
#define TYPE_STRING 2
#define TYPE_PERCENT 3
#define TYPE_INT 4

int _putchar(char c);
int _printf(const char *format, ...);
int parse_format(char c);
int print_char(char c);
int print_string(char *s);
int print_percent(void);
int print_int(long n);


#endif
