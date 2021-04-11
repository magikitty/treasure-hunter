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
        newDungeon(player);
        this->setLevel(getLevel() + 1);
    }
    this->dungeon.printDungeon();
}

// Create new dungeon, add player and monster
void LevelManager::newDungeon(Player &player) {
    Dungeon dungeonNew(12, 8);

    dungeonNew.setCharAtPosition(player.getSymbol(),
                                 player.getPosition().getX(),
                                 player.getPosition().getY());

    this->level.addMonster(Monster('M', 50, 3, 5));
    dungeonNew.setCharAtPosition(
            this->level.getMonsters()[0].getSymbol(),
            this->level.getMonsters()[0].getPosition().getX(),
            this->level.getMonsters()[0].getPosition().getY());

    this->dungeon = dungeonNew;
}