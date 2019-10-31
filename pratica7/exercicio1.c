#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ELEM_ARRANJO 50

int getRandomNumber(int size) {
    return rand() % size;
}

int main()
{
    srand(time(NULL));
    int u[MAX_ELEM_ARRANJO];
    int v[MAX_ELEM_ARRANJO];
    for (int i = 0; i < MAX_ELEM_ARRANJO; i++) {
        u[i] = getRandomNumber(100);
        v[i] = getRandomNumber(100);
    }
    int result = 0;
    for (int i = 0; i < MAX_ELEM_ARRANJO; i++) {
        result += u[i] * v[i];
    }
    printf("resultado: %d", result);
    return 0;
}
