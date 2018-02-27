#include "holberton.h"
#include <stdio.h>

/**
 * main - tests the _printf function
 *
 * Return: Always 0.
 */
int main(void)
{
	printf("%d\n", printf("Hello %i. \n"));
	printf("%d\n", _printf("Hello %i. \n"));
	printf("%d\n", printf("Hello %i. \n", 0));
	printf("%d\n", _printf("Hello %d. \n", 0));
	printf("%d\n", printf("Hello %i. \n", 67));
	printf("%d\n", _printf("Hello %i. \n", 67));
	printf("%d\n", printf("Hello %i. \n", 127));
	printf("%d\n", _printf("Hello %d. \n", 127));
	printf("%d\n", 0 % 10);
	_printf("%d\n", 0 % 10);

	return (0);
}
