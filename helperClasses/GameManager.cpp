// Elina Widdowson
// Programming Languages 2

#include "GameManager.h"

using namespace std;

// Prints message and returns user input
string GameManager::getUserInput(string message) {
        string userInput;
        cout << message;
        getline(cin, userInput);
        return userInput;
}

void GameManager::startGame() {
    cout << MESSAGE_WELCOME << endl;

    // Instantiate player, set player name
    Player player;
    player.setName(getUserInput(MESSAGE_ENTER_NAME));
    cout << "Hello " << player.getName() << "!" << endl;

    // Instantiate event logger
    EventLogger eventLogger;
    // Set game level to 1
    this->level.setLevelNumber(1);
    // Instantiate dungeon and set Player character
    Dungeon dungeon(12, 7);
    dungeon.setCharAtPosition(player.getSymbol(), player.getPosition().getX(),
                              player.getPosition().getY());

    // Infinite loop is terminated by quitGame()
    while (true) {
        gameLoop(player, dungeon, eventLogger);
    }
}

void GameManager::gameLoop(Player &player, Dungeon &dungeon, EventLogger &eventLogger) {
    cout << endl << "|| Energy: " << player.getEnergy() << " || Points: " <<
         player.getPoints() << " ||";

    loadLevel(dungeon, player);
    string playerAction;
    cout << MESSAGE_PLAYER_ACTION;
    getline(cin, playerAction);
    quitGame(playerAction, player, eventLogger);
    player.move(playerAction, dungeon);
}

void GameManager::loadLevel(Dungeon &dungeon, Player player) {
    dungeon.printDungeon();
}

// Quits game if user portals out or runs out of energy
void GameManager::quitGame(string playerAction, Player player, EventLogger eventLogger) {
    if (playerAction == PORTAL_OUT) {
        cout << MESSAGE_PORTAL_OUT << endl;
        eventLogger.printEvents();
        exit(0);
    } else if (player.getEnergy() == 0) {
        cout << MESSAGE_PLAYER_DEAD << endl;
        eventLogger.printEvents();
        exit(0);
    }
}
