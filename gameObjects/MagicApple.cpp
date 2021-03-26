// Elina Widdowson
// Programming Languages 2

#include "MagicApple.h"

MagicApple::MagicApple(char symbol, int energyRestored) : GameObject(symbol) {
    this->energyRestored = energyRestored;
}

int MagicApple::getEnergyRestored() const {
    return this->energyRestored;
}

void MagicApple::setEnergyRestored(int energyRestored) {
    this->energyRestored = energyRestored;
}
