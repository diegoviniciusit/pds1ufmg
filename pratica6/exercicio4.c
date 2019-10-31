#include <stdio.h>
#include <stdlib.h>

void main()
{
    char linha[128];
    printf("digite uma linha:\n");
    fgets(linha, 128, stdin);
    int i;
    for (i = 0; linha[i] != '\n'; i++);
    printf("tamanho: %d", i);
}