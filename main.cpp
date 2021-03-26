// Elina Widdowson
// Programming Languages 2

#include <iostream>
#include "Dungeon.h"
#include "Player.h"
#include "Constants.h"

using namespace std;

string getUserInputString(string message);
void gameLoop(Player player);
void loadLevel();
void quitGame(string playerAction);

int main() {
    cout << "Welcome to Treasure Hunter!" << endl;

    // Instantiate player, set player name
    Player player;
    player.setName(getUserInputString("Enter your name: "));
    cout << "Hello " << player.getName() << "!" << endl;

    while (!QUIT_GAME) {
        gameLoop(player);
    }

    return 0;
}

string getUserInputString(string message) {
    string userInput;
    cout << message;
    getline(cin, userInput);
    return userInput;
}

void gameLoop(Player player) {
    loadLevel();
    string playerAction;
    cout << MESSAGE_PLAYER_ACTION;
    getline(cin, playerAction);
    quitGame(playerAction);
    player.move(playerAction);
}

void loadLevel() {
    Dungeon dungeon(10, 7);
    dungeon.printDungeon();
}

void quitGame(string playerAction) {
    string quitInput;

    if (playerAction == PORTAL_OUT) {
        QUIT_GAME = true;
    }
}
