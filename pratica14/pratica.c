#include <stdio.h>
#include <stdlib.h>

int primeirosNCubos(int n)
{
    if (n == 1) {
        return 1;
    }
    return (n * n * n) + primeirosNCubos(n - 1);
}

void imprimeNaturaisCrescente(int n)
{
    if (n == 0) {
        printf("0 ");
        return;
    }
    imprimeNaturaisCrescente(n - 1);
    printf("%d ", n);
}

void imprimeNaturaisDecrescente(int n)
{
    if (n == 0) {
        printf("0 ");
        return;
    } else {
        printf("%d ", n);
    }
    imprimeNaturaisDecrescente(n - 1);
}

int media(int v[], int n, int tam)
{
    if (n == 0) {
        return 0;
    }
    return (v[n - 1] / (float) tam) + media(v, n - 1, tam);

}

void main()
{
    printf("%d ", primeirosNCubos(7));
    printf("\n");
    imprimeNaturaisCrescente(7);
    printf("\n");
    imprimeNaturaisDecrescente(7);
    printf("\n");
    int v[3];
    v[0] = 5;
    v[1] = 8;
    v[2] = 8;
    printf("%d ", media(v, 3, 3));
}
