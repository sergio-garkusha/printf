#include "holberton.h"

/**
 * _printf - takes a string and args of each '%s' and '%c and prints them
 * @format: initial string containing % + char denoting type and number of args
 * @...: variable list of arguments
 *
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, j, count = 0;
	char cbuf;
/*	int *ibuf = 0; */
	char *sbuf;
	va_list lst;

	va_start(lst, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				count += 1;
				cbuf = va_arg(lst, int);
				write(1, &cbuf, 1);
			}
			else if (format[i + 1] == '%')
			{
				count += 1;
				cbuf = '%';
				write(1, &cbuf, 1);
			}
			else if (format[i + 1] == 's')
			{
				sbuf = va_arg(lst, char *);
				if (sbuf == NULL)
					sbuf = "(null)";
				for (j = 0; sbuf[j]; j++)
				{
					write(1, &sbuf[j], 1);
					count += 1;
				}
			}
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count += 1;
		}
	}
	va_end(lst);
	return (count);
}
