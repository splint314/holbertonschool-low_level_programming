#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
* add_node_end - adds a new node at the end of a list_t list
* @head: pointer to pointer to the head of the list
* @str: string to add
* Return: address of the new element, or NULL if it failed
*/
list_t *add_node_end(list_t **head, const char *str)
{
list_t *new, *temp;
unsigned int i = 0;

if (head == NULL)
return (NULL);
new = malloc(sizeof(list_t));
if (new == NULL)
return (NULL);
if (str)
{
new->str = strdup(str);
if (new->str == NULL)
{
free(new);
return (NULL);
}
while (str[i])
i++;
new->len = i;
}
else
{
new->str = NULL;
new->len = 0;
}
new->next = NULL;
if (*head == NULL)
{
*head = new;
return (new);
}
temp = *head;
while (temp->next)
temp = temp->next;
temp->next = new;
return (new);
}
