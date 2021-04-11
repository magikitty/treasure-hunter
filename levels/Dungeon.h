// Elina Widdowson
// Programming Languages 2

#include "../helperClasses/Position.h"

#ifndef TREASURE_HUNTER_DUNGEON_H
#define TREASURE_HUNTER_DUNGEON_H


class Dungeon {
private:
    char symbolWall = '#';
    char symbolFloor = '.';
    char symbolEntrance;
    int width, height;
    char *dungeonMap;
public:
    Dungeon();
    Dungeon(int width, int height);
    ~Dungeon();
    char* makeDungeonMap();
    char getSymbolWall() const;
    char getSymbolFloor() const;
    int getWidth() const;
    int getHeight() const;
    void setWidth(int width);
    void setHeight(int height);
    void printDungeon();
    int getIndexAtPosition(int x, int y) const;
    char getCharAtPosition(int x, int y) const;
    char getCharAtPosition(Position position) const;
    void setCharAtPosition(char symbolToAdd, int x, int y);
    void setCharAtPosition(char symbolToAdd, Position position);
};


#endif //TREASURE_HUNTER_DUNGEON_H
