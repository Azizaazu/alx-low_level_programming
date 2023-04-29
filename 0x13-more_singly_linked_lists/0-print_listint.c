#include "lists.h"


/**
 * print_listint - prints all the elements of a listint_t list
 * @h: linked list
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	const listint_t *c = h;
	size_t nm = 0;

	while (c != NULL)
	{
		printf("%d\n", c->n);
		nm += 1;
		c = c->next;
	}
	return (nm);
}
