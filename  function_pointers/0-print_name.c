#include "function_pointers.h"
#include <stddef.h>

/**
 * print_name - prints a name using a function
 * @name: name to print
 * @f: function to use
 */
void print_name(char *name, void (*f)(char *))
{
    if (name != NULL && f != NULL)
    {
        f(name);
    }
}