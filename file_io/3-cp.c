#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * close_fd - closes a file descriptor
 * @fd: file descriptor
 *
 * Return: nothing, exits on error
 */
void close_fd(int fd)
{
if (close(fd) == -1)
{
dprintf(2, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
 * copy_loop - reads and writes between files
 * @fd1: source file descriptor
 * @fd2: destination file descriptor
 * @av: argument vector
 *
 * Return: nothing, exits on error
 */
void copy_loop(int fd1, int fd2, char **av)
{
ssize_t r, w;
char buf[1024];

while ((r = read(fd1, buf, 1024)) > 0)
{
w = write(fd2, buf, r);
if (w == -1 || w != r)
{
dprintf(2, "Error: Can't write to %s\n", av[2]);
close_fd(fd1);
close_fd(fd2);
exit(99);
}
}
if (r == -1)
{
dprintf(2, "Error: Can't read from file %s\n", av[1]);
close_fd(fd1);
close_fd(fd2);
exit(98);
}
}

/**
 * main - copies a file to another file
 * @ac: number of arguments
 * @av: arguments
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
int fd1, fd2;

if (ac != 3)
{
dprintf(2, "Usage: cp file_from file_to\n");
exit(97);
}

fd1 = open(av[1], O_RDONLY);
if (fd1 == -1)
{
dprintf(2, "Error: Can't read from file %s\n", av[1]);
exit(98);
}

fd2 = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (fd2 == -1)
{
dprintf(2, "Error: Can't write to %s\n", av[2]);
close_fd(fd1);
exit(99);
}

copy_loop(fd1, fd2, av);

close_fd(fd1);
close_fd(fd2);

return (0);
}
