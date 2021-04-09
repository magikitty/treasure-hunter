// Elina Widdowson
// Programming Languages 2

#include "GameManager.h"

using namespace std;

GameManager::GameManager(int levelNumber) : level(levelNumber) {
    this->level = Level(levelNumber);
}

// Print message and returns user input
string GameManager::getUserInput(string message) {
        string userInput;
        cout << message;
        getline(cin, userInput);
        return userInput;
}

// Start game by instantiating necessary game elements
void GameManager::startGame() {
    cout << MESSAGE_WELCOME << endl;

    // Instantiate player, set player name
    Player player;
    player.setName(getUserInput(MESSAGE_ENTER_NAME));
    cout << "Hello " << player.getName() << "!" << endl;

    // Instantiate event logger
    EventLogger eventLogger;
    // Instantiate dungeon and set Player character
    Dungeon dungeon(12, 7);
    dungeon.setCharAtPosition(player.getSymbol(), player.getPosition().getX(),
                              player.getPosition().getY());

    // Infinite loop is terminated by quitGame()
    while (true) {
        gameLoop(player, dungeon, eventLogger);
    }
}

// Update the game each time player makes action
void GameManager::gameLoop(Player &player, Dungeon &dungeon, EventLogger &eventLogger) {
    cout << endl << "|| Energy: " << player.getEnergy() << " || Points: " <<
         player.getPoints() << " || Level: " << this->level.getLevelNumber();

    dungeon.printDungeon();
    string playerAction = getUserInput(MESSAGE_PLAYER_ACTION);
    quitGame(playerAction, player, eventLogger);
    player.move(playerAction, dungeon);
}

// Quit game if user portals out or runs out of energy
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
