#include <stdio.h>
#include <math.h>

float parteInteira(float x)
{
	return (float) (int) x;
}

float parteFracionaria(float x)
{
	return x - (int) x;
}

float divInts(int x, int y)
{
	return (float) x / (float) y;
}

void main ()
{
	float valor1 = -3.141592;
	float valor2 = 2.1569;
	float valor3 = 1.33;
	int valor4 = 1;
	int valor5 = 2;
	int valor6 = 3;
	int valor7 = 4;
	int valor8 = 5;
	int valor9 = 6;
	printf("Retornos da função parteInteira com os valores: %f = %f, %f = %f, %f = %f\n", valor1, parteInteira(valor1), valor2, parteInteira(valor2), valor3, parteInteira(valor3));
	printf("Retorno da função parteFracionaria com os valores: %f = %f, %f = %f, %f = %f\n", valor1, parteFracionaria(valor1), valor2, parteFracionaria(valor2), valor3, parteFracionaria(valor3));
	printf("Retorno da função divInts com os valores: %d / %d = %f, %d / %d = %f, %d / %d = %f\n", valor4, valor5, divInts(valor4, valor5), valor6, valor7, divInts(valor6, valor7), valor8, valor9, divInts(valor8, valor9));
}
