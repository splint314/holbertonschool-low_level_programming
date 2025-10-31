#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers
 * @a: the array of integers to reverse
 * @n: the number of elements in the array
 *
 * Description: This function reverses the order of elements
 * in the array so that the first becomes the last, and so on.
 */
void reverse_array(int *a, int n)
{
int i, temp;

for (i = 0; i < n / 2; i++)
{
temp = a[i];
a[i] = a[n - 1 - i];
a[n - 1 - i] = temp;
}
}
