#include <stdio.h>
#include "main.h"

/**
 * _puts - prints a string followed by a new line
 * @s: the string to print
 */

void _puts(char *s)
{
while (*s != '\0')
{
_putchar (*s);
s++;
}
_putchar ('\n');
}
