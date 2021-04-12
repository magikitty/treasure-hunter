// Elina Widdowson
// Programming Languages 2

#include "../levels/Level.h"
#include "../levels/Map.h"
#include "../gameObjects/Player.h"

#ifndef TREASURE_HUNTER_LEVELMANAGER_H
#define TREASURE_HUNTER_LEVELMANAGER_H


class LevelManager {
private:
    Level level;
public:
    Map map; // TODO refactor with getter-setter
    int getLevel() const;
    void makeNewMap(Player &player);
    void setLevel(int levelNumber);
    void selectAndPrintLevel(Player &player, int levelCurrent);
};


#endif //TREASURE_HUNTER_LEVELMANAGER_H
