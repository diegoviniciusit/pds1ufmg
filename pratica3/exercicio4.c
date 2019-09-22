#include <stdio.h>

void troca(float *x, float *y) {
	float foo = *x;
	*x = *y;
	*y = foo;
}

void main()
{
	float x, y;
	scanf("%f %f", &x, &y);
	troca(&x, &y);
	printf("\nx = %f\ny = %f", x, y);
}
