#include "search_algos.h"

/**
  * advanced_binary_recursive - Searches recursively for a value in a sorted
  * array of integers using binary search.
  *
  * @array: array to search.
  * @left: starting index
  * @right: ending index
  * @value: value to search for
  *
  * Return: value is not present, -1. index where the value is located.
  * Description: Prints the [sub]array being searched after each change.
  */

int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t idx;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (idx = left; idx < right; idx++)
		printf("%d, ", array[idx]);
	printf("%d\n", array[idx]);

	idx = left + (right - left) / 2;
	if (array[idx] == value && (idx == left || array[idx - 1] != value))
		return (idx);
	if (array[idx] >= value)
		return (advanced_binary_recursive(array, left, idx, value));
	return (advanced_binary_recursive(array, idx + 1, right, value));
}

/**
 *advanced_binary -  a function that searches for a value
 *in a sorted array of integers.
 *
 * @array: array
 * @size: Size
 * @value: Element to be searched
 *
 * Return: return index of searched element
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
