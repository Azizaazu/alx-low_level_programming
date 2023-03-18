#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - prints all possible combination of two two-digit numbers
 *
 * Return: 0 (success)
 */

int main(void)
{
int a;
int b;
for (a = 0; a <= 98 ; a++)
{
for (b =  1; b <= 99; b++)
{
if ((a + (a % 10)) != (b + (b % 10)))
{
putchar ((a / 10) + '0');
putchar ((a % 10) + '0');
putchar (' ');
putchar ((b / 10) + '0');
putchar ((b % 10) + '0');
if (a == 98 && b == 99)
continue;
putchar (',');
putchar (' ');
}
}
}
putchar ('\n');
return (0);
}
