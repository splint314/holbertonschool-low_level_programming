#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * close_fd - closes a file descriptor and handles errors
 * @fd: the file descriptor
 */
void close_fd(int fd)
{
if (close(fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
 * copy_file - copies the content of one file descriptor to another
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @file_from: source file name (for error messages)
 * @file_to: destination file name (for error messages)
 */
void copy_file(int fd_from, int fd_to, char *file_from, char *file_to)
{
ssize_t r, w;
char buffer[BUFFER_SIZE];

while ((r = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
w = write(fd_to, buffer, r);
if (w == -1 || w != r)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
close_fd(fd_from);
close_fd(fd_to);
exit(99);
}
}
if (r == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
close_fd(fd_from);
close_fd(fd_to);
exit(98);
}
}

/**
 * main - copy content of a file to another file
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
int fd_from, fd_to;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close_fd(fd_from);
exit(99);
}

copy_file(fd_from, fd_to, argv[1], argv[2]);
close_fd(fd_from);
close_fd(fd_to);

return (0);
}
