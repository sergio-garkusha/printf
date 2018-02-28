#ifndef holberton
#define holberton

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct
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
