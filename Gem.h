// Elina Widdowson
// Programming Languages 2

#include "GameObject.h"

#ifndef TREASURE_HUNTER_GEM_H
#define TREASURE_HUNTER_GEM_H


class Gem : public GameObject {
private:
    int value;
public:
    Gem(int value);
    Gem(char symbol, int value);
    int getValue() const;
    void setValue(int value);
};


#endif //TREASURE_HUNTER_GEM_H
