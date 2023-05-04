#include "main.h"

/**
 * clear_bit - sets the value of a given bit to 0
 * @n: pointer to the index number to change
 * @index: index of the bit to set from 0
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
