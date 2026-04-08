#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * create_file - Creates a file and writes text content into it.
 * @filename: The name of the file to create or truncate.
 * @text_content: A NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
int fd;
int length = 0;
ssize_t bytes_written;

if (filename == NULL)
return (-1);

fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
if (fd == -1)
return (-1);

if (text_content != NULL)
{
while (text_content[length])
length++;

bytes_written = write(fd, text_content, length);


if (bytes_written == -1 || bytes_written != length)
{
close(fd);
return (-1);
}
}

close(fd);
return (1);
}
