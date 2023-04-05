#include "main.h"
#include <stdio.h>

int check_pal(char *s, int i, int l);
int _strlen_recursion(char *s);

/**
 * is_palindrome - returns 1 if a string is a palindrome and 0 if not.
 * @s: string
 * Return: 1 if it is, 0 if its not
 */

int is_palindrome(char *s)
{
	if (*s == 0)
		return (1);
	return (check_pal(s, 0, _strlen_recursion(s)));
}

/**
 * _strlen_recursion - returns the length of a string
 * @s: string
 * Return: l
 */

int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}

/**
 * check_pal - checks if it is a palindrome
 * @s: string
 * @i: iterator
 * @l: length
 * Return: l
 */

int check_pal(char *s, int i, int l)
{
	if (*(s + i) != *(s + l - 1))
		return (0);
	if (i >= l)
		return (1);
	return (check_pal(s, i + 1, l - 1));
}
