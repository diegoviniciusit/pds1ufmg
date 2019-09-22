#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main ()
{
	float pesoBrutus = 122, pesoOlivia = 45, alturaBrutus = 1.84, alturaOlivia = 1.76;
	float imcBrutus = pesoBrutus / (alturaBrutus * alturaBrutus);
	float imcOlivia = pesoOlivia / (alturaOlivia * alturaOlivia);
	printf("O IMC de Brutus é: %.2f\nO IMC de Olívia é: %.2f", imcBrutus, imcOlivia);
	float pesoAPerderBrutus = 122 - (24.9 * (1.84 * 1.84));
	float pesoAPerderOlivia = (45 - (18.5 * (1.76 * 1.76)) ) * -1;
	printf("\nO Brutus deve perder no mínimo: %.2f\nA Olívia deve ganhar no mínimo: %.2f\n", pesoAPerderBrutus, pesoAPerderOlivia);
}
