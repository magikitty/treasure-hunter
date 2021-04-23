// Elina Widdowson
// Programming Languages 2

#include <string>

using namespace std;


#ifndef TREASURE_HUNTER_CONSTANTS_H
#define TREASURE_HUNTER_CONSTANTS_H


/*****************************************************************************/
/* General Messages */
/*****************************************************************************/

const string MESSAGE_CONFIRM_QUIT = "Are you sure you want to quit the game? "
                                    "(y/n) ";
const string MESSAGE_ENTER_NAME = "Enter your name: ";
const string MESSAGE_GAME_HISTORY = "Here is a history of your game:";
const string MESSAGE_INSTRUCTIONS = "-Move by pressing w, a, s or d and enter."
                                    "\n-Moving consumes energy and if "
                                    "your energy reaches 0 the game ends.\n-You"
                                    " can get more energy by eating "
                                    "magic apples (A).\n-You can gain points by"
                                    " picking up gems (G) or fighting "
                                    "monsters (M).\n-Fighting monsters also"
                                    " consumes energy.\n-The entrance to "
                                    "the next level will appear after you pick"
                                    " up a gem.\n-Press p to portal out "
                                    "of the dungeon and end the game.\n";
const string MESSAGE_PLAYER_ACTION = "Enter action (wasd to move, p to "
                                     "portal out): ";
const string MESSAGE_PLAYER_DEAD = "You have run out of energy and perished "
                                   "in the dungeon. Game over.";
const string MESSAGE_PORTAL_OUT = "You portal out of the dungeon and so ends "
                                  "your treasure hunt. Game over.";
const string MESSAGE_WELCOME = "\nWelcome to Treasure Hunter!\n";

/*****************************************************************************/
/* Event Messages */
/*****************************************************************************/

const string MESSAGE_FOUND_GEM = "You picked up a gem!";
const string MESSAGE_FOUND_MAGIC_APPLE = "You picked up a magic apple!";
const string MESSAGE_FOUGHT_MONSTER = "You fought a monster!";

/*****************************************************************************/
/* Movement & player commands */
/*****************************************************************************/

const string MOVE_DOWN = "s";
const string MOVE_LEFT = "a";
const string MOVE_RIGHT = "d";
const string MOVE_UP = "w";
const string PORTAL_OUT = "p";
const string QUIT_YES = "y";

/*****************************************************************************/
/* Character symbols */
/*****************************************************************************/

const char SYMBOL_ENTRANCE = 'E';
const char SYMBOL_FLOOR = '.';
const char SYMBOL_GEM = 'G';
const char SYMBOL_MAGIC_APPLE = 'A';
const char SYMBOL_MONSTER = 'M';
const char SYMBOL_PLAYER = '@';
const char SYMBOL_WALL = '#';

/*****************************************************************************/
/* Game object constants */
/*****************************************************************************/

const int PLAYER_ENERGY_START = 100;
const string PLAYER_NAME_DEFAULT = "Treasure Hunter";
const int PLAYER_POINTS_START = 0;

/*****************************************************************************/
/* Level constants */
/*****************************************************************************/

const int LEVEL_MAX = 15;

#endif //TREASURE_HUNTER_CONSTANTS_H