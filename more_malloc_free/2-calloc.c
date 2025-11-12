#include <stdlib.h>
#include <limits.h>
/**
 * _calloc - allocates memory for an array and sets it to zero
 * @nmemb: number of elements
 * @size: size of each element in bytes
 * Return: pointer to allocated memory (set to zero),
 *         or NULL if nmemb or size is 0, or if malloc fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
unsigned int i, total;
unsigned char *p;
if (nmemb == 0 || size == 0)
return (NULL);
if (size != 0 && nmemb > UINT_MAX / size)
return (NULL);
total = nmemb * size;
p = malloc(total);
if (p == NULL)
return (NULL);
for (i = 0; i < total; i++)
p[i] = 0;
return (p);
}
