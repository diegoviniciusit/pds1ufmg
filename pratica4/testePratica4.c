#include <stdio.h>
#include <math.h>
#include "pratica4.h"

void main()
{
    printf("1.5 km/h em m/s: %f\n", paraMetrosPorSegundo((float) 1.5));
    printf("Area do circulo de raio 4.5: %f\n", areaCirculo((float) 4.5));
    printf("E par - 2: %d, 3: %d\n", ePar(2), ePar(3));
    printf("Divisivel por 3 ou 5 (ou exclusivo) - 15: %d, 9: %d\n", eDivisivelPor3ou5(15), eDivisivelPor3ou5(9));
    printf("Peso ideal - Homem com altura 1.79m: %f, Mulher com altura 1.64m: %f\n", pesoIdeal(1.79, 'M'), pesoIdeal(1.64, 'F'));
    printf("Soma de impares - Ate 15: %d, Ate 37: %d\n", somaImpares(15), somaImpares(37));
    printf("Fatorial - De 10: %f, De 22: %f\n", fatorial(10.0), fatorial(22.0));
    printf("Soma dos numeros divisiveis por 3 ou 5 (ou exclusivo) ate 26: %d\n", somaNumerosDiv3ou5(26));
    printf("Media de 2, 3, 4 - Geometrica: %f, Ponderada: %f, Harmonica: %f, Aritmetica: %f\n", calculaMedia(2, 3, 4, 1), calculaMedia(2, 3, 4, 2), calculaMedia(2, 3, 4, 3), calculaMedia(2, 3, 4, 4));
    printf("Numero de divisores - De 10: %d, De 25: %d\n", numeroDivisores(10), numeroDivisores(25));
    printf("Enesimo numero de Fibonacci, N = 5: %d, N = 15: %d\n", enesimoFibonacci(5), enesimoFibonacci(15));
}