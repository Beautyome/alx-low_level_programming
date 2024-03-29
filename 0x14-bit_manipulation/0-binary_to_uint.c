#include "main.h"

/**
 * binary_to_uint - convert a binary number to unsigned int
 * @b: pointing to a string of 0 and 1 chars
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int a;
	unsigned int dec_val = 0;

	if (!b)
		return (0);

	for (a = 0; b[a] != '\0'; a++)
	{
		if (b[a] != '0' && b[a] != '1')
			return (0);
		dec_val = 2 * dec_val + (b[a] - '0');
	}

	return (dec_val);
}
