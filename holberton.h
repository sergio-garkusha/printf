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

#endif /* holberton */
