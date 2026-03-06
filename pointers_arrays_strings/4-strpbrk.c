#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: the string to search
 * @accept: the string containing the bytes to search for
 *
 * Return: a pointer to the byte in s
 */
char *_strpbrk(char *s, char *accept)
{
unsigned int i, j;
char *p;

for (i = 0; s[i] != '\0'; i++)
{
for (j = 0; accept[j] != '\0'; j++)
{
if (s[i] == accept[j])
{
p = &s[i];
return (p);
}
}
}
return (NULL);
}
