#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringIgual(char str1[], char str2[])
{
    int ctr = 0;
    while (str1[ctr] == str2[ctr]){
        if (str1[ctr] == '\0' || str2[ctr] == '\0') {
            break;
        }
        ctr++;
    }
    if (str1[ctr] == '\0' && str2[ctr] == '\0') {
        printf("a");
        return 1;
    }
    return 0;
}

int ePalindromo(char texto[])
{
    char textoContrario[128];
    int i;
    for (i = 0; texto[i] != '\n'; i++);
    int n = 0;
    i -= 1;
    while (i >= 0) {
        textoContrario[n] = texto[i];
        n++;
        i--;
    }
    return stringIgual(texto, textoContrario);
}

void main()
{
    char texto[128];
    printf("digite uma linha:\n");
    fgets(texto, 128, stdin);
    char retorno;
    if (ePalindromo(texto) == 1) {
        retorno = 'S';
    } else {
        retorno = 'N';
    }
    printf("e palindromo? %c", retorno);
}