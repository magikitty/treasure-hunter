// Elina Widdowson
// Programming Languages 2

#include "../Constants.h"
#include "../gameObjects/Monster.h"
#include "vector"

#ifndef TREASURE_HUNTER_LEVEL_H
#define TREASURE_HUNTER_LEVEL_H


class Level {
private:
    int mapWidth, mapHeight;
    int movementCost;
    int levelNumber, levelMaxNumber;
    std::vector<Monster> monsters;
public:
    Level();
    int getMovementCost() const;
    void setLevelNumber(int number);
    int getLevelNumber() const;
    void setMovementCost(); // movement cost determined by level
    void addMonster(Monster monster);
    std::vector<Monster> getMonsters();
};


#endif //TREASURE_HUNTER_LEVEL_H
