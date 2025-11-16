#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Enums.h"
#include <iostream>
#include <string>

using namespace std;

class InputHandler {
public:
    char getPlayerInput();
    Direction getDirectionInput();
    int getSpellIndexInput(int maxSpells);
};

#endif