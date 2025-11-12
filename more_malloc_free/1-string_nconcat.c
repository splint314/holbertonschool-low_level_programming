#include <stdlib.h>

/**
 * string_nconcat - concatenates s1 with the first n bytes of s2
 * @s1: first string (may be NULL; treat as "")
 * @s2: second string (may be NULL; treat as "")
 * @n: number of bytes from s2 to concatenate
 *
 * Return: pointer to newly allocated string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
char *p;
unsigned int len1 = 0, len2 = 0, i, j;

if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";

while (s1[len1] != '\0')
len1++;
while (s2[len2] != '\0')
len2++;

if (n < len2)
len2 = n; /* take min(n, original length of s2) */

p = malloc((len1 + len2 + 1) * sizeof(char));
if (p == NULL)
return (NULL);

for (i = 0; i < len1; i++)
p[i] = s1[i];
for (j = 0; j < len2; j++)
p[i + j] = s2[j];

p[i + j] = '\0';
return (p);
}
