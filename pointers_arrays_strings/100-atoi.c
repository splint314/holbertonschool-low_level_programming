#include "main.h"
#include <limits.h>

/**
 * _atoi - convert a string to an integer
 * @s: string to convert
 *
 * Return: the converted integer, or 0 if no number is found
 */
int _atoi(char *s)
{
int i = 0, sign = 1, started = 0, found = 0;
int result = 0, digit;

while (s[i] != '\0')
{
if (!started && (s[i] == '-' || s[i] == '+'))
{
if (s[i] == '-')
sign *= -1;
}
else if (s[i] >= '0' && s[i] <= '9')
{
started = 1;
found = 1;
digit = s[i] - '0';

if (sign == 1)
{
if (result > (INT_MAX - digit) / 10)
return (INT_MAX);
result = result * 10 + digit;
}
else
{
if (result < (INT_MIN + digit) / 10)
return (INT_MIN);
result = result * 10 - digit;
}
}
else if (started)
{
break;
}

i++;
}

if (!found)
return (0);

return (result);
}
