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
// Instantiate necessary game elements
[[noreturn]] void GameManager::startGame() {
    cout << MESSAGE_WELCOME << endl;

    player.setName(getUserInput(MESSAGE_ENTER_NAME));
    cout << "Hello " << player.getName() << "!" << endl;

    gameLoop();
}

// Print message to player and return user input
string GameManager::getUserInput(string message) {
    string userInput;
    cout << message;
    getline(cin, userInput);
    return userInput;
}

// Update the game each time player performs action
[[noreturn]] void
GameManager::gameLoop() {
    while (true) {
        printPlayerStats();
        this->levelManager.selectAndPrintLevel(this->player, this->levelCurrent);
        string playerAction = getUserInput(MESSAGE_PLAYER_ACTION);
        checkShouldQuitGame(playerAction);
        this->player.move(playerAction, this->levelManager.map);

        if (this->player.getIsAtEntrance()) {
            this->levelCurrent++;
            this->player.setIsAtEntrance(false);
        }
    }
}

void GameManager::printPlayerStats() const {
    cout << endl << "|| Energy: " << this->player.getEnergy() << " || Points: " <<
         this->player.getPoints() << " || Level: " << this->levelCurrent;
}

// Quit game if user portals out or runs out of energy
void GameManager::checkShouldQuitGame(string playerAction) {
    if (playerAction == PORTAL_OUT) {
        cout << MESSAGE_PORTAL_OUT << endl;
        this->eventLogger.printEvents();
        quitGame();
    } else if (this->player.getEnergy() == 0) {
        cout << MESSAGE_PLAYER_DEAD << endl;
        eventLogger.printEvents();
        quitGame();
    }
}

// TODO: add confirmation for quit
// Quit game
void GameManager::quitGame() const { exit(0); }
