#include "main.h"

/**
 * rev_string - reverse array
 * @n: integer
 * Return: 0
 */
void rev_string(char *n)
{
	int i = 0;
	int j = 0;
	char temp;

	while (*(n + i) != '\0')
	{
		i++;
	}
	i--;

	for (j = 0; j < i; j++, i--)
	{
		temp = *(n + j);
		*(n + j) = *(n + i);
		*(n + i) = temp;
	}
}

/**
 * infinite_add - a function that adds two numbers
 * @n1: number
 * @n2: number
 * @r: buffer to store the result
 * @size_r: buffer size
 * Return: result.
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int of = 0, i = 0, j = 0, dig = 0;
	int vl1 = 0, vl2 = 0, tpt = 0;

	while (*(n1 + i) != '\0')
		i++;
	while (*(n2 + j) != '\0')
		j++;
	i--;
	j--;
	if (i >= size_r || j >= size_r)
		return (0);
	while (i >= 0 || j >= 0 || of == 1)
	{
		if (i < 0)
			vl1 = 0;
		else
			vl1 = *(n1 + i) - '0';
		if (j < 0)
			vl2 = 0;
		else
			vl2 = *(n2 + j) - '0';
		tpt = vl1 + vl2 + of;
		if (tpt >= 10)
			of = 1;
		else
			of = 0;
		if (dig >= (size_r - 1))
			return (0);
		*(r + dig) = (tpt % 10) + '0';
		dig++;
		j--;
		i--;
	}
	if (dig == size_r)
		return (0);
	*(r + dig) = '\0';
	rev_string(r);
	return (r);
}
