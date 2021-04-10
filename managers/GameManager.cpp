// Elina Widdowson
// Programming Languages 2

#include "GameManager.h"

using namespace std;

GameManager::GameManager(int levelNumber) {
    this->levelCurrent = levelNumber;
}

// TODO: write game instructions
// Start game by instantiating necessary game elements
void GameManager::startGame() {
    cout << MESSAGE_WELCOME << endl;

    // Instantiate player, set player name
    Player player;
    player.setName(getUserInput(MESSAGE_ENTER_NAME));
    cout << "Hello " << player.getName() << "!" << endl;

    // Instantiate level manager
    LevelManager levelManager(1);

    // Instantiate event logger
    EventLogger eventLogger;

    // Load level with dungeon
    Dungeon dungeon = levelManager.loadLevel(player);

    // Infinite loop is terminated by checkShouldQuitGame()
    while (true) {
        gameLoop(player, dungeon, eventLogger);
    }
}

// Print message and returns user input
string GameManager::getUserInput(string message) {
    string userInput;
    cout << message;
    getline(cin, userInput);
    return userInput;
}

// Update the game each time player makes action
void GameManager::gameLoop(Player &player, Dungeon &dungeon,
                           EventLogger &eventLogger) {
    cout << endl << "|| Energy: " << player.getEnergy() << " || Points: " <<
         player.getPoints() << " || Level: " << this->levelCurrent;

    dungeon.printDungeon();
    string playerAction = getUserInput(MESSAGE_PLAYER_ACTION);
    checkShouldQuitGame(playerAction, player, eventLogger);
    player.move(playerAction, dungeon);
}

// TODO: add confirmation for quit
// Call to quit game if user portals out or runs out of energy
void GameManager::checkShouldQuitGame(string playerAction, Player player, EventLogger
eventLogger) {
    if (playerAction == PORTAL_OUT) {
        cout << MESSAGE_PORTAL_OUT << endl;
        eventLogger.printEvents();
        quitGame();
    } else if (player.getEnergy() == 0) {
        cout << MESSAGE_PLAYER_DEAD << endl;
        eventLogger.printEvents();
        quitGame();
    }
}

// Quit game
void GameManager::quitGame() const { exit(0); }
