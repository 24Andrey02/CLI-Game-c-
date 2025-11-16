#ifndef COMBATMANAGER_H
#define COMBATMANAGER_H

#include "GameState.h"
#include "Enemy.h"
#include "EnemyTower.h"
#include "Player.h"
#include <random>
#include <chrono>

using namespace std;

class CombatManager {
private:
    GameState& gameState;

public:
    CombatManager(GameState& state);

    void performRangedAttack(Direction dir);
    void processEnemyTurns();
    void movePlayer(Direction dir);
};

#endif