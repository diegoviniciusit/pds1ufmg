#include <stdio.h>
#include <stdlib.h>
#define BUFFER_TAM 5    

void main()
{
    int contBuffer = 0;
    char c;
    char buffer[BUFFER_TAM];
    char *texto, *textoAux;
    do {
        c = getche();
        if (c == '\r') {
            c = '\n';
	        printf("\n");
        }
        if (contBuffer != BUFFER_TAM) {
            buffer[contBuffer] = c;
            contBuffer++;
        }
        if (contBuffer == BUFFER_TAM || c == '#') {
            textoAux = (char *) malloc(contBuffer * sizeof(char));
            contBuffer = 0;
        }
    } while (c != '#c');
}
