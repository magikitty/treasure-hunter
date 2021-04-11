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
    Dungeon dungeonNew; // TODO refactor with getter-setter
    int getLevel() const;
    Dungeon newDungeon(Player &player);
    void setLevel(int levelNumber);
    void selectAndPrintLevel(Player &player, int levelCurrent);
    Dungeon loadLevel(Player &player, int levelCurrent);
};


#endif //TREASURE_HUNTER_LEVELMANAGER_H
