#include "main.h"

/**
 * print_times_table - function that prints the n times table, starting with 0
 *@n: parameter
 * Return: Always 0.
 */

void print_times_table(int n)
{
int a, b, r;
if (n <= 15 && n >= 0)
{
for (a = 0; a <= n; a++)
{
_putchar('0');

for (b = 1; b <= n; b++)
{
_putchar(',');
_putchar(' ');
r = a * b;
if (r <= 99)
_putchar(' ');

if (r <= 9)
_putchar(' ');
if (r >= 100)
{
_putchar((r / 100) + '0');
_putchar((r / 10) % 10 + '0');
}
else if (r <= 99 && r >= 10)
{
_putchar((r / 10) + '0');
}
_putchar((r % 10) + '0');
}
_putchar('\n');
}
}
}
