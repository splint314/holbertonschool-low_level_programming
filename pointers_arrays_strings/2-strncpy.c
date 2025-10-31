#include "main.h"

/**
 * _strncpy - copies a string like the standard strncpy
 * @dest: the destination buffer
 * @src: the source string
 * @n: the maximum number of bytes to copy from src
 *
 * Description: This function copies up to n bytes from the string pointed
 * to by src to the buffer pointed to by dest. If the length of src is less
 * than n, the remaining bytes in dest are filled with '\0'. If src is longer
 * than or equal to n, dest will not be null-terminated.
 *
 * Return: a pointer to the resulting string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
int i;

for (i = 0; i < n && src[i] != '\0'; i++)
dest[i] = src[i];

for (; i < n; i++)
dest[i] = '\0';

return (dest);
}
