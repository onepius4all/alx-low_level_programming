#include "main.h"
#include <stdio.h>
#include <stdlib.h>
char *create_buffer(char *file);
void close_file(int fd);

/**
* create_buffer - Allocates_1024_bytes for a buffer
* @file: The name of the file_buffer is storing chars for
*
* Return: Pointer to the newly-allocated_buffer
*/

char *create_buffer(char *file)

{
char *buffer;
buffer = malloc(sizeof(char) * 1024);
if (buffer == NULL)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", file);
exit(99);
}
return (buffer);
}

/**
* close_file - Close file descriptors
* @f: The file descriptor to be closed.
*/

void close_file(int f)
{
int c;
c = close(f);
if (c == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close f %d\n", f);
exit(100);
}

}

/**
* main - Copy the content of file to another file.
* @argc: The number of argument supplied to a program.
* @argv: Array of pointer to the arguments.
*
* Return: 0 on success
*
* Description: If the argument count is incorrect - exit code 97.
*              If file_from does not exist - exit code 98.
*              If file_to cannot be created - exit code 99.
*              If file_to or file_from cannot be close - exit code 100.
*/

int main(int argc, char *argv[])

{
int from, to, r, w;
char *buffer;
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
buffer = create_buffer(argv[2]);
from = open(argv[1], O_RDONLY);
r = read(from, buffer, 1024);
to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
do {
if (from == -1 || r == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}
w = write(to, buffer, r);
if (to == -1 || w == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", argv[2]);
free(buffer);
exit(99);
}
r = read(from, buffer, 1024);
to = open(argv[2], O_WRONLY | O_APPEND);
} while (r > 0);
free(buffer);
close_file(from);
close_file(to);
return (0);
}
