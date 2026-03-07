#include "main.h"

/**
* reverse_array - reverses an array of integers
* @a: an array of integers
* @n: the number of elements to swap.
*/

void reverse_array(int *a, int n)
{
int i;
int temp;

i = 0;
while (i < n / 2)
{
temp = a[i];
a[i] = a[n - 1 - i];
a[n - 1 - i] = temp;
i++;
}
}
