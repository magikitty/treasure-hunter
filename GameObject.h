// Elina Widdowson
// Programming Languages 2

#include "Position.h"

#ifndef TREASURE_HUNTER_GAMEOBJECT_H
#define TREASURE_HUNTER_GAMEOBJECT_H


class GameObject {
protected:
    char symbol;
    Position position;
public:
    char getSymbol() const;
    void setSymbol(char symbol);
    Position getPosition() const;
    void setPosition(int xPosition, int yPosition);
    void setPosition(Position position);
};

#endif //TREASURE_HUNTER_GAMEOBJECT_H
