#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "GameRenderer.h"
#include "LevelManager.h"
#include "CombatManager.h"
#include "ObjectManager.h"
#include "GameStateManager.h"
#include "SaveLoadManager.h"
#include "InputHandler.h"
#include <iostream>

using namespace std;

class Game {
private:
    GameState gameState;
    GameRenderer renderer;
    LevelManager levelManager;
    CombatManager combatManager;
    ObjectManager objectManager;
    GameStateManager stateManager;
    SaveLoadManager saveLoadManager;
    InputHandler inputHandler;

    void switchWeapon();
    void castSpell();
    void buySpell();
    void quitGame();
    void restartGame();

public:
    Game(int fieldWidth = 15, int fieldHeight = 15, int startLevel = 1);

    void loadGame(const string& filename);
    void playerTurn();
    void runGame();
};

#endif