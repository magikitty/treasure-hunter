// Elina Widdowson
// Programming Languages 2

#include "Level.h"
#include <iostream>
#include "../Constants.h"
#include "../gameObjects/Player.h"
#include "EventLogger.h"

#ifndef TREASURE_HUNTER_GAMEMANAGER_H
#define TREASURE_HUNTER_GAMEMANAGER_H


class GameManager {
private:
    Level level;
public:
    explicit GameManager(int levelNumber);
    void gameLoop(Player &player, Dungeon &dungeon, EventLogger &eventLogger);
    string getUserInput(string message);
    void loadLevel(Dungeon &dungeon);
    void quitGame(string playerAction, Player player, EventLogger eventLogger);
    void startGame();
};


#endif //TREASURE_HUNTER_GAMEMANAGER_H
