#include "main.h"
/**
 * _print_rev_recursion - prints a string in reverse followed by a new line
 * @x: the base number
 * @y: the exponent
 */
int _pow_recursion(int x, int y)
{
if (y < 0)
return (-1);
if (y == 0)
return (1);
return (x * _pow_recursion(x, y - 1));
}
