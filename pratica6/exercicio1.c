#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int calculaFatorial(int n) {
    int fatorial = 1;
    for (int i = 2; i <= n; i++) {
        fatorial *= i;
    }
    return fatorial;
}

void main()
{
    float euler = 1;
    float termo = 1;
    int n = 1;
    float limit = pow(10, -6);
    while (termo > limit) {
        int fatorial = calculaFatorial(n);
        termo = (float) 1 / calculaFatorial(n);
        euler += termo;
        n++;
    }
    printf("%f", euler);
}
