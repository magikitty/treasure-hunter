// Elina Widdowson
// Programming Languages 2

#include "../Constants.h"

#ifndef TREASURE_HUNTER_LEVEL_H
#define TREASURE_HUNTER_LEVEL_H


class Level {
private:
    int mapWidth, mapHeight;
    int movementCost;
    int levelNumber, levelMaxNumber;
public:
    explicit Level(int levelNum);
    int getMovementCost() const;
    void setLevelNumber(int number);
    int getLevelNumber() const;
    void setMovementCost();
};


#endif //TREASURE_HUNTER_LEVEL_H
