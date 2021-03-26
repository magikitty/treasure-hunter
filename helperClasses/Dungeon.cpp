// Elina Widdowson
// Programming Languages 2

#include <iostream>
#include "Dungeon.h"

Dungeon::Dungeon(int width, int height) {
    this->width = width;
    this->height = height;
    this->dungeonMap = new char *[height];

    // Make two dimensional array by adding an array to each element
    for (int i = 0; i < height; ++i) {
        dungeonMap[i] = new char[width];
    }

    // Add walls and floors to array
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == (height - 1) || j == 0 || j == (width - 1)) {
                dungeonMap[i][j] = this->getSymbolWall();
            } else {
                dungeonMap[i][j] = this->getSymbolFloor();
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
    for (int i = 0; i < this->getHeight(); i++) {
        for (int j = 0; j < this->getWidth(); j++) {
            std::cout << this->dungeonMap[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
