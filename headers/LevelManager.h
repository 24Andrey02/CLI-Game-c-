#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "GameState.h"
#include "Enemy.h"
#include "EnemyTower.h"
#include <random>
#include <chrono>

using namespace std;

class LevelManager {
private:
    GameState& gameState;

    void initializeEnemies();
    void initializeTowers();

public:
    LevelManager(GameState& state);

    void startLevel();
    void nextLevel();
};

#endif