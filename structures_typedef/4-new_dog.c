#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 *
 * Return: length of s
 */
static int _strlen(char *s)
{
int len = 0;

if (s == NULL)
return (0);

while (s[len] != '\0')
len++;

return (len);
}

/**
 * _strcpy - copies a string from src to dest
 * @dest: destination buffer
 * @src: source string
 *
 * Return: dest
 */
static char *_strcpy(char *dest, char *src)
{
int i = 0;

if (dest == NULL || src == NULL)
return (dest);

while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';

return (dest);
}

/**
 * new_dog - creates a new dog
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 *
 * Return: pointer to new dog_t, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *d;
int len_name, len_owner;

if (name == NULL || owner == NULL)
return (NULL);

d = malloc(sizeof(dog_t));
if (d == NULL)
return (NULL);

len_name = _strlen(name);
len_owner = _strlen(owner);

d->name = malloc(sizeof(char) * (len_name + 1));
if (d->name == NULL)
{
free(d);
return (NULL);
}

d->owner = malloc(sizeof(char) * (len_owner + 1));
if (d->owner == NULL)
{
free(d->name);
free(d);
return (NULL);
}

_strcpy(d->name, name);
_strcpy(d->owner, owner);
d->age = age;

return (d);
}
