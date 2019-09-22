#include <stdio.h>
#include <math.h>
#include "pratica4.h"

void main()
{
    float height;
    float weight;
    char gender;
    printf("Digite sua altura: ");
    scanf("%f", &height);
    printf("\nDigite seu peso: ");
    scanf("%f", &weight);
    printf("\nDigite seu sexo (M ou F): ");
    getchar();
    scanf("%c", &gender);
    float idealWeight = pesoIdeal(height, gender);
    if (idealWeight == weight) {
        printf("\nParabens, voce esta no peso ideal");
    } else if(weight > idealWeight) {
        printf("\nVoce deve perder %f kgs para entrar no peso ideal", weight - idealWeight);
    } else {
        printf("\nVoce deve ganhar %f kgs para entrar no peso ideal", idealWeight - weight);
    }
}
