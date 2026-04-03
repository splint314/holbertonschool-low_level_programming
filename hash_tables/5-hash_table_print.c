#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: hash table
 *
 * Return: void
 */

void hash_table_print(const hash_table_t *ht)
{
unsigned long int i;
hash_node_t *tmp;

if (ht == NULL)
return;

for (i = 0; i < ht->size; i++)
{
tmp = ht->array[i];
while (tmp)
{
printf("'%s': '%s'", tmp->key, tmp->value);
if (tmp->next)
printf(", ");
tmp = tmp->next;
}
}
printf("\n");
}
