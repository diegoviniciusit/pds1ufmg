#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogo.h"

int rollDices()
{
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += (rand() % 6) + 1;
    }
    return sum;
}

void createWarrior(Warrior *w)
{
    w->attack = rollDices();
    w->defense = rollDices();
    w->carism = rollDices();
    w->healthPoints = rollDices() + rollDices() + rollDices();
}

int bonusCarism(int carism)
{
    switch (carism) {
        case 18:
            return 3;
        case 17:
            return 2;
        case 16:
            return 2;
        case 14:
            return 1;
        case 15:
            return 1;
        case 7:
            return -1;
        case 6:
            return -1;
        case 5:
            return -2;
        case 4:
            return -2;
        case 3:
            return -3;
        default:
            return 0;
    }
}

void attack(Warrior *w1, Warrior *w2)
{
    int attack, defense, damage;
    attack = rollDices() + rollDices() + rollDices() + w1->attack + bonusCarism(w1->carism);
    defense = rollDices() + rollDices() + rollDices() + w2->defense + bonusCarism(w2->carism);
    damage = attack - defense;
    if (damage > 0) {
        w2->healthPoints = w2->healthPoints - damage;
    }
}
