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
        this->player.setEnergy(this->player.getEnergy() - this->levelManager
                .getMovementCost());
        handlePlayerInteraction();

        if (this->player.getIsAtEntrance()) {
            this->levelCurrent++;
            this->player.setIsAtEntrance(false);
        }
    }
}

// Handle interaction based on which object's symbol player moved to on map
void GameManager::handlePlayerInteraction() {
    if (this->player.getSymbolInteractingWith() == this->levelManager
            .getMonster().getSymbol()) {
        handleInteractionWithMonster();
    } else if (this->player.getSymbolInteractingWith() == this->levelManager
            .getGem().getSymbol()) {
        handleInteractionWithGem();
    } else if (this->player.getSymbolInteractingWith() == this->levelManager
            .getMagicApple().getSymbol()) {
        handleInteractionWithMagicApple();
    } else if (this->player.getSymbolInteractingWith() == SYMBOL_ENTRANCE) {
        handleInteractionWithEntrance();
    }
}

// Handle player's interaction with monster
void GameManager::handleInteractionWithMonster() {
    cout << MESSAGE_FOUGHT_MONSTER << endl;
    int monsterStrength = this->levelManager.getMonster().getStrength();
    int energyPlayer = this->player.getEnergy() - monsterStrength;
    this->player.setEnergy(energyPlayer);
    this->player.setPoints(this->player.getPoints() + monsterStrength);
    this->eventLogger.addEvent(MESSAGE_FOUGHT_MONSTER);
}

// Handle player's interaction with gem
void GameManager::handleInteractionWithGem() {
    cout << MESSAGE_FOUND_GEM << endl;
    this->player.setFoundEntrance(true);
    this->player.setPoints(
            this->player.getPoints() +
            this->levelManager.getGem().getValue());
    this->eventLogger.addEvent(MESSAGE_FOUND_GEM);
}

// Handle player's interaction with magic apple
void GameManager::handleInteractionWithMagicApple() {
    cout << MESSAGE_FOUND_MAGIC_APPLE << endl;
    int energyRestored = this->levelManager.getMagicApple().getEnergyRestored();
    int energyPlayer = this->player.getEnergy() + energyRestored;
    this->player.setEnergy(energyPlayer);
    this->eventLogger.addEvent(MESSAGE_FOUND_MAGIC_APPLE);
}

// Handle player's interaction with entrance to new level
void GameManager::handleInteractionWithEntrance() {
    this->player.setIsAtEntrance(true);
    this->eventLogger.addEvent(
            MESSAGE_ENTERED_LEVEL + to_string(this->levelCurrent + 1));
}

// Print current level and player energy and points
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
            eventLogger.addEvent(MESSAGE_PORTALED);
            this->eventLogger.printEvents();
            quitGame();
        }
    } else if (this->player.getEnergy() < 1) {
        cout << MESSAGE_PLAYER_DEAD << endl;
        eventLogger.addEvent(MESSAGE_DIED);
        eventLogger.printEvents();
        quitGame();
    }
}

// Quit game
void GameManager::quitGame() const { exit(0); }
