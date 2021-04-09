// Elina Widdowson
// Programming Languages 2

#include "Level.h"

Level::Level(int levelNum) {
    this->levelNumber = levelNum;
    this->levelMaxNumber = MAX_LEVEL;
}

int Level::getLevelNumber() const {
    return this->levelNumber;
}

void Level::setLevelNumber(int number) {
    this->levelNumber = number;
}

int Level::getMovementCost() const {
    return this->movementCost;
}

// Set movement cost to equal current level number
void Level::setMovementCost() {
    this->movementCost = this->getLevelNumber();
}
