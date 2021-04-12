// Elina Widdowson
// Programming Languages 2

#include "LevelManager.h"

int LevelManager::getLevel() const {
    return this->level.getLevelNumber();
}

void LevelManager::setLevel(int levelNumber) {
    this->level.setLevelNumber(levelNumber);
}

// Load new level or print current level
void LevelManager::selectAndPrintLevel(Player &player, int levelCurrent) {
    if (levelCurrent > this->getLevel()) {
        makeNewMap(player);
        this->setLevel(getLevel() + 1);
    }
    this->map.printMap();
}

// Create new map, add player and monster
void LevelManager::makeNewMap(Player &player) {
    Map mapNew(12, 8);

    mapNew.setCharAtPosition(player.getSymbol(),
                             player.getPosition().getX(),
                             player.getPosition().getY());

    this->level.addMonster(Monster('M', 50, 3, 5));
    mapNew.setCharAtPosition(
            this->level.getMonsters()[0].getSymbol(),
            this->level.getMonsters()[0].getPosition().getX(),
            this->level.getMonsters()[0].getPosition().getY());

    // TODO: modify after gems implemented (TESTING ENTRANCE)
    mapNew.addEntrance();

    this->map = mapNew;
}
