// Elina Widdowson
// Programming Languages 2

#include "../helperClasses/Position.h"

#ifndef TREASURE_HUNTER_GAMEOBJECT_H
#define TREASURE_HUNTER_GAMEOBJECT_H


class GameObject {
protected:
    char symbol;
    Position position;
public:
    GameObject();
    explicit GameObject(char symbol);
    GameObject(char symbol, Position position);
    GameObject(char symbol, int x, int y);
    GameObject(int x, int y);
    char getSymbol() const;
    void setSymbol(char symbol);
    Position getPosition() const;
    void setPosition(int xPosition, int yPosition);
    void setPosition(Position position);
};

#endif //TREASURE_HUNTER_GAMEOBJECT_H
