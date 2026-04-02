#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_dnodeint - Adds a node at the beginning of a linked list.
 * @head: Pointer to the first node of the list.
 * @n: Integer to add in the node.
 * Return: Pointer to the beginning of the list.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
dlistint_t *new_node;

new_node = malloc(sizeof(dlistint_t));
if (!new_node)
return (0);
if (!*head)
{
new_node->n = n;
*head = new_node;
return (new_node);
}
new_node->next = *head;
new_node->n = n;
new_node->next->prev = new_node;
*head = new_node;
return (new_node);
}