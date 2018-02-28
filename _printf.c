#include "holberton.h"
#include <stdio.h>

/**
 * _printf - takes a string and args of each '%'
 * and prints them
 * @format: initial string containing % +
 * char denoting type and number of args
 * @...: variable list of arguments
 *
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, j;
	int count = 0;
	va_list lst;
	interface ids[] = {
		{'c', _print_char},
		{'s', _print_string},
		{'i', _print_int},
		{'d', _print_int},
		{'%', _print_mod},
		{'\0', NULL}
	};

	va_start(lst, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; ids[j].id != '\0'; j++)
				if (format[i + 1] == ids[j].id)
					count += ids[j].fn(lst);

			i += 2;
		}

		write(1, &format[i], 1);
		count += 1;
	}

	va_end(lst);

	return (count);
}

/**
 * main - tests the _printf function
 *
 * Return: Always 0.
 */
int main(void)
{
	int code;

	printf("Numeric:\n");
	printf("============\n");
/* %i without param */
	code = printf("Std: %i.\n");
	printf("Std Returns: %d\n", code);
	code = _printf("Our: %i.\n");
	printf("Our Returns: %d\n", code);

	code = printf("Std: %i.\n", 0);
	printf("Std Returns: %d\n", code);
	code = _printf("Our: %i.\n", 0);
	printf("Our Returns: %d\n", code);

	code = printf("Std: %i.\n", 67);
	printf("Std Returns: %d\n", code);
	code = _printf("Our: %i.\n", 67);
	printf("Our Returns: %d\n", code);

	code = printf("Std: %i.\n", 127);
	printf("Std Returns: %d\n", code);
	code = _printf("Our: %i.\n", 127);
	printf("Our Returns: %d\n", code);

	code = printf("Std: %d.\n", 0 % 10);
	printf("Std Returns: %d\n", code);
	code = _printf("Our: %d.\n", 0 % 10);
	printf("Our Returns: %d\n", code);

	printf("\nCharacters:\n");
	printf("============\n");

	code = printf("Std: %%.\n");
	printf("Std Returns: %d\n", code);
	code = _printf("Our: %%.\n");
	printf("Our Returns: %d\n", code);

	code = printf("Std: Cu%cio.us\n", '7');
	printf("Std Returns: %d\n", code);
	code = _printf("Our: Cu%cio.us\n", '7');
	printf("Our Returns: %d\n", code);

	return (0);
}
