#include "main.h"

/**
* append_text_to_file - Appends text at the end of file.
* @filename: Pointer to the name of a file.
* @text_content: The string to add to the end the file.
*
* Return: If function error or filename is NULL - -1.
*         If the file does not exist the user lacks write permissions - -1.
*         else - 1.
*/

int append_text_to_file(const char *filename, char *text_content)

{
	int y, b, l = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}

	y = open(filename, O_WRONLY | O_APPEND);
	b = write(y, text_content, l);

	if (y == -1 || b == -1)
		return (-1);

	close(y);

	return (1);
}
