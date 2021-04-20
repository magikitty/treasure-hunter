// Elina Widdowson
// Programming Languages 2

#include "../Constants.h"
#include "../gameObjects/Monster.h"
#include "../gameObjects/Gem.h"
#include "vector"

#ifndef TREASURE_HUNTER_LEVEL_H
#define TREASURE_HUNTER_LEVEL_H


class Level {
private:
    int mapWidth = 11, mapHeight = 7;
    int movementCost;
    int levelNumber, levelMaxNumber;
    std::vector<GameObject> gems;
    std::vector<GameObject> monsters;
    std::vector<GameObject> magicApples;
    Monster monster;
    Gem gem;
public:
    Level();
    int getMapWidth() const;
    int getMapHeight() const;
    int getMovementCost() const;
    void setLevelNumber(int number);
    int getLevelNumber() const;
    void setMapWidth(int width);
    void setMapHeight(int height);
    void setMovementCost();
//    void addMonstersToVector(Monster monster, int numToAdd);
    void addMonstersToVector(int numToAdd);
    std::vector<GameObject> getMonsters();
//    void addGemsToVector(Gem gem, int numToAdd);
    void addGemsToVector(int numToAdd);
    std::vector<GameObject> getGems();
    Monster getMonster();
    void setMonster(Monster monsterNew);
    Gem getGem();
    void setGem(Gem gemNew);
};


#endif //TREASURE_HUNTER_LEVEL_H
