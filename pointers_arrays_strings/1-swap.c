#include <stdio.h>
#include "main.h"

/**
 * swap_int - swap the both integers
 *@a: is the first integer
 *@b: is the second integer
 */

void swap_int(int *a, int *b)
{
int test = *a;
*a = *b;
*b = test;
}
