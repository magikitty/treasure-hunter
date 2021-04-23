// Elina Widdowson
// Programming Languages 2

#include "../Constants.h"
#include "../gameObjects/Monster.h"
#include "../gameObjects/Gem.h"
#include "../gameObjects/MagicApple.h"
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
    Gem gem;
    MagicApple magicApple;
    Monster monster;

public:
    Level();
    int getLevelNumber() const;
    int getMapHeight() const;
    int getMapWidth() const;
    int getMovementCost() const;

    void setLevelNumber(int number);
    void setMapHeight(int height);
    void setMapWidth(int width);
    void setMovementCost();

    void addGemsToVector(int numToAdd);
    void addMagicApplesToVector(int numToAdd);
    void addMonstersToVector(int numToAdd);
    std::vector<GameObject> getGems();
    std::vector<GameObject> getMagicApples();
    std::vector<GameObject> getMonsters();
    Monster getMonster();
    void setMonster(Monster monsterNew);
    Gem getGem();
    void setGem(Gem gemNew);
    MagicApple getMagicApple();
    void setMagicApple(MagicApple magicAppleNew);
};


#endif //TREASURE_HUNTER_LEVEL_H
