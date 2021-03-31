// Elina Widdowson
// Programming Languages 2

#ifndef TREASURE_HUNTER_GAME_H
#define TREASURE_HUNTER_GAME_H


class Game {
private:
    int levelCurrent, levelMax;
    int movementCost;
public:
    void loadLevel();
    void quitGame();
};


#endif //TREASURE_HUNTER_GAME_H
