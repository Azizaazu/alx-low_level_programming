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
 * _initialize_array - set memory to zero in new array
 * @array: array
 * @len: length of array
 * Return: ptr of array
 */

char *_initialize_array(char *array, int len)
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
	int ln1, ln2, lnout, add, addl, i, j, k, ca;
	char *nout;

	if (argc != 3)
		printf("Error\n"), exit(98);
	ln1 = _checknum(argv, 1), ln2 = _checknum(argv, 2);
	_is_zero(argv), lnout = ln1 + ln2, nout = malloc(lnout + 1);
	if (nout == NULL)
		printf("Error\n"), exit(98);
	nout = _initialize_array(nout, lnout);
	k = lnout - 1, i = ln1 - 1, j = ln2 - 1, ca = addl = 0;
	for (; k >= 0; k--, i--)
	{
		if (i < 0)
		{
			if (addl > 0)
			{
				add = (nout[k] - '0') + addl;
				if (add > 9)
					nout[k - 1] = (add / 10) + '0';
				nout[k] = (add % 10) + '0';
			}
			i = ln1 - 1, j--, addl = 0, ca++, k = lnout - (1 + ca);
		}
		if (j < 0)
		{
			if (nout[0] != '0')
				break;
			lnout--;
			free(nout), nout = malloc(lnout + 1), nout = _initialize_array(nout, lnout);
			k = lnout - 1, i = ln1 - 1, j = ln2 - 1, ca = addl = 0;
		}
		if (j >= 0)
		{
			add = ((argv[1][i] - '0') * (argv[2][j] - '0')) + (nout[k] - '0') + addl;
			addl = add / 10, nout[k] = (add % 10) + '0';
		}
	}
	printf("%s\n", nout);
	return (0);
}

