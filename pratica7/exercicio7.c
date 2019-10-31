#include <stdio.h>
#include <stdlib.h>
#define LIMIT 500000

int randomNumber(size) {
    return rand() % (size + 1);
}

void setRandomValues(int v[], int n)
{
    for (int i = 0; i < n; i++) {
        v[i] = randomNumber(999);
    }
}

void countElements(int v[], int vn, int z[], int zn)
{
    for (int i = 0; i < zn; i++) {
        z[i] = 0;
    }
    for (int i = 0; i < vn; i++) {
        z[v[i]] += 1;
    }
}

int difference(int v[], int n)
{
    int higherValue = 0;
    int lesserValue = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > higherValue) {
            higherValue = v[i];
        }
        if (v[i] != 0 && (v[i] < lesserValue || lesserValue == 0)) {
            lesserValue = v[i];
        }
    }
    return higherValue - lesserValue;
}

int main()
{
    srand(time(NULL));
    int v[LIMIT];
    int count[1000];
    setRandomValues(v, LIMIT);
    countElements(v, LIMIT, count, 1000);
    printf("\n%d", difference(count, 1000));
    return 0;
}