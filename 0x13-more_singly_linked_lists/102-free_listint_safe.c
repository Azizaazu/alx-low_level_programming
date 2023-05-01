#include "lists.h"



/**
 * free_listint_safe - frees a listint_t list
 * @h: pointer
 *
 * Return: num of elelment to freed
 *
 */
size_t free_listint_safe(listint_t **h)
{
	size_t l = 0;
	int dif;
	listint_t *t;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		dif = *h - (*h)->next;

		if ((dif > 0))
		{
			t = (*h)->next;
			free(*h);
			*h = t;
			l++;
		}
		else
		{
			free(*h);
			*h = NULL;
			l++;
			break;
		}
	}
		*h = NULL;

		return (l);
}
