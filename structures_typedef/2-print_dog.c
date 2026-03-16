#include "dog.h"
#include <stdio.h>
/**
 * print_dog - prints a struct dog
 * @d: pointer to struct dog to print
 * Description: This function prints a struct dog.
 * If an element of d is NULL, print (nil) instead of it.
 * If d is NULL, print nothing.
 */
void print_dog(struct dog *d)
{
if (d != NULL)
{
printf("Name: %s\n", d->name != NULL ? d->name : "(nil)");
printf("Age: %.6f\n", d->age);
printf("Owner: %s\n", d->owner != NULL ? d->owner : "(nil)");
}
}
