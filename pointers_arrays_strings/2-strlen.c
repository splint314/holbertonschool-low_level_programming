#include <stdio.h>
#include "main.h"

/**
 * _strlen - entry point
 *
 * Description: returns the length of a string
 * @s: the string
 * Return: 0 if (success)
 */

int _strlen(char *s)
{
int length = 0;

while (*s != '\0')
{
length++;
s++;
}
return (length);
}
