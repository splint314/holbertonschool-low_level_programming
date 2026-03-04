#include "main.h"
#include <stdio.h>

/**
 * _strncat - concatenates two strings, using at most n bytes from src
 * @dest: the string to be concatenated upon
 * @src: the string to concatenate to dest
 * @n: the number of bytes from src to concatenate to dest
 *
 * Return: a pointer to the resulting string dest
 */

char *_strncat(char *dest, char *src, int n)
{
int i, j;

i = 0;
while (dest[i] != '\0')
{
i++;
}

j = 0;
while (j < n && src[j] != '\0')
{
dest[i] = src[j];
i++;
j++;
}

dest[i] = '\0';

return (dest);
}
