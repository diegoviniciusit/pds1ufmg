#include <stdio.h>
#include <stdlib.h>
#define MAX_FIBONACCI 80

void calcFibonacci(unsigned long long int n[], int size)
{
    n[0] = 1;
    n[1] = 1;
    for (int i = 2; i < size; i++) {
        n[i] = n[i - 1] + n[i - 2];
    }
}

int main()
{
    unsigned long long int fibonacci[MAX_FIBONACCI];
    calcFibonacci(fibonacci, MAX_FIBONACCI);
    int n;
    do {
        scanf("%d", &n);
        if (n <= 80 && n >= 0) {
            printf("%llu\n", fibonacci[n]);
        }
    } while (n <= 80 && n >= 0);
    return 0;
}