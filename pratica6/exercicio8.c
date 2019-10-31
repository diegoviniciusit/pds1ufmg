#include <stdio.h>
#include <stdlib.h>

int main()
{
    char abreviacao[20];
    int n = 0;
    char c = '\0';
    for (int i = 0; c != '.'; i++) {
        c = getc(stdin);
        if (c >= 65 && c <= 90) {
            abreviacao[n] = c;
            n++;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%c.", abreviacao[i]);
    }
    return 0;
}