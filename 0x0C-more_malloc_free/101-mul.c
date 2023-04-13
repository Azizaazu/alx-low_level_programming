#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <ctype.h>

/**
 * _is_zero - prints buffer in hexa
 * @argv: argument
 * Return: Nothing.
 */

void _is_zero(char *argv[])
{
	int a, z1 = 1, z2 = 1;

	for (a = 0; argv[1][a]; a++)
		if (argv[1][a] != '0')
		{
			z1 = 0;
			break;
		}
	for (a = 0; argv[2][a] != '0'; a++)
		if (argv[2][a] != '0')
		{
			z2 = 0;
			break;
		}
	if (z1 == 1 || z2 == 1)
	{
		printf("0\n");
		exit(0);
	}
}

/**
 * _intialize_array - set memory to zero in new array
 * @array: array
 * @len: length of array
 * Return: ptr of array
 */

char *_intialize_array(char *array, int len)
{
	int a = 0;

	for (a = 0; a < len; a++)
		array[a] = '0';
	array[len] = '\0';
	return (array);
}

/**
 * _checknum - determines length of a number
 * @argv: arguments
 * @n: row of array
 * Return: length of number
 */
int _checknum(char *argv[], int n)
{
	int len;

	for (len = 0; argv[n][len]; len++)
		if (!isdigit(argv[n][len]))
		{
			printf("Error\n");
			exit(98);
		}
	return (len);
}
/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: arguments
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int len1, len2, ls, add, addlen, a, b, c, carry;
	char *s;

	if (argc != 3)
		printf("Error\n"), exit(98);
	len1 = _checknum(argv, 1);
	len2 = _checknum(argv, 2);
	_is_zero(argv);
	ls = len1 + len2;
	s = malloc(ls + 1);
	if (s == NULL)
		printf("Error\n"), exit(98);
	s = _intialize_array(s, ls);
	c = ls - 1;
	a = len1 - 1;
	b = len2 - 1;
	carry = addlen = 0;
	for (; c >= 0; c--, a--)
	{
		if (a < 0)
		{
			if (addlen > 0)
			{
				add = (s[c] - '0') + addlen;
				if (add > 9)
					s[c - 1] = (add / 10) + '0';
				s[c] = (add % 10) + '0';
			}
			a = len1 - 1, b--, addlen = 0, carry++, c = ls - (1 + carry);
		}
		if (b < 0)
		{
			if (s[0] != '0')
				break;
			ls--;
			free(s), s = malloc(ls + 1), s = _intialize_array(s, ls);
			c = ls - 1, a = len1 - 1, b = len2 - 1, carry = addlen = 0;
		}
		if (b >= 0)
		{
			add = ((argv[1][a] - '0') * (argv[2][b] - '0')) + (s[c] - '0') + addlen;
			addlen = add / 10, s[c] = (add % 10) + '0';
		}
	}
		printf("%s\n", s);
		return (0);
}
