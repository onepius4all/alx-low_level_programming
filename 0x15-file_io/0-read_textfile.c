#include "main.h"
#include <stdlib.h>

/**
* read_textfile- Read a text file & print to Standard Output.
* @filename: text file to be read
* @letters: number of letters ready for read
* Return: b- actual number of bytes read and printed
*        0 when function error.
*/

ssize_t read_textfile(const char *filename, size_t letters)

{
	char *buf;
	ssize_t f;
	ssize_t b;
	ssize_t r;

	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	r = read(f, buf, letters);
	b = write(STDOUT_FILENO, buf, r);
	free(buf);
	close(f);
	return (b);
}
