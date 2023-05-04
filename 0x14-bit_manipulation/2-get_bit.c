#include "main.h"

/**
 * get_bit - returns the value of a bit at an index in a decimal number
 * @n: decimal number to search
 * @index: Starting from 0 the bit you want to get
 *
 * Return: The value of the bit at index or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
