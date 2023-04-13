#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: minimum value
 * @max: maximum value
 * Return: poiter to newly created array
 * If min > max, return NULL
 * If malloc fails, return NULL
 */

int *array_range(int min, int max)
{
	int *a;
	int x;

	if (min > max)
		return (NULL);
	a = malloc(sizeof(*a) * ((max - min) + 1));
	if (a == NULL)
		return (NULL);
	for (x = 0; min <= max; x++, min++)
		a[x] = min;
	return (a);
}
