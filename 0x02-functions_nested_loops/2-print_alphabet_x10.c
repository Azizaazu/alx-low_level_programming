#include "main.h"

/**
 * print_alphabet_x10 - a function that prints 10 times the alphabet.
 *
 * Return: 0 (success)
 */
void print_alphabet_x10(void)
{
int a;
char b;
for (a = 1 ; a <= 10 ; a++)
{
for (b = 'a' ; b <= 'z' ; b++)
_putchar(b);
_putchar('\n');
}
}
