#include "../headers/InputHandler.h"

char InputHandler::getPlayerInput() {
    char input;
    cout << "Enter command (WASD-move, X-switch weapon, R-ranged attack, C-cast spell, B-buy spell, O-save, L-load, Q-quit): ";
    cin >> input;
    return input;
}

Direction InputHandler::getDirectionInput() {
    char direction;
    cout << "Enter direction (w-up, s-down, a-left, d-right): ";
    cin >> direction;

    switch(direction){
        case 'w': case 'W': return Direction::UP;
        case 's': case 'S': return Direction::DOWN;
        case 'a': case 'A': return Direction::LEFT;
        case 'd': case 'D': return Direction::RIGHT;
        default: 
            cout << "Invalid direction!\n"; 
            return Direction::UP;
    }
}

int InputHandler::getSpellIndexInput(int maxSpells) {
    int spellIndex = -1;
    bool validInput = false;
    while (!validInput) {
        cout << "Choose spell (0-" << maxSpells - 1 << "): ";
        string input;
        cin >> input;
        
        try {
            spellIndex = stoi(input);
            validInput = true;
        } catch (const invalid_argument&) {
            cout << "Invalid input! Please enter a number.\n";
            continue;
        } catch (const out_of_range&) {
            cout << "Number is too large! Please enter a smaller number.\n";
            continue;
        }
        
        if (spellIndex < 0 || spellIndex >= maxSpells) {
            cout << "Invalid spell index! Please enter between 0 and " << maxSpells - 1 << ".\n";
            validInput = false;
        }
    }
    return spellIndex;
}