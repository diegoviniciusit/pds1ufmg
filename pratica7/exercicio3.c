#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ELEM 10

float randomFloat()
{
    return ((float) rand()) / ((float) RAND_MAX) * 20.0;
}

float averageValue(float v[], int size) {
    float average = 0;
    for (int i = 0; i < size; i++) {
        average += v[i];
    }
    return average / size;
}

int main()
{
    srand(time(NULL));
    float v[MAX_ELEM];
    for (int i = 0; i < MAX_ELEM; i++) {
        v[i] = randomFloat();
    }
    float average;
    average = averageValue(v, MAX_ELEM);
    printf("%f", average);
    return 0;
}