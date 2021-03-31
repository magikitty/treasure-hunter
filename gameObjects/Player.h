// Elina Widdowson
// Programming Languages 2

#include <iostream>
#include "GameObject.h"
#include "../helperClasses/Dungeon.h"

#ifndef TREASURE_HUNTER_PLAYER_H
#define TREASURE_HUNTER_PLAYER_H


class Player : public GameObject {
private:
    int energy;
    int points;
    std::string name;
public:
    Player();
    std::string getName() const;
    int getEnergy();
    int getPoints();
    void setName(std::string namePlayer);
    void setEnergy(int energy);
    void setPoints(int points);
    void move(std::string action, Dungeon &dungeon);
    void interact(GameObject gameObject);
};


#endif //TREASURE_HUNTER_PLAYER_H
