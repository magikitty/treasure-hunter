// Elina Widdowson
// Programming Languages 2

#include "Monster.h"
#include <iostream>

Monster::Monster(int strength) {
    this->strength = strength;
    this->symbol = SYMBOL_MONSTER;
}

Monster::Monster(char symbol, int strength, int x, int y) : GameObject(symbol, x, y) {
    this->strength = strength;
}

Monster::Monster(int x, int y) : GameObject(x, y) {}

Monster::Monster(char symbol, int x, int y) : GameObject(symbol, x, y) {}

int Monster::getStrength() const {
    return this->strength;
}

void Monster::setStrength(int strength) {
    this->strength = strength;
}
