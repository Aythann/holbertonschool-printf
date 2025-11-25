#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int parse_format(char c);

int print_char(char c);
int print_string(char *s);
int print_percent(void);
int print_int(int n);

#endif
