// Elina Widdowson
// Programming Languages 2

#include "GameObject.h"

#ifndef TREASURE_HUNTER_MAGICAPPLE_H
#define TREASURE_HUNTER_MAGICAPPLE_H


class MagicApple : public GameObject {
private:
    int energyRestored;
public:
    MagicApple(char symbol, int energyRestored);
    int getEnergyRestored() const;
    void setEnergyRestored(int energyRestored);
};


#endif //TREASURE_HUNTER_MAGICAPPLE_H
