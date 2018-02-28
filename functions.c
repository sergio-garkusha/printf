#include "holberton.h"
#include <stdio.h>

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
	return (1);
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
	int a, expo = 1, len = 0;
	unsigned int n;
	char pr;

	a = va_arg(ls, int);

	if (a < 0)
	{
		pr = '-';
		len = len + write(1, &pr, 1);
		n = a * -1;
	}
	else
		n = a;
	while (n / expo > 9)
		expo *= 10;

	while (expo != 0)
	{
		pr = n / expo + '0';
		len = len + write(1, &pr, 1);
		n = n % expo;
		expo = expo / 10;
	}
	return (len);
}
