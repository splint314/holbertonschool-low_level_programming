#include lists.h
#include <stdio.h>

size_t print_dlistint(const dlistint_t *h);

{
while (h != NULL)
{
printf("%d ", h->n);
h = h->next;
}
printf("\n");
}

return count;