// Elina Widdowson
// Programming Languages 2

#include <iostream>
#include "Map.h"

Map::Map() {
    this->width = 1;
    this->height = 1;
    this->charMap = new char[height * width]{'#'};
}

Map::Map(int width, int height) {
    this->width = width;
    this->height = height;
    this->charMap = makeCharMap();
}

char *Map::makeCharMap() {
    charMap = new char[height * width];

    // Generate pseudo random number
    srand(time(NULL));

    // Add symbols for floor and walls to map map
    for (int i = 0; i < (width * height); i++) {
        if (i < width || i % width == 0 || (i + 1) % width == 0 ||
            i == (width * height) - 1) {
            charMap[i] = this->symbolWall;
        } else if (i == (width * (height - 1)) + 1) {
            for (int j = 0; j < width; j++) {
                charMap[i] = this->symbolWall;
                i++;
            }
        } else {
            int numRandom = rand() % 100;
            if (numRandom < 10) {
                charMap[i] = this->symbolWall;
            } else {
                charMap[i] = this->symbolFloor;
            }
        }
    }
    return charMap;
}

void Map::addEntrance() {
    Position entrancePosition = getRandomPosition();
    setCharAtPosition(this->symbolEntrance, entrancePosition);
}

Map &Map::operator=(const Map &map) {
    this->width = map.getWidth();
    this->height = map.getHeight();
    this->charMap = new char[width * height];

    for (int i = 0; i < (width * height); i++) {
        this->charMap[i] = (map.charMap[i]);
    }
    return *this;
}

Map::~Map() {
    delete[] this->charMap;
}

char Map::getSymbolEntrance() const {
    return this->symbolEntrance;
}

char Map::getSymbolFloor() const {
    return this->symbolFloor;
}

char Map::getSymbolWall() const {
    return this->symbolWall;
}

int Map::getWidth() const {
    return this->width;
}

int Map::getHeight() const {
    return this->height;
}

// Return random position on map that contains floor symbol
Position Map::getRandomPosition() {
    Position randomPosition(0, 0);
    // Generate pseudo random number
    srand(time(NULL));
    int maxWidth = (this->width - 1);
    int maxHeight = (this->height - 1);

    // Get new position until character at position is floor symbol
    while(getCharAtPosition(randomPosition) != getSymbolFloor()) {
        int randomWidth = rand() % maxWidth;
        int randomHeight = rand() % maxHeight;
        randomPosition = Position(randomWidth, randomHeight);
    }
    return randomPosition;
}

void Map::setWidth(int width) {
    this->width = width;
}

void Map::setHeight(int height) {
    this->height = height;
}

void Map::printMap() {
    int mapSize = (this->height * this->width);
    std::cout << std::endl;

    for (int i = 0; i < mapSize; i++) {
        if (i != 0 && i % this->width == 0) {
            std::cout << std::endl;
        }
        std::cout << this->charMap[i];
    }
    std::cout << std::endl;
}

int Map::getIndexAtPosition(int x, int y) const {
    return (x + (this->getWidth() * y));
}

char Map::getCharAtPosition(int x, int y) const {
    return this->charMap[this->getIndexAtPosition(x, y)];
}

char Map::getCharAtPosition(Position position) const {
    return this->charMap[this->getIndexAtPosition(
            position.getX(),
            position.getY())];
}

void Map::setCharAtPosition(char symbolToAdd, int x, int y) {
    this->charMap[this->getIndexAtPosition(x, y)] = symbolToAdd;
}

void Map::setCharAtPosition(char symbolToAdd, Position position) {
    this->charMap[this->getIndexAtPosition(position.getX(), position.getY())]
            = symbolToAdd;
}
