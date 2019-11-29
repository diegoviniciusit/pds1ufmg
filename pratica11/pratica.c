#include <stdio.h>
#include <stdlib.h>

void troca(int m[], int i, int j)
{
    int aux = m[i];
    m[i] = m[j];
    m[j] = aux;
}

void ordenarMatriz(int m[])
{
    int chave;
    for (int i = 0; i < 6; i++) {
        chave = i;
        for (int j = i + 1; j < 6; j++) {
            if (m[j] < m[chave]) {
                chave = j;
            }
        }
        if (m[i] > m[chave]) {
            troca(m, i, chave);
        }
    }
}

int validarCartelaVencedora(int m[])
{
    ordenarMatriz(m);
    if (m[0] == 6 && m[1] == 9 && m[2] == 22 && m[3] == 23 && m[4] == 48 && m[5] == 52) {
        return 1;
    }
    return 0;
}

int validarCartelaLost(int m[])
{
    if (m[0] == 4 && m[1] == 8 && m[2] == 15 && m[3] == 16 && m[4] == 23 && m[5] == 42) {
        return 1;
    }
    return 0;
}

void main()
{
    FILE *arq;
    arq = fopen("cartelas.txt", "r");
    int n, cartelaVencedora = 0, cartelaLost = 0, i = 0;
    int m[6];
    while (feof(arq) == 0) {
	    fscanf(arq, "%d", &n);
        m[i] = n;
        if (i == 5) {
            i = 0;
            cartelaVencedora += validarCartelaVencedora(m);
            cartelaLost += validarCartelaLost(m);
        } else {
            i++;
        }
    }
    printf("Cartelas vencedoras: %d\n", cartelaVencedora);
    printf("Cartelas lost: %d", cartelaLost);
    fclose(arq);
}
