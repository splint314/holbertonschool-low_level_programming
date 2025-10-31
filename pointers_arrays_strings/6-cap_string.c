#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: the string to modify
 *
 * Description: This function capitalizes every word in the string.
 * A word is defined as a sequence of letters separated by one of these:
 * space, tab, newline, ',', ';', '.', '!', '?', '"', '(', ')', '{', or '}'.
 *
 * Return: a pointer to the modified string
 */
char *cap_string(char *str)
{
int i = 0, j;
char separators[] = " \t\n,;.!?\"(){}";

/* Capitalize first letter if it's lowercase */
if (str[0] >= 'a' && str[0] <= 'z')
str[0] -= 32;

while (str[i] != '\0')
{
for (j = 0; separators[j] != '\0'; j++)
{
if (str[i] == separators[j] && str[i + 1] >= 'a' && str[i + 1] <= 'z')
{
str[i + 1] -= 32;
break;
}
}
i++;
}

return (str);
}
