#include "main.h"
/**
 * puts_half - prints the second half of a string
 * @str: the string to print
 *
 * Description: This function prints the second half of a string,
 * It then prints a newline at the end.
 */

void puts_half(char *str)
{
int len = 0;
int n;
int i;

while (str[len] != '\0')
len++;
if (len % 2 == 0)
n = len / 2;
else
n = (len + 1) / 2;

for (i = n; str[i] != '\0'; i++)
_putchar(str[i]);

_putchar('\n');
}
