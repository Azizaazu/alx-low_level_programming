#include "lists.h"



/**
 * get_dnodeint_at_index - returns the nth node
 * @head: pointer to head
 * @index: index of the node
 *
 * Return: nth or null
 **/


dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int s;
	dlistint_t *t;

	s = 0;
	if (head == NULL)
	return (NULL);

	t = head;
	while (t)
	{
	if (index == s)
	return (t);

	s++;
	t = t->next;
	}

	return (NULL);
}
