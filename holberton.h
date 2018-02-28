#ifndef _holberton_h_
#define _holberton_h_

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * struct intface - interface for printing
 * @id: the character, which identifies the type of
 * the argument
 * @fn: function to run if id matches
 */
typedef struct intface
{
	char id;
	int (*fn)(va_list);
} interface;

int _printf(const char *format, ...);
int _print_char(va_list ls);
int _print_mod(va_list ls);
int _print_string(va_list ls);
int _print_int(va_list ls);

#endif /* holberton */
