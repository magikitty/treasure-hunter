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
    int getLevelNumber() const;
    Gem getGem();
    MagicApple getMagicApple();
    Monster getMonster();
    int getNumberOfObjectsToAdd(Map &map);
    void makeNewMap(Player &player);
    void setLevel(int levelNumber);
    void selectAndPrintLevel(Player &player, int levelCurrent);
};


#endif //TREASURE_HUNTER_LEVELMANAGER_H
