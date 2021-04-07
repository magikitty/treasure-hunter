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
    void gameLoop();
    std::string getUserInput(std::string message);
    void loadLevel();
    void quitGame(string playerAction, Player player, EventLogger eventLogger);
    void startGame();
};


#endif //TREASURE_HUNTER_GAMEMANAGER_H
