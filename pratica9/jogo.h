typedef struct {
    int id;
    int attack;
    int defense;
    int carism;
    int healthPoints;
} Warrior;

int rollDices();

void createWarrior(Warrior *w);

int bonusCarism(int carism);

void attack(Warrior *w1, Warrior *w2);