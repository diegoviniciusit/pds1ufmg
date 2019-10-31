#include <stdio.h>
#include <stdlib.h>

void inverterArray(char texto[], int i)
{
    char temp;
    for (int n = 0; n < i; n++, i--) {
        temp = texto[n];
        texto[n] = texto[i - 1];
        texto[i - 1] = temp;
    }
}

int main()
{
    char texto[1000];
    char c = '\0';
    int i;
    for (i = 0; c != '.'; i++) {
        c = getc(stdin);
        texto[i] = c;
    }
    inverterArray(texto, i);
    printf("\nO inverso e: %s", texto);
    return 0;
}