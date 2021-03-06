// Elina Widdowson
// Programming Languages 2

#include "GameObject.h"
#include "../Constants.h"

#ifndef TREASURE_HUNTER_MONSTER_H
#define TREASURE_HUNTER_MONSTER_H


class Monster : public GameObject {
private:
    int strength;
public:
    Monster();
    explicit Monster(int strength);
    Monster(char symbol, int strength, int x, int y);
    Monster(int x, int y);
    Monster(char symbol, int x, int y);
    int getStrength() const;
    void setStrength(int strength);
};


#endif //TREASURE_HUNTER_MONSTER_H
