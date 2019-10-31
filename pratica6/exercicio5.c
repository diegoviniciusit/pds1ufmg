#include <stdio.h>
#include <stdlib.h>

void main()
{
    char linha[128];
    printf("digite uma linha:\n");
    fgets(linha, 128, stdin);
    char linhaNova[128];
    for (int i = 0; i < 128; i++) {
        if (linha[i] >= 97 && linha[i] <= 122) {
            linhaNova[i] = linha[i] - 32;
        } else {
            linhaNova[i] = linha[i];
        }
    }
    printf("%s", linhaNova);
}