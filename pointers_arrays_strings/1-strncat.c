#include "main.h"

/** 
 * main - Entry point
 * 
 * Return: Always 0 (Success)
*/
char *_strncat(char *dest, char *src, int n)
{
int i = 0, j = 0;

while (dest[i] != '\0')
i++;

while (j < n && src[j] != '\0') {
dest[i + j] = src[j];
j++;
}

dest[i + j] = '\0';
return dest;
}
