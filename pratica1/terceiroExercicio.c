#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main ()
{
	float poupanca = 789.54;
	float rendimento = 1.0056;
	poupanca = poupanca * rendimento;
	poupanca += 303.2;
	poupanca = poupanca * rendimento;
	poupanca -= 58.25;
	poupanca = poupanca * rendimento;
	printf("%f", poupanca);
}
