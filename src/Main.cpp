#include "../headers/MenuManager.h"

int main(){
    try {
        MenuManager menu;
        menu.handleMainMenu();
    }
    catch (const exception& e) {
        cout << "Fatal error: " << e.what() << "\n";
        return 1;
    }
    
    return 0;
}