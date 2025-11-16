#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "GameField.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyTower.h"
#include "Trap.h"
#include "Enums.h"
#include <vector>
#include <memory>

using namespace std;

class GameState {
private:
    GameField field;
    shared_ptr<Player> player;
    vector<shared_ptr<GameObject>> gameObjects;
    GameStatus status;
    int currentLevel;
    bool gameRunning;

public:
    GameState(int fieldWidth = 15, int fieldHeight = 15, int startLevel = 1);

    GameField& getField();
    shared_ptr<Player> getPlayer();
    vector<shared_ptr<GameObject>>& getGameObjects();
    GameStatus getStatus() const;
    int getCurrentLevel() const;
    bool isRunning() const;

    void setStatus(GameStatus newStatus);
    void setGameRunning(bool running);
    void setCurrentLevel(int level);
    void setPlayer(const shared_ptr<Player>& newPlayer);
    void setField(const GameField& newField);
    
    void clearGameObjects();
    void addGameObject(shared_ptr<GameObject> obj);
    
    void updateFieldState();

    vector<shared_ptr<Enemy>> getEnemies();
    vector<shared_ptr<EnemyTower>> getTowers();
    vector<shared_ptr<Trap>> getTraps();
};

#endif