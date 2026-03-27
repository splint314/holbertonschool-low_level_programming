#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
* add_node - adds a new node at the beginning of a list_t list
* @head: pointer to pointer to the head of the list
* @str: string to add
* Return: address of the new element, or NULL if it failed
*/

list_t *add_node(list_t **head, const char *str)
{
list_t *node;
int len;

if (!head)
return (NULL);
node = malloc(sizeof(list_t));
if (node == NULL)
return (NULL);
node->str = strdup(str);
if (!node->str)
{
free(node);
return (NULL);
}
for (len = 0; str[len]; len++)
;
node->len = len;
node->next = *head;
*head = node;
return (node);
}