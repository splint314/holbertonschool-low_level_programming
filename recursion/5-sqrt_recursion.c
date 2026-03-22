#include "main.h"

/**
* _sqrt_helper - helper to find square root recursively
* @n: original number
* @i: current guess
*
* Return: the natural square root of n, or -1 if none exists
*/
int _sqrt_helper(int n, int i)
{
if (i * i == n)
return (i);
else if (i * i > n)
return (-1);
else
return (_sqrt_helper(n, i + 1));
}

/**
* _sqrt_recursion - returns the natural square root of a number
* @n: number to calculate the square root of
*
* Return: the natural square root of n, or -1 if n does not have a natural
* square root
*/
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
else if (n == 0 || n == 1)
return (n);
else
return (_sqrt_helper(n, 1));
}
