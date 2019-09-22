#include <stdio.h>

void main()
{
	int x = 0;
	int *y = &x;
	*y = 3;
	printf("%d", x);
}
