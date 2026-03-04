#include "main.h"
#include <stdio.h>

/**
* swap_int swaps the value of 2 integers
* *a = address of the first integer
* *b = address of the second integer
*/

void swap_int(int *a, int *b)

{

int c;
c = *a;
*a = *b;
*b = c;

}
