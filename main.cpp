// Elina Widdowson
// Programming Languages 2

#include <iostream>
#include "Dungeon.h"

using namespace std;

string getUserInputString(string message);

int main() {
    cout << "Welcome to Treasure Hunter!" << endl;
    string namePlayer = getUserInputString("Enter your name: ");
    cout << "Hello " << namePlayer << "!" << endl;

    Dungeon dungeon(10, 7);
    dungeon.printDungeon();

    return 0;
}

string getUserInputString(string message) {
    string userInput;
    cout << message;
    getline(cin, userInput);
    return userInput;
}
