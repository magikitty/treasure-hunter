// Elina Widdowson
// Programming Languages 2

#include "Player.h"
#include <iostream>
#include "../Constants.h"

Player::Player() {
    this->setSymbol('@');
    this->energy = 100;
    this->name = "Treasure Hunter";
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
void Player::move(std::string action) {
    if (action == MOVE_UP) {
        std::cout << "You move up!" << std::endl;
    } else if (action == MOVE_LEFT) {
        std::cout << "You move left!" << std::endl;
    } else if (action == MOVE_DOWN) {
        std::cout << "You move down!" << std::endl;
    } else if (action == MOVE_RIGHT) {
        std::cout << "You move right!" << std::endl;
    } else if (action == PORTAL_OUT) {
        std::cout << "You portal out of the dungeon!" << std::endl;
    } else {
        std::cout << "Invalid action" << std::endl;
    }
}
