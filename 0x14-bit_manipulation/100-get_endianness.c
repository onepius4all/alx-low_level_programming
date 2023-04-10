#include "main.h"
/**
 * get_endianness - checks type of endian (big or small)
 * Return: 0 for big & 1 for small
 */
int get_endianness(void)
{
	unsigned int a = 1;
	char *d = (char *) &a;

	return (*d);
}
