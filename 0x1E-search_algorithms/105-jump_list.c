#include "search_algos.h"

/**
 * jump_list - Searches linked list of integers using jump search.
 * @list: A pointer
 * @size: number of nodes
 * @value: value to search for.
 *
 * Return:NULL, pointer to the first node where the value is located.
 * Description: Prints a value every time it is compared in the list.
 *
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t stp, stp_size;
	listint_t *nd, *jmp;

	if (list == NULL || size == 0)
		return (NULL);

	stp = 0;
	stp_size = sqrt(size);
	for (nd = jmp = list; jmp->index + 1 < size && jmp->n < value;)
	{
		nd = jmp;
		for (stp += stp_size; jmp->index < stp; jmp = jmp->next)
		{
			if (jmp->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jmp->index, jmp->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			nd->index, jmp->index);

	for (; nd->index < jmp->index && nd->n < value; nd = nd->next)
		printf("Value checked at index [%ld] = [%d]\n", nd->index, nd->n);
	printf("Value checked at index [%ld] = [%d]\n", nd->index, nd->n);

	return (nd->n == value ? nd : NULL);
}
