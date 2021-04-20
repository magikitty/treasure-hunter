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

// Instantiate necessary game elements
[[noreturn]] void GameManager::startGame() {
    cout << MESSAGE_WELCOME << endl;
    cout << MESSAGE_INSTRUCTIONS << endl;

    player.setName(getUserInput(MESSAGE_ENTER_NAME));
    cout << "Hello " << player.getName() << "!" << endl;

    gameLoop();
}

// Print message to player and return user input
string GameManager::getUserInput(string message) const {
    string userInput;
    cout << message;
    getline(cin, userInput);
    return userInput;
}

// Update the game each time player performs action
[[noreturn]] void GameManager::gameLoop() {
    while (true) {
        printPlayerStats();
        this->levelManager.selectAndPrintLevel(this->player,
                                               this->levelCurrent);
        string playerAction = getUserInput(MESSAGE_PLAYER_ACTION);
        checkShouldQuitGame(playerAction);
        this->player.move(playerAction, this->levelManager.map);
        handlePlayerInteraction();

        if (this->player.getIsAtEntrance()) {
            this->levelCurrent++;
            this->player.setIsAtEntrance(false);
        }
    }
}

// Handle interaction based on which object's symbol Player moved to on map
void GameManager::handlePlayerInteraction() {
    if (this->player.getSymbolInteractingWith() == this->levelManager
            .getMonster().getSymbol()) {
        cout << "You fought a monster!" << endl;
        int monsterStrength = this->levelManager.getMonster().getStrength();
        int energyPlayer = this->player.getEnergy() - monsterStrength;
        this->player.setEnergy(energyPlayer);
        this->player.setPoints(this->player.getPoints() + monsterStrength);
    } else if (this->player.getSymbolInteractingWith() == this->levelManager
            .getGem().getSymbol()) {
        cout << "You picked up a gem!" << endl;
        this->player.setPoints(
                this->player.getPoints() +
                this->levelManager.getGem().getValue());
    }
}

void GameManager::printPlayerStats() const {
    cout << endl << "|| Energy: " << this->player.getEnergy() << " || Points: "
         <<
         this->player.getPoints() << " || Level: " << this->levelCurrent;
}

// Quit game if user portals out or runs out of energy
void GameManager::checkShouldQuitGame(string playerAction) {
    if (playerAction == PORTAL_OUT) {
        string quitConfirmation = getUserInput(MESSAGE_CONFIRM_QUIT);
        if (quitConfirmation == QUIT_YES) {
            cout << MESSAGE_PORTAL_OUT << endl;
            this->eventLogger.printEvents();
            quitGame();
        }
    } else if (this->player.getEnergy() == 0) {
        cout << MESSAGE_PLAYER_DEAD << endl;
        eventLogger.printEvents();
        quitGame();
    }
}

// Quit game
void GameManager::quitGame() const { exit(0); }
