#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the head of the list
 * @idx: index where the new node should be placed
 * @n: value of the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *tmp = *h, *new;
unsigned int i = 0;

if (h == NULL)
return (NULL);

/* Case 1: insert at head */
if (idx == 0)
return (add_dnodeint(h, n));

/* Traverse until the position */
while (tmp != NULL && i < idx - 1)
{
tmp = tmp->next;
i++;
}

/* If out of bounds */
if (tmp == NULL)
return (NULL);

/* Case 2: insert at end */
if (tmp->next == NULL)
return (add_dnodeint_end(h, n));

/* Case 3: insert in the middle */
new = malloc(sizeof(dlistint_t));
if (new == NULL)
return (NULL);

new->n = n;

new->next = tmp->next;
new->prev = tmp;

tmp->next->prev = new;
tmp->next = new;

return (new);
}
