#include "holberton.h"
#include <stdio.h>

/**
 * main - tests the _printf function
 *
 * Return: Always 0.
 */
int main(void)
{
	printf("%. \n");
	printf("%d\n", printf("Hello %%%. \n"));
	_printf("Hello %%%. \n");
	printf("%d\n", _printf("Hello %%%. \n"));

	return (0);
}
