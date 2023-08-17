#include "lists.h"



/**
 * sum_dlistint - returns the sum
 * @head: head
 *
 * Return: some
 */


int sum_dlistint(dlistint_t *head)
{
	int some;

	some = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;

		while (head != NULL)
		{
			some += head->n;
			head = head->next;
		}
	}
	return (some);
}
