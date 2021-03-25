// Elina Widdowson
// Programming Languages 2

#include "GameObject.h"

char GameObject::getSymbol() const {
    return this->symbol;
}

void GameObject::setSymbol(char symbol) {
    this->symbol = symbol;
}

Position GameObject::getPosition() const {
    return this->position;
}

void GameObject::setPosition(int xPosition, int yPosition) {
    this->position.setX(xPosition);
    this->position.setY(yPosition);
}

void GameObject::setPosition(Position position) {
    this->position = position;
}
