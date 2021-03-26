#include <string>
using namespace std;


#ifndef TREASURE_HUNTER_CONSTANTS_H
#define TREASURE_HUNTER_CONSTANTS_H


/*****************************************************************************/
/* Messages */
/*****************************************************************************/

const string MESSAGE_PLAYER_ACTION = "Enter action (wasd to move, p to portal"
                                     " out): ";

/*****************************************************************************/
/* Movement & player commands */
/*****************************************************************************/

const string MOVE_UP = "w";
const string MOVE_LEFT = "a";
const string MOVE_DOWN = "s";
const string MOVE_RIGHT = "d";
const string PORTAL_OUT = "p";


#endif //TREASURE_HUNTER_CONSTANTS_H