#include "main.h"
#include <stdio.h>

/**
 * main - prints numbers from 1 to 100 replacing multiples with Fizz/Buzz
 *
 * Return: Always 0.
 */
int main(void)
{
int n;
for (n = 1; n <= 100; n++)
{
if (n % 15 == 0)
printf("FizzBuzz");
else if (n % 5 == 0)
printf("Buzz");
else if (n % 3 == 0)
printf("Fizz");
else
printf("%d", n);
if (n < 100)
printf(" ");
}
printf("\n");
return (0);
}
