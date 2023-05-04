#include "main.h"

/**
 * print_binary - prints the binary representation of a decimal number
 * @n: The decimal number to print
 */
void print_binary(unsigned long int n)
{
	int b, count = 0;
	unsigned long int current;

	for (b = 63; b >= 0; b--)
	{
		current = n >> b;

		if (current & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count > 0)
		{
			_putchar('0');
		}
	}
	if (count == 0)
	{
		_putchar('0');
	}
}
