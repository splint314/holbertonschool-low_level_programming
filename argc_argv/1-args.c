#include <stdio.h>

/**
 * main - prints the number of arguments passed into the program
 * @argc: number of arguments
 * @argv: array of arguments (unused)
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
(void) argv; /* to avoid unused variable warning */

printf("%d\n", argc - 1);
return (0);
}
