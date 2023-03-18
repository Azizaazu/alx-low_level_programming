#include <stdio.h>
/**
 * main - program that prints all single digit numbers of base
 *
 * Return: 0 (success)
 */
int main(void)
{
int a;
a = 0;
while (a < 10)
{
putchar (a + '0');
a++;
}
putchar ('\n');
return (0);
}
