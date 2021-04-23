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
    void checkShouldQuitGame(string playerAction);
    [[noreturn]] void gameLoop();
    string getUserInput(string message) const;
    void handleInteractionWithEntrance();
    void handleInteractionWithGem();
    void handleInteractionWithMagicApple();
    void handleInteractionWithMonster();
    void handlePlayerInteraction();
    void printPlayerStats() const;
    [[noreturn]] void startGame();
    void quitGame() const;
};


#endif //TREASURE_HUNTER_GAMEMANAGER_H
