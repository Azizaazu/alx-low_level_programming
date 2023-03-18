#include <stdio.h>
/**
 * main - program that prints all single digit numbers of base
 *
 * Return: 0 (success)
 */
int main(void)
{
int a;
char b;
a = 0;
b = 'a';
while (a < 10)
{
putchar (a + '0');
a++;
}
while (b <= 'f')
{
putchar (b);
b++;
}
putchar ('\n');
return (0);
}
