#include "holberton.h"

/**
 * _print_char - prints character from the corresponging
 * argument from the arguments list
 * @ls: list of arguments, va_list
 *
 * Return: the number of printed chars, int
 */
int _print_char(va_list ls)
{
	char c = va_arg(ls, int);

	write(1, &c, 1);
	return(1);
}

/**
 * _print_mod - prints "%" character
 * @ls: list of arguments, va_list
 *
 * Return: the number of printed chars, int
 */
int _print_mod(va_list ls)
{
	char c = '%';

	(void) ls;

	write(1, &c, 1);
	return (1);
}

/**
 * _print_string - prints the string, char by char
 * @ls: list of arguments, va_list
 *
 * Return: the number of printed chars, int
 */
int _print_string(va_list ls)
{
	int i, count = 0;
	char *sbuf = va_arg(ls, char *);

	if (sbuf == NULL)
		sbuf = "(null)";

	for (i = 0; sbuf[i]; i++)
	{
		write(1, &sbuf[i], 1);
		count += 1;
	}

	return (count);
}

/**
 * _print_int - prints a decimal integer
 * @ls: list of arguments, va_list
 *
 * Return: the number of printed chars, int
 */
int _print_int(va_list ls)
{
	int n, j, count = 0;
	int ibuf = va_arg(ls, int);
	int tmp = ibuf;
	char *sbuf;

	for (n = 0; tmp / 10 != 0; n++)
		tmp = tmp / 10;

	sbuf = malloc(sizeof(char) * (n + 1));

	if (sbuf == NULL)
		exit(-1);

	for (j = 0; ibuf / 10 != 0; j++)
	{
		sbuf[j] = (ibuf % 10) + '0';
		ibuf = ibuf / 10;
	}

	sbuf[j] = (ibuf % 10) + '0';

	for (; j >= 0; j--)
	{
		write(1, &sbuf[j], 1);
		count += 1;
	}

	free(sbuf);

	return (count);
}
