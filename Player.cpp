// Elina Widdowson
// Programming Languages 2

#include "Player.h"
#include <iostream>

std::string Player::getName() const {
    return this->name;
}

void Player::setName(std::string namePlayer) {
    this->name = namePlayer;
}

// Dummy function for determining how player moves
void Player::move(std::string action) {
    if (action == "w") {
        std::cout << "You move up!" << std::endl;
    } else if (action == "a") {
        std::cout << "You move left!" << std::endl;
    } else if (action == "s") {
        std::cout << "You move down!" << std::endl;
    } else if (action == "d") {
        std::cout << "You move right!" << std::endl;
    } else if (action == "p") {
        std::cout << "You portal out of the dungeon!" << std::endl;
    } else {
        std::cout << "Invalid action" << std::endl;
    }
}
