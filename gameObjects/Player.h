// Elina Widdowson
// Programming Languages 2

#include <iostream>
#include "GameObject.h"
#include "../levels/Map.h"

#ifndef TREASURE_HUNTER_PLAYER_H
#define TREASURE_HUNTER_PLAYER_H


class Player : public GameObject {
private:
    int energy;
    int points;
    std::string name;
    bool isAtEntrance = false;

public:
    Player();
    std::string getName() const;
    int getEnergy() const;
    int getPoints() const;
    bool getIsAtEntrance() const;
    void setName(std::string namePlayer);
    void setEnergy(int energy);
    void setPoints(int points);
    void setIsAtEntrance(bool playerIsAtEntrance);
    void move(std::string action, Map &map);
    void selectInteraction(char symbol);
};


#endif //TREASURE_HUNTER_PLAYER_H
