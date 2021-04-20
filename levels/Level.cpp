// Elina Widdowson
// Programming Languages 2

#include "Level.h"

Level::Level() {
    this->levelNumber = 0;
    this->levelMaxNumber = LEVEL_MAX;
    this->movementCost = 1;
}

int Level::getLevelNumber() const {
    return this->levelNumber;
}

void Level::setLevelNumber(int number) {
    this->levelNumber = number;
}

int Level::getMapHeight() const {
    return this->mapHeight;
}

int Level::getMapWidth() const {
    return this->mapWidth;
}

int Level::getMovementCost() const {
    return this->movementCost;
}

void Level::setMapHeight(int height) {
    this->mapHeight = height;
}

void Level::setMapWidth(int width) {
    this->mapWidth = width;
}

// Movement cost to equal current level number
void Level::setMovementCost() {
    this->movementCost = this->getLevelNumber();
}

std::vector<GameObject> Level::getMonsters() {
    return this->monsters;
}

// TODO: delete
// Add specified number of monster objects to monsters vector
//void Level::addMonstersToVector(Monster monster, int numToAdd) {
//    for (int i = 0; i < numToAdd; i++) {
//        this->monsters.push_back(monster);
//    }
//}

// Add specified number of monster objects to monsters vector
void Level::addMonstersToVector(int numToAdd) {
    for (int i = 0; i < numToAdd; i++) {
        this->monsters.push_back(this->monster);
    }
}

// Add specified number of gem objects to gems vector
//void Level::addGemsToVector(Gem gem, int numToAdd) {
//    for (int i = 0; i < numToAdd; i++) {
//        this->gems.push_back(gem);
//    }
//}

void Level::addGemsToVector(int numToAdd) {
    for (int i = 0; i < numToAdd; i++) {
        this->gems.push_back(this->gem);
    }
}

std::vector<GameObject> Level::getGems() {
    return this->gems;
}

Monster Level::getMonster() {
    return this->monster;
}

void Level::setMonster(Monster monsterNew) {
    this->monster = monsterNew;
}

Gem Level::getGem() {
    return this->gem;
}

void Level::setGem(Gem gemNew) {
    this->gem = gemNew;
}