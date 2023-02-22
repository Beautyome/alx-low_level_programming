#include <stdio.h>

/**
 * main - Prints the first 50 fibonacci numbers, starting with 1 and 2
 * followed by a new line
 * Return: Always 0
 */
int main(void)
{
	long int i, j, k, sum;

	j = 1;

	k = 2;

	for (i = 1; i <= 50; ++i)
	{
		if (j != 20365011074)
		{
			printf("%ld, ", j);
		}
		else
		{
			prinff("%ld\n", j);
		}
		sum = j + k;
		j = k;
		k = sum;
	}
	return (0);

}
