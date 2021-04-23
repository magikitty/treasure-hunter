// Elina Widdowson
// Programming Languages 2

#include "LevelManager.h"

// Get level number
int LevelManager::getLevelNumber() const {
    return this->level.getLevelNumber();
}

// Set level number
void LevelManager::setLevel(int levelNumber) {
    this->level.setLevelNumber(levelNumber);
}

// Load new or current level, print level
void LevelManager::selectAndPrintLevel(Player &player, int levelCurrent) {
    if (levelCurrent > this->getLevelNumber()) {
        makeNewMap(player);
        this->setLevel(getLevelNumber() + 1);
        this->level.setMovementCost(this->getLevelNumber());
    } else if (player.getFoundEntrance() == true && this->entranceIsAdded ==
    false) {
        this->map.addEntrance();
        this->entranceIsAdded = true;
    }
    this->map.printMap();
}

// Create new map, add all game objects (player, gems, magic apples, monsters)
void LevelManager::makeNewMap(Player &player) {
    this->entranceIsAdded = false;
    player.setFoundEntrance(false);
    this->level.setMapWidth(this->level.getMapWidth()+1);

    // Create new map
    Map mapNew(this->level.getMapWidth(), this->level.getMapHeight());

    // Add player symbol to map
    mapNew.setCharAtPosition(player.getSymbol(),
                             player.getPosition().getX(),
                             player.getPosition().getY());

    // Add monsters to vector and place symbols on map
    this->level.setMonster(Monster(5));
    this->level.addMonstersToVector(this->getNumberOfObjectsToAdd(mapNew));
    addGameObjectsToMap(this->level.getMonsters(), mapNew);

    // Add gems to vector and place symbols on map
    this->level.setGem(Gem(2));
    this->level.addGemsToVector(this->getNumberOfObjectsToAdd(mapNew));
    addGameObjectsToMap(this->level.getGems(), mapNew);

    // Add magic apples to vector and place symbols on map
    this->level.setMagicApple(MagicApple(2));
    this->level.addMagicApplesToVector(this->getNumberOfObjectsToAdd(mapNew));
    addGameObjectsToMap(this->level.getMagicApples(), mapNew);

    this->map = mapNew;
}

// Add game object symbols to map at random positions
void LevelManager::addGameObjectsToMap(vector<GameObject> objects, Map &map) {
    for (int i = 0; i < objects.size(); i++) {
        map.setCharAtPosition(objects[i].getSymbol(), map.getRandomPosition());
    }
}

// Return number of game objects that should be added to the map
int LevelManager::getNumberOfObjectsToAdd(Map &map) {
    int numToAdd = (map.getWidth() * map.getHeight()) / 60;
    int numExtraToAdd;

    if (this->level.getLevelNumber() < 5) {
        numExtraToAdd = 1;
    } else if (this->level.getLevelNumber() < 10) {
        numExtraToAdd = 2;
    } else {
        numExtraToAdd = 3;
    }

    int numToAddTotal = (numToAdd + numExtraToAdd);
    return numToAddTotal;
}

// Return Monster member variable of Level class
Monster LevelManager::getMonster() {
    return this->level.getMonster();
}

// Return Gem member variable of Level class
Gem LevelManager::getGem() {
    return this->level.getGem();
}

// Return Magic Apple member variable of Level class
MagicApple LevelManager::getMagicApple() {
    return this->level.getMagicApple();
}

int LevelManager::getMovementCost() const {
    return this->level.getMovementCost();
}