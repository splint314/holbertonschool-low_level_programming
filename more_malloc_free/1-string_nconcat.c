#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to concatenate from s2
 *
 * Return: pointer to the concatenated string
 *         NULL if memory allocation fails
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
char *concat;
unsigned int len1, len2, total_len;
if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";
len1 = strlen(s1);
len2 = strlen(s2);
if (n >= len2)
n = len2;
total_len = len1 + n + 1;
concat = malloc_checked(total_len);
if (concat == NULL)
return (NULL);
strcpy(concat, s1);
strncat(concat, s2, n);
return (concat);
}
