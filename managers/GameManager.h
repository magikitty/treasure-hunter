// Elina Widdowson
// Programming Languages 2

#include "../levels/Level.h"
#include <iostream>
#include "../Constants.h"
#include "../gameObjects/Player.h"
#include "../helperClasses/EventLogger.h"
#include "LevelManager.h"

#ifndef TREASURE_HUNTER_GAMEMANAGER_H
#define TREASURE_HUNTER_GAMEMANAGER_H


class GameManager {
private:
    int levelCurrent;
public:
    explicit GameManager(int levelNumber);
    void gameLoop(Player &player, Dungeon &dungeon, EventLogger &eventLogger);
    string getUserInput(string message);
    void checkShouldQuitGame(string playerAction, Player player, EventLogger eventLogger);
    void startGame();
    void quitGame() const;
};


#endif //TREASURE_HUNTER_GAMEMANAGER_H
