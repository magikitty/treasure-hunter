// Elina Widdowson
// Programming Languages 2

#include "GameManager.h"

using namespace std;

GameManager::GameManager() {
    this->eventLogger = EventLogger();
    this->levelCurrent = 1;
    this->levelManager = LevelManager();
    this->player = Player();
}

// TODO: write game instructions
// Start game by instantiating necessary game elements
[[noreturn]] void GameManager::startGame() {
    cout << MESSAGE_WELCOME << endl;

    player.setName(getUserInput(MESSAGE_ENTER_NAME));
    cout << "Hello " << player.getName() << "!" << endl;

    gameLoop(player, levelManager, eventLogger);
}

// Print message and returns user input
string GameManager::getUserInput(string message) {
    string userInput;
    cout << message;
    getline(cin, userInput);
    return userInput;
}

// Update the game each time player makes action
[[noreturn]] void
GameManager::gameLoop(Player &player, LevelManager &levelManager,
                      EventLogger &eventLogger) {
    while (true) {
        printPlayerStats(player);
        levelManager.selectAndPrintLevel(player, this->levelCurrent);
        string playerAction = getUserInput(MESSAGE_PLAYER_ACTION);
        checkShouldQuitGame(playerAction, player, eventLogger);
        player.move(playerAction, levelManager.dungeon);
    }
}

void GameManager::printPlayerStats(Player &player) const {
    cout << endl << "|| Energy: " << player.getEnergy() << " || Points: " <<
         player.getPoints() << " || Level: " << this->levelCurrent;
}

// Call to quit game if user portals out or runs out of energy
void GameManager::checkShouldQuitGame(
        string playerAction, Player player, EventLogger eventLogger) {
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

// TODO: add confirmation for quit
// Quit game
void GameManager::quitGame() const { exit(0); }
