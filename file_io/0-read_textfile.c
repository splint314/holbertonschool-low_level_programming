#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - Read a file and display it on standard POSIX.
 * @filename: Name of the file to read
 * @letters: number and letters to read and display
 * * Return: the real number readed or displayed, or 0 if error.
 */


ssize_t read_textfile(const char *filename, size_t letters)

{
int fd;
char *buffer;
ssize_t octets_lus, octets_ecrits;

if (filename == NULL)
return (0);

buffer = malloc(sizeof(char) * letters);
if (buffer == NULL)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
{
free(buffer);
return (0);
}

octets_lus = read(fd, buffer, letters);
if (octets_lus == -1)
{
free(buffer);
close(fd);
return (0);
}

octets_ecrits = write(STDOUT_FILENO, buffer, octets_lus);

free(buffer);
close(fd);

if (octets_ecrits == -1 || octets_ecrits != octets_lus)
return (0);

return (octets_ecrits);
}
