// Elina Widdowson
// Programming Languages 2

#include "Player.h"
#include <iostream>
#include "../Constants.h"

Player::Player() : GameObject(SYMBOL_PLAYER) {
    this->energy = PLAYER_ENERGY_START;
    this->name = PLAYER_NAME_DEFAULT;
    this->points = PLAYER_POINTS_START;
    this->setPosition(Position(1, 1));
}

std::string Player::getName() const {
    return this->name;
}

int Player::getEnergy() const {
    return this->energy;
}

bool Player::getFoundEntrance() const {
    return this->foundEntrance;
}

char Player::getSymbolInteractingWith() const {
    return this->symbolInteractingWith;
}

bool Player::getIsAtEntrance() const {
    return this->isAtEntrance;
}

int Player::getPoints() const {
    return this->points;
}

void Player::setName(std::string namePlayer) {
    this->name = namePlayer;
}

void Player::setEnergy(int energy) {
    this->energy = energy;
}

// Set to true if player finds first gem in level
void Player::setFoundEntrance(bool foundEntrance) {
    this->foundEntrance = foundEntrance;
}

// Set bool for whether or not player is on entrance tile
void Player::setIsAtEntrance(bool playerIsAtEntrance) {
    this->isAtEntrance = playerIsAtEntrance;
}

// Set symbol player is currently interacting with
void Player::setSymbolInteractingWith(char symbolInteractingWith) {
    this->symbolInteractingWith = symbolInteractingWith;
}

void Player::setPoints(int points) {
    this->points = points;
}

// Move player char to new map tile
void Player::move(std::string action, Map &map) {
    this->symbolInteractingWith = SYMBOL_FLOOR;
    int xPosition = this->getPosition().getX();
    int yPosition = this->getPosition().getY();
    Position oldPosition(xPosition, yPosition);
    Position newPosition;

    if (action == MOVE_UP) {
        newPosition = Position(xPosition, (yPosition - 1));
    } else if (action == MOVE_LEFT) {
        newPosition = Position((xPosition - 1), yPosition);
    } else if (action == MOVE_DOWN) {
        newPosition = Position(xPosition, (yPosition + 1));
    } else if (action == MOVE_RIGHT) {
        newPosition = Position((xPosition + 1), yPosition);
    } else if (action == PORTAL_OUT) {
    } else {
        std::cout << MESSAGE_INVALID_ACTION << std::endl;
    }

    // Check that player does not walk over wall
    if (map.getCharAtPosition(newPosition) != map.getSymbolWall()) {
        if (map.getCharAtPosition(newPosition) != map.getSymbolFloor()) {
            this->symbolInteractingWith = map.getCharAtPosition(newPosition);
        }
        this->setPosition(newPosition);
        map.setCharAtPosition(this->getSymbol(), this->getPosition());
        map.setCharAtPosition(map.getSymbolFloor(), oldPosition);
    } else {
        cout << "You can't walk through walls!" << endl;
    }
}
