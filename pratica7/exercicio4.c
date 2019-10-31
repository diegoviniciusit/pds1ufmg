#include <stdio.h>
#include <stdlib.h>

void intercalacao(){
  int i = 0;
  int cont_x = 0;
  int cont_y = 0;
  //criar vetor Z de 20 elementos
  int z[19];
  //gerar 2 vetores X e Y de 10 elementos com valores aleatórios
  //imprimir os vetores X e Y para teste
  int x[9];
  int y[9];

  for(i = 0; i <= 9; i++){
    x[i] = rand()%10;
    printf("x - %d\n", x[i]);
  }
  printf("\n");
  for(i = 0; i <= 9; i++){
    y[i] = rand()%10;
    printf("y - %d\n", y[i]);
  }
  printf("\n");
  //colocar os elementos de X nas posições impares de Z
  //colocar os elementos de Y nas posições pares de Z
  //imprimir o vetor Z
  for(i = 0; i <= 19; i++){
    if(i % 2 == 0){
      z[i] = y[cont_y];
      cont_y++;
    } else {
      z[i] = x[cont_x];
      cont_x++;
    }
    printf("z - %d\n", z[i]);
  }
}

int main(){
  intercalacao();
  return 0;
}
