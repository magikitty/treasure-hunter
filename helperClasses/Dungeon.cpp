// Elina Widdowson
// Programming Languages 2

#include <iostream>
#include "Dungeon.h"

Dungeon::Dungeon(int width, int height) {
    this->width = width;
    this->height = height;
    this->dungeonMap = new char[height * width];

    // Generate pseudo random number
    srand(time(NULL));

    // Add symbols for floor and walls to table
    for (int i = 0; i < (width * height); i++) {
        if (i < width || i % width == 0 || (i + 1) % width == 0 ||
            i == (width * height) - 1) {
            dungeonMap[i] = this->getSymbolWall();
        } else if (i == (width * (height - 1)) + 1) {
            for (int j = 0; j < width; j++) {
                dungeonMap[i] = this->getSymbolWall();
                i++;
            }
        } else {
            int numRandom = rand() % 100;
            if (numRandom < 10) {
                dungeonMap[i] = this->getSymbolWall();
            } else {
                dungeonMap[i] = this->getSymbolFloor();
            }
        }
    }
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
    int dungeonSize = this->height * this->width;

    for (int i = 0; i < dungeonSize; i++) {
        if (i != 0 && i % this->width == 0) {
            std::cout << std::endl;
        }
        std::cout << this->dungeonMap[i];
    }
    std::cout << std::endl;
}
