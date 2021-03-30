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

void Player::setName(std::string namePlayer) {
    this->name = namePlayer;
}

void Player::setEnergy(int energy) {
    this->energy = energy;
}

// Dummy function for determining how player moves
void Player::move(std::string action, Dungeon &dungeon) {
    int xPosition = this->getPosition().getX();
    int yPosition = this->getPosition().getY();
    Position oldPosition(xPosition, yPosition);
    Position newPosition;
    int currentPositionIndex = dungeon.getIndexAtPosition(xPosition, yPosition);

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
        std::cout << "You portal out of the dungeon!" << std::endl; // debugging
    } else {
        std::cout << "Invalid action" << std::endl; // debugging
    }

    // Check that player does not walk over wall
    if (dungeon.getCharAtPosition(newPosition) != dungeon.getSymbolWall()) {
        this->setPosition(newPosition);
        dungeon.setCharAtPosition(this->getSymbol(), this->getPosition());
        dungeon.setCharAtPosition(dungeon.getSymbolFloor(), oldPosition);
    } else {
        cout << "You can't walk through walls!" << endl; // debugging
    }
}
