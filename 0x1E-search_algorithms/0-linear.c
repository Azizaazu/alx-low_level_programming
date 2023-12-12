#include "search_algos.h"

/**
 * linear_search - searches for a value in a sorted array of integers
 * @array: array
 * @size: size
 * @value: value to search in
 *
 * Return: index of value or -1 if not found
 */


int linear_search(int *array, size_t size, int value)
{
	size_t in;

	if (array == NULL)
		return (-1);
	for (in = 0; in < size; in++)
	{
		printf("Value checked array[%ld] = [%d]\n", in, array[in]);
		if (array[in] == value)
			return (in);
	}
	return (-1);
}
