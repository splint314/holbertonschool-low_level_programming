#include <stdarg.h>

/**
* sum_them_all - returns the sum of all its parameters
* @n: number of arguments passed to the function
*
* Return: the sum of all arguments, or 0 if n is 0
*/

int sum_them_all(const unsigned int n, ...)
{
va_list args;
unsigned int i;
int total = 0;

va_start(args, n);

for (i = 0; i < n; i++)
{
total += va_arg(args, int);
}

va_end(args);

return total;
}
