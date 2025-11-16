#include "../headers/GameStateManager.h"

GameStateManager::GameStateManager(GameState& state, ObjectManager& objManager) 
    : gameState(state), objectManager(objManager) {}

void GameStateManager::updateGameState() {
    auto player = gameState.getPlayer();
    if (!player->isAlive()) {
        gameState.setStatus(GameStatus::PLAYER_DIED);
        return;
    }
    
    objectManager.cleanupDeadObjects();
    objectManager.checkTraps();
    
    bool enemies_alive = false;
    auto enemies = gameState.getEnemies();
    for (const auto& enemy : enemies) {
        if (enemy->isAlive()) {
            enemies_alive = true;
            break;
        }
    }
    
    bool towers_alive = false;
    auto towers = gameState.getTowers();
    for (const auto& tower : towers) {
        if (tower->isAlive()) {
            towers_alive = true;
            break;
        }
    }
    
    if (!enemies_alive && !towers_alive) {
        gameState.setStatus(GameStatus::LEVEL_COMPLETED);
    }
}