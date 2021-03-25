// Elina Widdowson
// Programming Languages 2

#include <iostream>
#include "GameObject.h"

#ifndef TREASURE_HUNTER_PLAYER_H
#define TREASURE_HUNTER_PLAYER_H


class Player : public GameObject {
private:
    int energy;
    int points;
    std::string name;
public:
    std::string getName() const;
    void setName(std::string namePlayer);
    void move(std::string action);
};


#endif //TREASURE_HUNTER_PLAYER_H
