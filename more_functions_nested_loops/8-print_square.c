#include "main.h"

/**
 * print_square - Prints a square in the terminal
 * @size: size of the square
 *
 * Description: If size <= 0, prints only a newline.
 */
void print_square(int size)
{
int i, j;

if (size <= 0)
{
_putchar('\n');
return;
}

for (i = 0; i < size; i++)
{
for (j = 0; j < size; j++)
_putchar('#');
_putchar('\n');
}
}
