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
