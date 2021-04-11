// Elina Widdowson
// Programming Languages 2

#include "Level.h"

Level::Level() {
    this->levelNumber = 0;
    this->levelMaxNumber = MAX_LEVEL;
    this->mapHeight = 0;
    this->mapWidth = 0;
    this->movementCost = 1;
    this->monsters = std::vector<Monster>();
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

std::vector<Monster> Level::getMonsters() {
    return this->monsters;
}

void Level::addMonster(Monster monster) {
    this->monsters.push_back(monster);
}