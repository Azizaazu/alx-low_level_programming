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

	while (s[lon] != '\0')
	{
		lon++;
	}
	for (lon = lon - 1; lon >= 0; lon--)
	{
		_putchar(s[lon]);
	}
	_putchar('\n');
}
