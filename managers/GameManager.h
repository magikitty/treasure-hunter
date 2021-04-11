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
    LevelManager levelManager;
    EventLogger eventLogger;
    Player player;
public:
    GameManager();

    [[noreturn]] void gameLoop(Player &player, LevelManager &levelManager, EventLogger
    &eventLogger);
    void printPlayerStats(Player &player) const;
    string getUserInput(string message);
    void checkShouldQuitGame(string playerAction, Player player, EventLogger
        eventLogger);

    [[noreturn]] void startGame();
    void quitGame() const;
};


#endif //TREASURE_HUNTER_GAMEMANAGER_H
