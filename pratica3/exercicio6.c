#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ddd(unsigned int x)
{
	return (x - (x % 100000000)) / 100000000;
}

int soma1SePar(unsigned int x)
{
	return 1 | x;
}

int parOuImpar(unsigned int x)
{
	return (1 & x) ^ 1;
}

void main()
{
	unsigned int valor1 = 3000000000;
	unsigned int valor2 = 3234095859;
	unsigned int valor3 = 3334095860;
	unsigned int valor4 = 1;
	unsigned int valor5 = 2;
	unsigned int valor6 = 3;
	printf("Retorno da função DDD com os valores: %u = %d, %u = %d, %u = %d\n", valor1, ddd(valor1), valor2, ddd(valor2), valor3, ddd(valor3));
	printf("Retorno da função soma1SePar: %u = %d, %u = %d, %u = %d\n", valor4, soma1SePar(valor4), valor5, soma1SePar(valor5), valor6, soma1SePar(valor6));
	printf("Retorno da função parOuImpar: %u = %d, %u = %d, %u = %d\n", valor4, parOuImpar(valor4), valor5, parOuImpar(valor5), valor6, parOuImpar(valor6));
}
