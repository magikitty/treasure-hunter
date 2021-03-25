// Elina Widdowson
// Programming Languages 2

#include "Position.h"

Position::Position() {
    this->xCoordinate = 0;
    this->yCoordinate = 0;
}

Position::Position(int xCoordinate, int yCoordinate) {
    this->xCoordinate = xCoordinate;
    this->yCoordinate = yCoordinate;
}

void Position::setCoordinates(int xCoordinate, int yCoordinate) {
    this->xCoordinate = xCoordinate;
    this->yCoordinate = yCoordinate;
}

int Position::getX() const {
    return this->xCoordinate;
}

int Position::getY() const {
    return this->yCoordinate;
}

void Position::setX(int xCoordinate) {
    this->xCoordinate = xCoordinate;
}

void Position::setY(int yCoordinate) {
    this->yCoordinate = yCoordinate;
}
