#include <stdlib.h>
#include <stdio.h>

void main ()
{
	float a = 3.14159, b = 2.71828;
	float c;
	c = b;
	b = a;
	a = c;
	printf("\nPI = %f", b);
	printf("\nEULER = %f", a);
}
