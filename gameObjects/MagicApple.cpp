// Elina Widdowson
// Programming Languages 2

#include "MagicApple.h"

MagicApple::MagicApple() {
    this->energyRestored = 1;
    this->symbol = SYMBOL_MAGIC_APPLE;
}

MagicApple::MagicApple(int energyRestored) {
    this->energyRestored = energyRestored;
    this->symbol = SYMBOL_MAGIC_APPLE;
}

int MagicApple::getEnergyRestored() const {
    return this->energyRestored;
}

void MagicApple::setEnergyRestored(int energyRestored) {
    this->energyRestored = energyRestored;
}
