// Elina Widdowson
// Programming Languages 2

#include "LevelManager.h"

int LevelManager::getLevel() const {
    return this->level.getLevelNumber();
}

void LevelManager::setLevel(int levelNumber) {
    this->level.setLevelNumber(levelNumber);
}

void LevelManager::selectAndPrintLevel(Player &player, int
levelCurrent) {
    if (levelCurrent > this->getLevel()) {
        cout << "Making new level" << endl;
        dungeonNew = newDungeon(player);
        this->setLevel(getLevel() + 1);
    }
    dungeonNew.printDungeon();
}

Dungeon LevelManager::newDungeon(Player &player) {
    Dungeon dungeon(12, 7);

    dungeon.setCharAtPosition(player.getSymbol(),
                              player.getPosition().getX(),
                              player.getPosition().getY());

    this->level.addMonster(Monster('M', 50, 3, 5));
    dungeon.setCharAtPosition(
            this->level.getMonsters()[0].getSymbol(),
            this->level.getMonsters()[0].getPosition().getX(),
            this->level.getMonsters()[0].getPosition().getY());

    return dungeon;
};

Dungeon LevelManager::loadLevel(Player &player, int levelCurrent) {
    if (levelCurrent > this->getLevel()) {
        cout << "LOADING NEW LEVEL" << endl; // debugging
        cout << "current level is " << levelCurrent << " levelmanager level is "
        << this->getLevel() << endl;

        Dungeon dungeon(12, 7);

        dungeon.setCharAtPosition(player.getSymbol(), player.getPosition().getX(),
                                  player.getPosition().getY());

        this->level.addMonster(Monster('M', 50, 3, 5));
        dungeon.setCharAtPosition(
                this->level.getMonsters()[0].getSymbol(),
                this->level.getMonsters()[0].getPosition().getX(),
                this->level.getMonsters()[0].getPosition().getY());

        dungeon.printDungeon();

        this->setLevel(this->getLevel() + 1);

        return dungeon;
    }
}
