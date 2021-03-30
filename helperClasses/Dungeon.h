// Elina Widdowson
// Programming Languages 2

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
    Dungeon(int width, int height);
    ~Dungeon();
    char getSymbolWall() const;
    char getSymbolFloor() const;
    int getWidth() const;
    int getHeight() const;
    void setWidth(int width);
    void setHeight(int height);
    void printDungeon();
    char getCharAtPosition(int x, int y) const;
    void setCharAtPosition(char symbolToAdd, int x, int y);
};


#endif //TREASURE_HUNTER_DUNGEON_H
