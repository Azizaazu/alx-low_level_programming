#include "search_algos.h"
#include <math.h>

/**
 * jump_search - searches for a value in an array of integers
 * @array: array
 * @size: size
 * @value: value
 *
 * Return: idx of the num
 */
int jump_search(int *array, size_t size, int value)
{
	int idx, num, ke, prv;

	if (array == NULL || size == 0)
		return (-1);

	num = (int)sqrt((double)size);
	ke = 0;
	prv = idx = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", idx, array[idx]);

		if (array[idx] == value)
			return (idx);
		ke++;
		prv = idx;
		idx = ke * num;
	} while (idx < (int)size && array[idx] < value);

	printf("Value found between indexes [%d] and [%d]\n", prv, idx);

	for (; prv <= idx && prv < (int)size; prv++)
	{
		printf("Value checked array[%d] = [%d]\n", prv, array[prv]);
		if (array[prv] == value)
			return (prv);
	}

	return (-1);
}
