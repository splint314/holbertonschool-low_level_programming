#include "main.h"

/**
 * check_prime - checks if n has a divisor starting from i
 * @n: number to check
 * @i: current divisor to test
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int check_prime(int n, int i)
{
if (i * i > n)      /* on a testé tous les diviseurs utiles */
return (1);
if (n % i == 0)     /* trouvé un diviseur */
return (0);
return (check_prime(n, i + 1));
}

/**
 * is_prime_number - returns 1 if the input integer is a prime number,
 * otherwise return 0
 * @n: number to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
if (n <= 1)
return (0);
return (check_prime(n, 2));
}
