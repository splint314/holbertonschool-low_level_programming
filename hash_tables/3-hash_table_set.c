#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: 1 if success, 0 otherwise
 */

 int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
hash_node_t *node;
hash_node_t *tmp;
unsigned long int index;
char *value_copy;

if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
return (0);

index = key_index((const unsigned char *)key, ht->size);

tmp = ht->array[index];
while (tmp)
{
if (strcmp(tmp->key, key) == 0)
{
free(tmp->value);
tmp->value = strdup(value);
return (1);
}
tmp = tmp->next;
}

node = malloc(sizeof(hash_node_t));
if (node == NULL)
return (0);

node->key = strdup(key);
value_copy = strdup(value);

if (node->key == NULL || value_copy == NULL)
{
free(node->key);
free(value_copy);
free(node);
return (0);
}

node->value = value_copy;
node->next = ht->array[index];
ht->array[index] = node;

return (1);
}
