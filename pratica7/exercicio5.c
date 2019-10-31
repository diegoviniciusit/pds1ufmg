#include <stdio.h>
#include <stdlib.h>

void inverso(int n){
    int i = 0;
    int j = 0;
    int y[n];
    int x[n];
    //gerar n numeros aleatorios para o vetor X
    for(i = 0; i <= n; i++){
        x[i] = rand()%100;
        printf("x - %d\n", x[i]);
    }

    printf("\n");
    
    //reverter esses valores no vetor Y
    i = n;
    for(j = 0; j <= n; j++){
        y[j] = x[i];
        i--;
        printf("y - %d\n", y[j]);
    }
}

int main(){
    inverso(5);
    return 0;
}