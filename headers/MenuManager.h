#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "Game.h"
#include "InputHandler.h"
#include <iostream>
#include <string>

using namespace std;

class MenuManager {
private:
    InputHandler inputHandler;

    void startNewGame();
    void loadGame();

public:
    void showMainMenu();
    int getMenuChoice();
    void handleMainMenu();
};

#endif