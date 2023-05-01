#include "lists.h"


/**
 * sum_listint - returns the sum of all the data (n) of a listint_t
 * @head: first node
 *
 * Return: sum, if the list is empty 0
 */
int sum_listint(listint_t *head)
{
	int somme = 0;
	listint_t *t = head;

	while (t)
	{
		somme += t->n;
		t = t->next;
	}
	return (somme);
}

