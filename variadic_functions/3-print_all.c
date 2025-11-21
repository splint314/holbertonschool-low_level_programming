#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/* helpers */
static void p_char(va_list *ap, char **sep)
{
printf("%s%c", *sep, va_arg(*ap, int));
*sep = ", ";
}

static void p_int(va_list *ap, char **sep)
{
printf("%s%d", *sep, va_arg(*ap, int));
*sep = ", ";
}

static void p_float(va_list *ap, char **sep)
{
printf("%s%f", *sep, va_arg(*ap, double));
*sep = ", ";
}

static void p_str(va_list *ap, char **sep)
{
char *s = va_arg(*ap, char *);

/* sans if / sans ternaire : si s est NULL, on le remplace */
(s == NULL) && (s = "(nil)");

printf("%s%s", *sep, s);
*sep = ", ";
}

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
typedef struct printer
{
char t;
void (*f)(va_list *, char **);
} printer_t;

/* dispatch table */

printer_t ops[4] = {
{'c', p_char},
{'i', p_int},
{'f', p_float},
{'s', p_str}
};

va_list ap;
unsigned int i = 0, j;
char *sep = "";

va_start(ap, format);

while (format && format[i])
{
j = 0;
while (j < 4 && ops[j].t != format[i])
j++;

if (j < 4)
ops[j].f(&ap, &sep);

i++;
}

printf("\n");
va_end(ap);
}
