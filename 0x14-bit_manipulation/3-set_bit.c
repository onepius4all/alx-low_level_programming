#include "main.h"

/**
* set_bit - sets a bit at a given index to 1
* @b: pointer to the number to change
* @index: index of the bit to set to 1
*
* Return: 1 for success & -1 for failure
*/

int set_bit(unsigned long int *b, unsigned int index)

{
	if (index > 63)
		return (-1);
	*b = ((1UL << index) | *b);
	return (1);
}
