#include "main.h"

/**
* create_file -Function that Creates a file.
* @filename: Pointer to the name of the file create.
* @text_content: Pointer to a string to write to the file create.
*
* Return: If function error - -1.
*         else - 1.
*/

int create_file(const char *filename, char *text_content)

{
	int f, b, l = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}

	f = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	b = write(f, text_content, l);

	if (f == -1 || b == -1)
		return (-1);

	close(f);

	return (1);
}
