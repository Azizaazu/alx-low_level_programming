#include <stdio.h>
#include "lists.h"

size_t loop_listint_length(const listint_t *head);
/**
 * print_listint_safe -  prints a listint_t linked list
 * @head: pointer
 * Return: number of nodes in the list
 *
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nod, idx = 0;

	nod = loop_listint_length(head);

	if (nod == 0)
	{
		for (; head != NULL; nod++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (idx = 0; idx < nod; idx++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (nod);
}
/**
 * loop_listint_length - counts num of a node
 * @head: pointer
 *
 * Return: 0 if is not looped, num of nodes
 *
 */
size_t loop_listint_length(const listint_t *head)
{
	const listint_t *t, *h;
	size_t nod = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	t = head->next;
	h = (head->next)->next;

	while (h)
	{
		if (t == h)
		{
			t = head;

			while (t != h)
			{
				nod++;
				t = t->next;
				h = h->next;
			}

			t = t->next;

			while (t != h)
			{
				nod++;
				t = t->next;
			}
			return (nod);
		}
		t = t->next;
		h = (h->next)->next;
	}
	return (0);
}
