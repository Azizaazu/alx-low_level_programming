#include "main.h"

/**
 * print_last_digit - function that prints the last digit.
 *
 * @d: function parameter
 *
 * Return: Always b
 */

int print_last_digit(int d)
{
int b;
b = d % 10;
if (d < 0)
b = -b;
_putchar(b + '0');
return (b);
}
