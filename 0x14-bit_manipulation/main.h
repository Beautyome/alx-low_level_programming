#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
int get_endianness(void);
unsigned int binary_to_uint(const char *b);
int _atoi(const char *s);
unsigned int flip_bits(unsigned long int n, unsigned long int m);
int set_bit(unsigned long int *n, unsigned int index);
int clear_bit(unsigned long int *n, unsigned int index);
int get_bit(unsigned long int n, unsigned int index);
void print_binary(unsigned long int n);

#endif
