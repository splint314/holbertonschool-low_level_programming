#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: double pointer to the head of the list
 * @index: index of the node to delete (starting at 0)
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp;
    unsigned int i = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    tmp = *head;

    /* Case index 0: delete the head node */
    if (index == 0)
    {
        *head = tmp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(tmp);
        return (1);
    }

    /* Move forward until reaching the node at the given index */
    while (tmp != NULL && i < index)
    {
        tmp = tmp->next;
        i++;
    }

    /* If the index is out of range */
    if (tmp == NULL)
        return (-1);

    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;

    if (tmp->prev != NULL)
        tmp->prev->next = tmp->next;

    free(tmp);
    return (1);
}
