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

int Player::getEnergy() {
    return this->energy;
}

int Player::getPoints() {
    return this->points;
}

void Player::setName(std::string namePlayer) {
    this->name = namePlayer;
}

void Player::setEnergy(int energy) {
    this->energy = energy;
}

void Player::setPoints(int points) {
    this->points = points;
}

// Move player char to new map tile
void Player::move(std::string action, Map &map) {
    int xPosition = this->getPosition().getX();
    int yPosition = this->getPosition().getY();
    Position oldPosition(xPosition, yPosition);
    Position newPosition;

    if (action == MOVE_UP) {
        std::cout << "You move up!" << std::endl; // debugging
        newPosition = Position(xPosition, (yPosition - 1));
    } else if (action == MOVE_LEFT) {
        std::cout << "You move left!" << std::endl;  // debugging
        newPosition = Position((xPosition - 1), yPosition);
    } else if (action == MOVE_DOWN) {
        newPosition = Position(xPosition, (yPosition + 1));
        std::cout << "You move down!" << std::endl; // debugging
    } else if (action == MOVE_RIGHT) {
        newPosition = Position((xPosition + 1), yPosition);
        std::cout << "You move right!" << std::endl; // debugging
    } else if (action == PORTAL_OUT) {
        std::cout << "You portal out of the map!" << std::endl; // debugging
    } else {
        std::cout << "Invalid action" << std::endl; // debugging
    }

    // Check that player does not walk over wall
    if (map.getCharAtPosition(newPosition) != map.getSymbolWall()) {
        this->setPosition(newPosition);
        map.setCharAtPosition(this->getSymbol(), this->getPosition());
        map.setCharAtPosition(map.getSymbolFloor(), oldPosition);
    } else {
        cout << "You can't walk through walls!" << endl; // debugging
    }
}
