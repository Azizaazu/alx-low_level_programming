#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: If width or height is 0 or negative, return NULL
 */

int **alloc_grid(int width, int height)
{
	int **gr;
	int x, y;

	if (width <= 0 || height <= 0)
		return (NULL);

	gr = malloc(sizeof(int *) * height);

	if (gr == NULL)
		return (NULL);
	for (x = 0; x < height; x++)
	{
		gr[x] = malloc(sizeof(int) * width);
		if (gr[x] == NULL)
		{
			for (; x >= 0; x--)
				free(gr[x]);
		free(gr);
		return (NULL);
		}
	}
	for (x = 0; x < height; x++)
	{
		for (y = 0; y < width; y++)
			gr[x][y] = 0;
	}
	return (gr);
}


