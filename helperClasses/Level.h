// Elina Widdowson
// Programming Languages 2

#ifndef TREASURE_HUNTER_LEVEL_H
#define TREASURE_HUNTER_LEVEL_H


class Level {
private:
    int mapWidth, mapHeight;
    int movementCost;
    int levelNumber, levelMaxNumber;
public:
    int getMovementCost();
    void setLevelNumber(int number);
    int getLevelNumber();
};


#endif //TREASURE_HUNTER_LEVEL_H
