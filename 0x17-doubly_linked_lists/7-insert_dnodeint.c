#include "lists.h"



/**
 * insert_dnodeint_at_index - inserts node in position
 * @h: head
 * @idx: index
 * @n: value node
 *
 * Return: addr node, or NUll
 */


dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *nouveau;
	dlistint_t *hd;
	unsigned int id;

	nouveau = NULL;

	if (idx == 0)
		nouveau = add_dnodeint(h, n);
	else
	{
		hd = *h;
		id = 1;
		if (hd != NULL)
			while (hd->prev != NULL)
				hd = hd->prev;
		while (hd != NULL)
		{
			if (id == idx)
			{
				if (hd->next == NULL)
					nouveau = add_dnodeint_end(h, n);
				else
				{
					nouveau = malloc(sizeof(dlistint_t));
					if (nouveau != NULL)
					{
						nouveau->n = n;
						nouveau->next = hd->next;
						nouveau->prev = hd;
						hd->next->prev = nouveau;
						hd->next = nouveau;
					}
				}
				break;
			}
			hd = hd->next;
			id++;
		}
	}
	return (nouveau);
}
