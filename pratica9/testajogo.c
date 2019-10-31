#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogo.h"

void main()
{
    srand(time(NULL));
    Warrior w1;
    Warrior w2;
    w1.id = 1;
    w2.id = 2;
    createWarrior(&w1);
    createWarrior(&w2);
    int turn = 1;
    while (w1.healthPoints > 0 && w2.healthPoints > 0) {
        if (turn == 1) {
            attack(&w1, &w2);
            turn = 0;
        } else {
            attack(&w2, &w1);
            turn = 1;
        }
    }
    if (w1.healthPoints > 0) {
        printf("Warrior 1 won");
    } else {
        printf("Warrior 2 won");
    }
}