#include <string>
using namespace std;

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

/*****************************************************************************/
/* Quitting game (quit game if QUIT_GAME bool is true) */
/*****************************************************************************/

bool QUIT_GAME = false;