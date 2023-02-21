#include "main.h"

/**
 * print_alphabet_10 - prints 10 times the alphabet in lowercase
 */
void print_alphabetf10(void)
{
	int ten;
	char la;

	for (ten = 0; ten <= 9; ten++)
	{
		for (la = 'a'; la <= 'z'; la++)
			_putchar(la);
		_putchar('\n');
	}
}
