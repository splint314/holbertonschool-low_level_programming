#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: the string to convert
 *
 * Return: the integer representation of the string
 */

int _atoi(char *s)
{
int i = 0, sign = 1, result = 0;
while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
i++;
if (s[i] == '-' || s[i] == '+')
{
if (s[i] == '-')
sign = -1;
i++;
}
while (s[i] >= '0' && s[i] <= '9')
{
result = result * 10 + (s[i] - '0');
i++;
}
return (sign * result);
}
