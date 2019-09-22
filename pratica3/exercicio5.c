#include <stdio.h>
#include <stdlib.h>

unsigned long long fast_pow_2(int expoente)
{
	return (unsigned long long) 1 << expoente;
}

void main()
{
	unsigned long long x = fast_pow_2(63);
	x = x | ~x;
	printf("%llu", x);
}
