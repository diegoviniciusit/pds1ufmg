#include <stdio.h>

void main()
{
	float x, y;
	scanf("%f %f", &x, &y);
	float foo = x;
	x = y;
	y = foo;
	printf("\nx = %f\ny = %f", x, y);
}
