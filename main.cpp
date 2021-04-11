// Elina Widdowson
// Programming Languages 2

#include <iostream>
#include "managers/GameManager.h"

#include "levels/Dungeon.h"

using namespace std;

int main() {
    // Instantiate level manager
    LevelManager levelManager;
    // Instantiate event logger
    EventLogger eventLogger;
    // Instantiate player, set player name
    Player player;
    // Instantiate game manager
    GameManager gameManager(eventLogger, 1, levelManager, player);

    gameManager.startGame();

    return 0;
}
