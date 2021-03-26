// Elina Widdowson
// Programming Languages 2

#include <iostream>
#include "helperClasses/Dungeon.h"
#include "gameObjects/Player.h"
#include "Constants.h"

using namespace std;

string getUserInputString(string message);
void gameLoop(Player &player);
void loadLevel();
void quitGame(string playerAction, Player player);

int main() {
    cout << MESSAGE_WELCOME << endl;

    // Instantiate player, set player name
    Player player;
    player.setName(getUserInputString(MESSAGE_ENTER_NAME));
    cout << "Hello " << player.getName() << "!" << endl;

    // Infinite loop is terminated by quitGame()
    while (true) {
        gameLoop(player);
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

void gameLoop(Player &player) {
    loadLevel();
    string playerAction;
    cout << MESSAGE_PLAYER_ACTION;
    getline(cin, playerAction);
    quitGame(playerAction, player);
    player.move(playerAction);
}

// TODO: prints new random map each time, need to keep same dungeon
// Sets up level to display to user
void loadLevel() {
    Dungeon dungeon(10, 7);
    dungeon.printDungeon();
}

// Quits game if user portals out
void quitGame(string playerAction, Player player) {
    string quitInput;

    if (playerAction == PORTAL_OUT) {
        cout << "Quitting game. Bye bye!" << endl; // debugging
        exit(0);
    } else if (player.getEnergy() == 0) {
        cout << "Player ran out of energy. Game Over." << endl; // debugging
        exit(0);
    }
}
