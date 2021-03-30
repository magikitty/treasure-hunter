// Elina Widdowson
// Programming Languages 2

#include <iostream>
#include "helperClasses/Dungeon.h"
#include "gameObjects/Player.h"
#include "Constants.h"
#include "helperClasses/EventLogger.h"

using namespace std;

string getUserInputString(string message);
void gameLoop(Player &player, Dungeon &dungeon, EventLogger &eventLogger);
void loadLevel(Dungeon &dungeon, Player player);
void quitGame(string playerAction, Player player, EventLogger eventLogger);

int main() {
    cout << MESSAGE_WELCOME << endl;

    // Instantiate player, set player name
    Player player;
    player.setName(getUserInputString(MESSAGE_ENTER_NAME));
    cout << "Hello " << player.getName() << "!" << endl;

    // Instantiate dungeon
    Dungeon dungeon(12, 9);

    // Instantiate event logger
    EventLogger eventLogger;

    // Infinite loop is terminated by quitGame()
    while (true) {
        gameLoop(player, dungeon, eventLogger);
    }

    return 0;
}

// Prints message and returns user input
string getUserInputString(string message) {
    string userInput;
    cout << message;
    getline(cin, userInput);
    return userInput;
}

void gameLoop(Player &player, Dungeon &dungeon, EventLogger &eventLogger) {
    loadLevel(dungeon, player);
    string playerAction;
    cout << MESSAGE_PLAYER_ACTION;
    getline(cin, playerAction);
    quitGame(playerAction, player, eventLogger);
    player.move(playerAction);
}

// Sets up level to display to user
void loadLevel(Dungeon &dungeon, Player player) {
    dungeon.printDungeon();
}

// Quits game if user portals out
void quitGame(string playerAction, Player player, EventLogger eventLogger) {

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
