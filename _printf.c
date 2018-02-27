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
	int i, j, n, count = 0;
	char cbuf;
	char *sbuf;
	int ibuf, tmp;
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
			else if (format[i + 1] == 'd' || format [i + 1] == 'i')
			{
				ibuf = va_arg(lst, int);
				tmp = ibuf;
				for (n = 0; tmp / 10 != 0; n++)
					tmp = tmp / 10;
				sbuf = malloc(sizeof(char) * (n + 1));
				if (sbuf == NULL)
					return(count);
				for (j = 0; ibuf / 10 != 0; j++)
				{
					sbuf[j] = ibuf % 10;
					ibuf = ibuf / 10;
				}
				sbuf[j] = ibuf % 10;
				for ( ; j >= 0; j--)
				{
					write(1, &sbuf[j + '0'], 1);
					count += 1;
				}
				free(sbuf);
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
