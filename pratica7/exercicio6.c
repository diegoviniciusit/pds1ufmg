#include <stdio.h>
#include <stdlib.h>
#define LIMIT 60

int randomNumber(int size)
{
    return rand() % (size + 1);
}

int inArray(int x, int v[], int n) {
    for (int i = 0; i < n; i++) {
        if (x == v[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int x[LIMIT];
    int y[LIMIT];
    int z[LIMIT];
    for (int i = 0; i < LIMIT; i++) {
        x[i] = randomNumber(365);
        y[i] = randomNumber(365);
    }
    for (int i = 0, n = 0; i < LIMIT; i++) {
        if (i == 0 || inArray(x[i], z, n) == 0) {
            printf("%d ", x[i]);
            z[n] = x[i];
            n++;
        }
        if (inArray(y[i], z, n) == 0) {
            printf("%d ", y[i]);
            z[n] = y[i];
            n++;
        }
    }
    return 0;
}