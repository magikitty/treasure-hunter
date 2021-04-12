// Elina Widdowson
// Programming Languages 2

#include "../helperClasses/Position.h"
#include "../Constants.h"

#ifndef TREASURE_HUNTER_DUNGEON_H
#define TREASURE_HUNTER_DUNGEON_H


class Map {
private:
    char symbolWall = SYMBOL_WALL;
    char symbolFloor = SYMBOL_FLOOR;
    char symbolEntrance = SYMBOL_ENTRANCE;
    int width, height;
    char *charMap;
public:
    Map();
    Map(int width, int height);
    ~Map();
    char* makeCharMap();
    void addEntrance();
    Map& operator= (const Map &map); // operator overload
    char getCharAtPosition(int x, int y) const;
    char getCharAtPosition(Position position) const;
    int getIndexAtPosition(int x, int y) const;
    Position getRandomPosition();
    char getSymbolWall() const;
    char getSymbolFloor() const;
    int getWidth() const;
    int getHeight() const;
    void printMap();
    void setWidth(int width);
    void setHeight(int height);
    void setCharAtPosition(char symbolToAdd, int x, int y);
    void setCharAtPosition(char symbolToAdd, Position position);
};


#endif //TREASURE_HUNTER_DUNGEON_H
