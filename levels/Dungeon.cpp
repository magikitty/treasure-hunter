// Elina Widdowson
// Programming Languages 2

#include <iostream>
#include "Dungeon.h"

Dungeon::Dungeon() {
    this->width = 1;
    this->height = 1;
    this->dungeonMap = new char[height * width]{'X'};
}

Dungeon::Dungeon(int width, int height) {
    this->width = width;
    this->height = height;
    this->dungeonMap = makeDungeonMap();

//    this->dungeonMap = new char[height * width];
//
//    // Generate pseudo random number
//    srand(time(NULL));
//
//    // Add symbols for floor and walls to dungeon map
//    for (int i = 0; i < (width * height); i++) {
//        if (i < width || i % width == 0 || (i + 1) % width == 0 ||
//            i == (width * height) - 1) {
//            dungeonMap[i] = this->symbolWall;
//        } else if (i == (width * (height - 1)) + 1) {
//            for (int j = 0; j < width; j++) {
//                dungeonMap[i] = this->symbolWall;
//                i++;
//            }
//        } else {
//            int numRandom = rand() % 100;
//            if (numRandom < 10) {
//                dungeonMap[i] = this->symbolWall;
//            } else {
//                dungeonMap[i] = this->symbolFloor;
//            }
//        }
//    }
}

char * Dungeon::makeDungeonMap() {
    dungeonMap = new char[height * width];

    // Generate pseudo random number
    srand(time(NULL));

    // Add symbols for floor and walls to dungeon map
    for (int i = 0; i < (width * height); i++) {
        if (i < width || i % width == 0 || (i + 1) % width == 0 ||
            i == (width * height) - 1) {
            dungeonMap[i] = this->symbolWall;
        } else if (i == (width * (height - 1)) + 1) {
            for (int j = 0; j < width; j++) {
                dungeonMap[i] = this->symbolWall;
                i++;
            }
        } else {
            int numRandom = rand() % 100;
            if (numRandom < 10) {
                dungeonMap[i] = this->symbolWall;
            } else {
                dungeonMap[i] = this->symbolFloor;
            }
        }
    }

    return dungeonMap;
}

Dungeon::~Dungeon() {
    delete[] this->dungeonMap;
}

char Dungeon::getSymbolFloor() const {
    return this->symbolFloor;
}

char Dungeon::getSymbolWall() const {
    return this->symbolWall;
}

int Dungeon::getWidth() const {
    return this->width;
}

int Dungeon::getHeight() const {
    return this->height;
}

void Dungeon::setWidth(int width) {
    this->width = width;
}

void Dungeon::setHeight(int height) {
    this->height = height;
}

void Dungeon::printDungeon() {
    int mapSize = this->height * this->width;
    std::cout << std::endl;

    for (int i = 0; i < mapSize; i++) {
        if (i != 0 && i % this->width == 0) {
            std::cout << std::endl;
        }
        std::cout << this->dungeonMap[i];
    }
    std::cout << std::endl;
}

int Dungeon::getIndexAtPosition(int x, int y) const {
    return (x + (this->getWidth() * y));
}

char Dungeon::getCharAtPosition(int x, int y) const {
    return this->dungeonMap[this->getIndexAtPosition(x, y)];
}

char Dungeon::getCharAtPosition(Position position) const {
    return this->dungeonMap[this->getIndexAtPosition(
            position.getX(),
            position.getY())];
}

void Dungeon::setCharAtPosition(char symbolToAdd, int x, int y) {
    this->dungeonMap[this->getIndexAtPosition(x, y)] = symbolToAdd;
}

void Dungeon::setCharAtPosition(char symbolToAdd, Position position) {
    this->dungeonMap[this->getIndexAtPosition(position.getX(), position.getY())]
            = symbolToAdd;
}
