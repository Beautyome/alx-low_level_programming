#include <stdio.h>
#include <stdlib.h>

/**
 * main - print two two digits numbers
 * Return: Always 0
 */
int main(void)
{
	int a, n;

	for (a = 0; a < 100; a++)
	{
		for (n = 0; n < 100; n++)
		{
			if (a < n)
			{
				putchar((a / 10) + 48);
				putchar((a % 10) + 48);
				putchar(' ');
				putchar((n / 10) + 48);
				putchar((n % 10) + 48);
				if (a != 98 || n != 99)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}

	putchar('\n');
	return (0);
}
