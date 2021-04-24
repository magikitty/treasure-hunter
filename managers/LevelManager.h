// Elina Widdowson
// Programming Languages 2

#include "../levels/Level.h"
#include "../levels/Map.h"
#include "../gameObjects/Player.h"
#include "../gameObjects/GameObject.h"
#include "../gameObjects/Monster.h"
#include "../gameObjects/Gem.h"
#include "../gameObjects/MagicApple.h"

#ifndef TREASURE_HUNTER_LEVELMANAGER_H
#define TREASURE_HUNTER_LEVELMANAGER_H


class LevelManager {
private:
    Level level;
    bool entranceIsAdded = false;
public:
    Map map;
    void addGameObjectsToMap(std::vector<GameObject> objects, Map &map);
    int getGameObjectValue(int extraValue) const;
    int getLevelNumber() const;
    Gem getGem();
    MagicApple getMagicApple();
    Monster getMonster();
    int getMovementCost() const;
    int getNumberOfObjectsToAdd(Map &map);
    void makeNewMap(Player &player);
    void selectAndPrintLevel(Player &player, int levelCurrent);
    void setLevel(int levelNumber);
};


#endif //TREASURE_HUNTER_LEVELMANAGER_H
