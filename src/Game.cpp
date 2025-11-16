#include "../headers/Game.h"

Game::Game(int fieldWidth, int fieldHeight, int startLevel) 
    : gameState(fieldWidth, fieldHeight, startLevel),
      levelManager(gameState),
      combatManager(gameState),
      objectManager(gameState),
      stateManager(gameState, objectManager),
      saveLoadManager(gameState) {
    levelManager.startLevel();
}

void Game::loadGame(const string& filename) {
    saveLoadManager.loadGame(filename);
}

void Game::playerTurn() {
    char input = inputHandler.getPlayerInput();
    
    switch(input) {
        case 'w': case 'W': combatManager.movePlayer(Direction::UP); break;
        case 's': case 'S': combatManager.movePlayer(Direction::DOWN); break;
        case 'a': case 'A': combatManager.movePlayer(Direction::LEFT); break;
        case 'd': case 'D': combatManager.movePlayer(Direction::RIGHT); break;
        case 'x': case 'X': switchWeapon(); break;
        case 'r': case 'R': 
            if (gameState.getPlayer()->getAtackType() == AttackType::RANGED) {
                Direction dir = inputHandler.getDirectionInput();
                combatManager.performRangedAttack(dir);
            } else {
                cout << "Switch to ranged weapon first!\n";
            }
            break;
        case 'c': case 'C': castSpell(); break;
        case 'b': case 'B': buySpell(); break;
        case 'o': case 'O': 
            try {
                saveLoadManager.saveGame("savegame.txt");
            } catch (const GameException& e) {
                cout << "Save failed: " << e.what() << "\n";
            }
            break;
        case 'l': case 'L': 
            try {
                saveLoadManager.loadGame("savegame.txt");
            } catch (const GameException& e) {
                cout << "Load failed: " << e.what() << "\n";
            }
            break;
        case 'q': case 'Q': quitGame(); break;
        default: cout << "Invalid command!\n"; break;
    }
}

void Game::runGame() {
    while (gameState.isRunning()) {
        if (gameState.getStatus() != GameStatus::RUNNING) {
            gameState.setStatus(GameStatus::RUNNING);
        }
        
        while (gameState.getStatus() == GameStatus::RUNNING && gameState.isRunning()) {
            renderer.renderHeader(gameState.getField(), gameState.getPlayer(), gameState.getCurrentLevel(),gameState.getEnemies(), gameState.getTowers(), gameState.getTraps());
            renderer.renderField(gameState.getField());
            
            playerTurn();
            if (gameState.getStatus() != GameStatus::RUNNING || !gameState.isRunning()) break;
            
            combatManager.processEnemyTurns();
            stateManager.updateGameState();
        }
        
        if (!gameState.isRunning()) break;
        
        renderer.renderGameOver(gameState.getStatus(), gameState.getCurrentLevel(), gameState.getPlayer()->getScore());
        
        if (gameState.getStatus() == GameStatus::LEVEL_COMPLETED) {
            cout << "Press N for next level or Q to quit: ";
            char choice;
            cin >> choice;
            if (choice == 'n' || choice == 'N') {
                levelManager.nextLevel();
            } else {
                gameState.setGameRunning(false);
            }
        } else if (gameState.getStatus() == GameStatus::PLAYER_DIED) {
            cout << "Press R to restart or Q to quit: ";
            char choice;
            cin >> choice;
            if (choice == 'r' || choice == 'R') {
                restartGame();
            } else {
                gameState.setGameRunning(false);
            }
        }
    }
}

void Game::switchWeapon() {
    auto player = gameState.getPlayer();
    player->switchWeapon();
    cout << "Switched to " << player->getWeaponName() << " combat! Damage: " << player->getDamage() << "\n";
}

void Game::castSpell() {
    auto player = gameState.getPlayer();
    player->getSpellHand().displaySpells();

    if (player->getSpellHand().getSpellCount() == 0) {
        cout << "No spells available!\n";
        return;
    }

    int spellIndex = inputHandler.getSpellIndexInput(player->getSpellHand().getSpellCount());
    Direction dir = inputHandler.getDirectionInput();
    
    Position targetPos = player->getPosition().getNeighbour(dir);
    player->getSpellHand().castSpell(spellIndex, player->getPosition(), targetPos, gameState.getField(), gameState.getGameObjects());
    
    gameState.updateFieldState();
}

void Game::buySpell() {
    gameState.getPlayer()->buySpell();
}

void Game::quitGame() {
    gameState.setStatus(GameStatus::PLAYER_DIED);
    gameState.setGameRunning(false);
}

void Game::restartGame() {
    Game newGame(15, 15, 1);
    newGame.runGame();
    gameState.setGameRunning(false);
}