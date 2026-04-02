#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * print_dlistint - Counts the number of nodes in a list.
 * @h: Pointer to the first node of the list.
 * Return: size_t type , number of nodes.
 */
size_t print_dlistint(const dlistint_t *h)
{
size_t lg = 0;

while (h)
{
printf("%d\n", h->n);
h = h->next;
lg++;
}
return (lg);
}
