// Elina Widdowson
// Programming Languages 2

#include "../levels/Level.h"
#include "../levels/Dungeon.h"
#include "../gameObjects/Player.h"

#ifndef TREASURE_HUNTER_LEVELMANAGER_H
#define TREASURE_HUNTER_LEVELMANAGER_H


class LevelManager {
private:
    Level level;
public:
    explicit LevelManager(int levelNumber);
    Dungeon loadLevel(Player &player);
};


#endif //TREASURE_HUNTER_LEVELMANAGER_H
