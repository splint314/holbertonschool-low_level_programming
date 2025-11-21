#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - performs simple operations
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: 0 on success, specific error codes otherwise
 */
int main(int argc, char *argv[])
{
    int (*f)(int, int);

    if (argc != 4)
    {
        printf("Error\n");
        exit(98);
    }

    f = get_op_func(argv[2]);
    if (f == NULL)
    {
        printf("Error\n");
        exit(99);
    }

    if ((argv[2][0] == '/' || argv[2][0] == '%') && atoi(argv[3]) == 0)
    {
        printf("Error\n");
        exit(100);
    }

    printf("%d\n", f(atoi(argv[1]), atoi(argv[3])));
    return (0);
}
