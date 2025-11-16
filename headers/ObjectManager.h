#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "GameState.h"
#include "Trap.h"

using namespace std;

class ObjectManager {
private:
    GameState& gameState;

public:
    ObjectManager(GameState& state);

    void cleanupDeadObjects();
    void checkTraps();
};

#endif