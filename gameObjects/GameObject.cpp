// Elina Widdowson
// Programming Languages 2

#include "GameObject.h"

GameObject::GameObject() {
    this->symbol = '.';
    this->position = Position{0, 0};
}

GameObject::GameObject(char symbol) {
    this->symbol = symbol;
}

GameObject::GameObject(char symbol, Position position) {
    this->symbol = symbol;
    this->position = position;
}

GameObject::GameObject(int x, int y) {
    this->position.setX(x);
    this->position.setY(y);
}

GameObject::GameObject(char symbol, int x, int y) {
    this->symbol = symbol;
    this->position.setX(x);
    this->position.setY(y);
}

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
