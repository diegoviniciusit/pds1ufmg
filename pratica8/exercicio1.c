#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomNumber(int limit)
{
    return (rand() % limit) + 1;
}

void populateArray(int m, int n, int v[][n], int limit)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            v[i][j] = randomNumber(limit);
        }
    }
}

int main()
{
    int m, n, k;
    printf("Digite o numero de linhas (1-100) ");
    scanf("%d", &m);
    if (m > 100 || m < 1) {
        return 0;
    }
    printf("Digite o numero de colunas (1-100) ");
    scanf("%d", &n);
    if (n > 100 || n < 1) {
        return 0;
    }
    printf("Digite o limite maximo do numero aleatorio (1-100) ");
    scanf("%d", &k);
    if (k > 100 || k < 1) {
        return 0;
    }
    srand(time(NULL));
    int v[m][n];
    populateArray(m, n, v, k);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", v[i][j]); 
        }
        printf("\n");
    }
    return 0;
}
