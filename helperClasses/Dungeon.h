// Elina Widdowson
// Programming Languages 2

#ifndef TREASURE_HUNTER_DUNGEON_H
#define TREASURE_HUNTER_DUNGEON_H


class Dungeon {
private:
    char symbolWall = '#';
    char symbolFloor = '.';
    char symbolEntrance;
    int width;
    int height;
    // pointer to a pointer to a char
    char **dungeonMap;
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
};


#endif //TREASURE_HUNTER_DUNGEON_H
