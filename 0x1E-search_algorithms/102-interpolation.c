#include "search_algos.h"

/**
 *interpolation_search - searches for a value in a sorted array of int
 *@array: pointer of the array
 *@size: size
 *@value: value to search in
 *
 *Return: first index
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t idx, le, r;

	if (array == NULL)
		return (-1);

	for (le = 0, (r = size - 1); r >= le;)
	{
		idx = le + (((double)(r - le) / (array[r] - array[le])) * (value - array[le]));
		if (idx < size)
		{
			printf("Value checked array [%ld] = [%d]\n", idx, array[idx]);
		}
		else
		{
			printf("Value checked array [%ld] is out of range\n", idx);
			break;
		}

		if (array[idx] == value)
			return (idx);
		if (array[idx] > value)
			r = idx - 1;
		else
			le = idx + 1;
	}
	return (-1);

}
