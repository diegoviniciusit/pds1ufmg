#include <stdio.h>
#include "estatistica.h"

int main ()
{
	printf("\n%f", cauchy(-2));
	printf("\n%f", gumbel(0, 0.5, 2));
	printf("\n%f", laplace(-6, -5, 4));
	return 0;
}
