// Elina Widdowson
// Programming Languages 2

#include "GameObject.h"
#include "../Constants.h"

#ifndef TREASURE_HUNTER_MAGICAPPLE_H
#define TREASURE_HUNTER_MAGICAPPLE_H


class MagicApple : public GameObject {
private:
    int energyRestored;
public:
    MagicApple();
    MagicApple(int energyRestored);
    int getEnergyRestored() const;
    void setEnergyRestored(int energyRestored);
};


#endif //TREASURE_HUNTER_MAGICAPPLE_H
