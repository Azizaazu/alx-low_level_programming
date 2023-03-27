#include "main.h"

/**
 * print_rev - a function that prints a string, in reverse
 * @s: string
 *
 * Return: 0
 */

void print_rev(char *s)
{
	int lon = 0;
	int r;

	while (*s != '\0')
	{
		lon++;
		s++;
	}
	s--;
	for (r = lon; r > 0; r++)
	{
		_putchar(*s);
		s--;
	}
	_putchar('\n');
}
