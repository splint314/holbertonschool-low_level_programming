#include <stdio.h>
#include "main.h"
/**
 * _strchr - Entry point
 *
 * Description : fills memory with a constant byte.
 * @s: a
 * @c: a
 *
 * Return: always 0 (success)
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (c == '\0')
	{
		return (s);
	}
	return (NULL);
}
