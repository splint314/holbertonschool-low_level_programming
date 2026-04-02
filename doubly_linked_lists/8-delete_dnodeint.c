#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given index in a
 * doubly linked list.
 * @head: A pointer to the head of the list.
 * @index: The index of the node to be deleted. Index starts at 0.
 *
 * Return: If the function fails, it should return -1. Otherwise, it should
 * return 1.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *current = *head;
unsigned int i;
if (*head == NULL)
return (-1);
if (index == 0)
{
*head = current->next;
if (*head != NULL)
(*head)->prev = NULL;
free(current);
return (1);
}
for (i = 0; current != NULL && i < index; i++)
current = current->next;
if (current == NULL)
return (-1);
if (current->prev != NULL)
current->prev->next = current->next;
if (current->next != NULL)
current->next->prev = current->prev;
free(current);
return (1);
}
