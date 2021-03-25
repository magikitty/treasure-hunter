// Elina Widdowson
// Programming Languages 2

#include "Player.h"

std::string Player::getName() const {
    return this->name;
}

void Player::setName(std::string namePlayer) {
    this->name = namePlayer;
}
