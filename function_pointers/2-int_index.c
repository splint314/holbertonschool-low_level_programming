#include "function_pointers.h"
#include <stdio.h>
#include <stddef.h>
/**
 * int_index - searches for an integer in an array using a comparison function
 * @array: array of integers
 * @size: size of the array
 * @cmp: pointer to the comparison function
 *
 * Return: the index of the first element for which cmp returns non-zero,
 *         or -1 if no such element is found or size <= 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
int i;
if (array == NULL || size <= 0 || cmp == NULL)
return (-1);
for (i = 0; i < size; i++)
{
if (cmp(array[i]))
return (i);
}
return (-1);
}
