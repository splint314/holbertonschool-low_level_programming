#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 *
 * Return: pointer to new dog_t, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)

{
dog_t *d;
char *name_copy;
char *owner_copy;

d = malloc(sizeof(dog_t));
if (d == NULL)
return (NULL);

name_copy = malloc(strlen(name) + 1);
if (name_copy == NULL)
{
free(d);
return (NULL);
}
strcpy(name_copy, name);

owner_copy = malloc(strlen(owner) + 1);
if (owner_copy == NULL)
{
free(name_copy);
free(d);
return (NULL);
}
strcpy(owner_copy, owner);

d->name = name_copy;
d->age = age;
d->owner = owner_copy;

return (d);
}
