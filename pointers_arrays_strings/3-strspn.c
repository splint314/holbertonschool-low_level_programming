#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the string to search
 * @accept: the string containing the characters to match
 *
 * Return: the number of characters in the initial segment of s
 */
unsigned int _strspn(char *s, char *accept)
{
unsigned int i, j;
unsigned int count = 0;

for (i = 0; s[i] != '\0'; i++)
{
for (j = 0; accept[j] != '\0'; j++)
{
if (s[i] == accept[j])
{
count++;
break;
}
}
if (accept[j] == '\0')
{
break;
}
}
return (count);
}
