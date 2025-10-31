#include "main.h"

/**
 * _strcmp - compares two strings like strcmp
 * @s1: the first string to compare
 * @s2: the second string to compare
 *
 * Description: Compares the two strings s1 and s2 character by character.
 * It returns:
 *   - a negative value if s1 < s2
 *   - 0 if s1 == s2
 *   - a positive value if s1 > s2
 *
 * Return: the difference between the first two differing bytes (s1[i] - s2[i])
 */
int _strcmp(char *s1, char *s2)
{
int i = 0;

while (s1[i] != '\0' && s2[i] != '\0')
{
if (s1[i] != s2[i])
return (s1[i] - s2[i]);
i++;
}

return (s1[i] - s2[i]);
}
