// Elina Widdowson
// Programming Languages 2

#include "Gem.h"

Gem::Gem(int value) {
    this->value = value;
}

Gem::Gem(char symbol, int value) : GameObject(symbol) {
    this->value = value;
}

int Gem::getValue() const {
    return this->value;
}

void Gem::setValue(int value) {
    this->value = value;
}
