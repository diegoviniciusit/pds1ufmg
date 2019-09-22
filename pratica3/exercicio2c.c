#include <stdio.h>

void soma1(int *x)
{
	*x = *x + 1;
}

void main()
{
	int x = 0;
	soma1(&x);
	soma1(&x);
	soma1(&x);
	printf("%d", x);
}
