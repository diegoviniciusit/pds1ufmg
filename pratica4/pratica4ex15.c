#include <stdio.h>
#include <math.h>
#include "pratica4.h"

void main()
{
    int n1;
    int n2;
    int invalidFirstNumber = 1;
    int invalidSecondNumber = 1;
    while (invalidFirstNumber == 1) {
        printf("Digite o primeiro numero maior que zero a seguir:\n");
        scanf("%d", &n1);
        if (n1 > 0) {
            invalidFirstNumber = 0;
        } else {
            printf("Numero invalido!\n");
        }
    }
    while (invalidSecondNumber == 1) {
        printf("Digite o segundo numero maior que zero a seguir:\n");
        scanf("%d", &n2);
        if (n2 > 0) {
            invalidSecondNumber = 0;
        } else {
            printf("Numero invalido!\n");
        }
    }
    printf("O MDC dos numeros %d e %d e: %d\n", n1, n2, mdc(n1, n2));
    printf("O MMC dos numeros %d e %d e: %d", n1, n2, mmc(n1, n2));
}
