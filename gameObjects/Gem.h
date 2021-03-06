// Elina Widdowson
// Programming Languages 2

#include "GameObject.h"
#include "../Constants.h"

#ifndef TREASURE_HUNTER_GEM_H
#define TREASURE_HUNTER_GEM_H


class Gem : public GameObject {
private:
    int value;
public:
    Gem();
    explicit Gem(int value);
    Gem(char symbol, int value);
    int getValue() const;
    void setValue(int value);
};


#endif //TREASURE_HUNTER_GEM_H
