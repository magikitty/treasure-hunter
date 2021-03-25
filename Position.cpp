// Elina Widdowson
// Programming Languages 2

#include "Position.h"

Position::Position() {
    this->xCoordinate = 0;
    this->yCoordinate = 0;
}

Position::Position(int xPosition, int yPosition) {
    this->xCoordinate = xPosition;
    this->yCoordinate = yPosition;
}

void Position::setCoordinates(int xPosition, int yPosition) {
    this->xCoordinate = xPosition;
    this->yCoordinate = yPosition;
}

int Position::getX() const {
    return this->xCoordinate;
}

int Position::getY() const {
    return this->yCoordinate;
}

void Position::setX(int xPosition) {
    this->xCoordinate = xPosition;
}

void Position::setY(int yPosition) {
    this->yCoordinate = yPosition;
}
