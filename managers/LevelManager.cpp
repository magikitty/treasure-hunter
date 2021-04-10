// Elina Widdowson
// Programming Languages 2

#include "LevelManager.h"

LevelManager::LevelManager(int levelNumber) : level(levelNumber) {
    this->level = Level(levelNumber);
}

Dungeon LevelManager::loadLevel(Player &player) {
    // Instantiate dungeon and set Player character
    Dungeon dungeon(12, 7);
    dungeon.setCharAtPosition(player.getSymbol(), player.getPosition().getX(),
                              player.getPosition().getY());

    this->level.addMonster(Monster('M', 50, 3, 5));
    dungeon.setCharAtPosition(
            this->level.getMonsters()[0].getSymbol(),
            this->level.getMonsters()[0].getPosition().getX(),
            this->level.getMonsters()[0].getPosition().getY());

    return dungeon;
}
