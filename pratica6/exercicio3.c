#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n;
    int lastNumber = 0;
    int printNumber = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printNumber += i;
        while (lastNumber < printNumber) {
            lastNumber++;
            printf("%d ", lastNumber);
        }
        printf("\n");
    }
}