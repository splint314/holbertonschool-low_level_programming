#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
* add_node - adds a new node at the beginning of a list_t list.
* @head: double pointer to the head of the list.
* @str: string to be added to the new node.
* Return: pointer to the new node, or NULL if allocation fails.
*/
list_t *add_node(list_t **head, const char *str)
{
list_t *new_node;
char *dup_str;

if (str == NULL)
return (NULL);
new_node = malloc(sizeof(list_t));
if (new_node == NULL)
return (NULL);
dup_str = strdup(str);
if (dup_str == NULL)
{
free(new_node);
return (NULL);
}	
new_node->str = dup_str;
new_node->len = strlen(dup_str);
new_node->next = *head;
*head = new_node;
return (new_node);
}
