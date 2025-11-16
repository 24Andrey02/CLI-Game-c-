#ifndef SAVELOADMANAGER_H
#define SAVELOADMANAGER_H

#include "GameState.h"
#include "GameException.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyTower.h"
#include "Trap.h"
#include <fstream>
#include <map>
#include <functional>

using namespace std;

class SaveLoadManager {
private:
    GameState& gameState;

public:
    SaveLoadManager(GameState& state);

    void saveGame(const string& filename);
    void loadGame(const string& filename);
};

#endif