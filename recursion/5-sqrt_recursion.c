#include "main.h"

/**
 * _sqrt_helper - helps to find the natural square root recursively
 * @n: number to find the square root of
 * @guess: current guess
 *
 * Return: the natural square root of n, or -1 if it doesn't exist
 */
int _sqrt_helper(int n, int guess)
{
if (guess * guess == n)
return (guess);
if (guess * guess > n)
return (-1);
return (_sqrt_helper(n, guess + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to find the square root of
 *
 * Return: the natural square root of n, or -1 if it doesn't exist
 */
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
return (_sqrt_helper(n, 1));
}
