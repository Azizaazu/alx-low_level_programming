#include <stdio.h>
/**
 * main - a program that prints the alphabet in lowercase
 *
 * Return: 0 (success)
 */
int main(void)
{
char c;

c = 'z';
while
(c >= 'a')
{
putchar(c);
c--;
}
putchar('\n');
return (0);
}
