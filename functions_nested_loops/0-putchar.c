#include "main.h"

/**
 * main - check the code for _putchar
 *
 * Return: Always 0.
 */
int main(void)
{
char text[] = "_putchar";
int i;

for (i = 0; text[i] != '\0'; i++)
_putchar(text[i]);
_putchar('\n');
return (0);
}
