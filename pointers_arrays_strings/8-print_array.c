#include <stdio.h>
#include "main.h"

/**
 * print_array - prints n elements of an array of integers
 * @a: pointer to the array
 * @n: number of elements to print
 *
 * Description: Prints the elements of an integer array separated by
 * a comma and a space
 */
void print_array(int *a, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);

        if (i != n - 1)
        {
            printf(", ");
        }
    }

    printf("\n");
}
