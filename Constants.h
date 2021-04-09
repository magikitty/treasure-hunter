// Elina Widdowson
// Programming Languages 2

#include <string>
using namespace std;


#ifndef TREASURE_HUNTER_CONSTANTS_H
#define TREASURE_HUNTER_CONSTANTS_H


/*****************************************************************************/
/* Messages */
/*****************************************************************************/

const string MESSAGE_PLAYER_ACTION = "Enter action (wasd to move, p to portal"
                                     " out): ";
const string MESSAGE_WELCOME = "Welcome to Treasure Hunter!";
const string MESSAGE_ENTER_NAME = "Enter your name: ";
const string MESSAGE_PORTAL_OUT = "You portal out of the dungeon and so ends "
                                  "your treasure hunt. Game over.";
const string MESSAGE_PLAYER_DEAD = "You have run out of energy and perished "
                                   "in the dungeon. Game over.";
const string MESSAGE_GAME_HISTORY = "Here is a history of your game:";

/*****************************************************************************/
/* Movement & player commands */
/*****************************************************************************/

const string MOVE_UP = "w";
const string MOVE_LEFT = "a";
const string MOVE_DOWN = "s";
const string MOVE_RIGHT = "d";
const string PORTAL_OUT = "p";

/*****************************************************************************/
/* Game object constants */
/*****************************************************************************/

const char SYMBOL_PLAYER = '@';
const int PLAYER_ENERGY_START = 100;
const string PLAYER_NAME_DEFAULT = "Treasure Hunter";
const int PLAYER_POINTS_START = 0;

/*****************************************************************************/
/* Level constants */
/*****************************************************************************/

const int MAX_LEVEL = 15;

#endif //TREASURE_HUNTER_CONSTANTS_H