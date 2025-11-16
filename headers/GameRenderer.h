#ifndef GAMERENDERER_H
#define GAMERENDERER_H

#include "GameField.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyTower.h"
#include "Trap.h"
#include "Enums.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class GameRenderer {
public:
    void renderHeader(const GameField& field, const shared_ptr<Player>& player, int currentLevel, 
                     const vector<shared_ptr<Enemy>>& enemies, const vector<shared_ptr<EnemyTower>>& towers, 
                     const vector<shared_ptr<Trap>>& traps);
    void renderField(const GameField& field);
    void renderGameOver(GameStatus status, int currentLevel, int score);
};

#endif