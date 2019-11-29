#include <stdio.h>
#include <stdlib.h>

void popularMatriz(float **m, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = 0.0;
        }
    }
}

void imprimirMatriz(float **m, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int n;
    float **m;
    scanf("%d", &n);
    m = (float **) malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        m[i] = (float *) malloc(n * sizeof(float));
    }
    popularMatriz(m, n);
    imprimirMatriz(m, n);
}
