#include "main.h"

/**
 * rev_string - reverses a string
 * @s: the string to reverse
 */

void rev_string(char *s)

{
int length = 0;
int i = 0;
char temp;

while (s[length] != '\0')

{
length++;
}
for (i = 0; i < length / 2; i++)
{
temp = s[i];
s[i] = s[length - 1 - i];
s[length - 1 - i] = temp;
}
}
