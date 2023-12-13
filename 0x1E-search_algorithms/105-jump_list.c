#include "search_algos.h"
#include <math.h>

/**
 * jump_list - searches for a value in an array of integers
 * using the Jump search algorithm
 * @list: input list
 * @size: size
 * @value: value
 *
 * Return: index of the number
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t idx, ke, num;
	listint_t *prv;

	if (list == NULL || size == 0)
		return (NULL);

	num = (size_t)sqrt((double)size);
	idx = 0;
	ke = 0;

	do {
		prv = list;
		ke++;
		idx = ke * num;

		while (list->next && list->idx < idx)
			list = list->next;

		if (list->next == NULL && idx != list->idx)
			idx = list->idx;

		printf("Value checked at index [%d] = [%d]\n", (int)idx, list->n);

	} while (idx < size && list->next && list->n < value);

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)prv->idx, (int)list->idx);

	for (; prv && prv->idx <= list->idx; prv = prv->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)prv->idx, prv->n);
		if (prv->n == value)
			return (prv);
	}

	return (NULL);
}
