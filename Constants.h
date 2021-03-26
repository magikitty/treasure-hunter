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

#endif //TREASURE_HUNTER_CONSTANTS_H