#ifndef TRAP_H
#define TRAP_H

#include "GameObject.h"
#include "Position.h"
#include <memory>
#include <sstream>
#include <iostream>

using namespace std;

class Trap : public GameObject {
private:
    Position position;
    int damage;
    bool active;
    
public:
    Trap(const Position& pos, int dmg = 20);
    
    Position getPosition() const override;
    bool isAlive() const override;
    void takeDamage(int) override;
    
    void trigger(shared_ptr<GameObject> target);
    
    string serialize() const override;
    
    static shared_ptr<Trap> deserialize(const string& data);
};

#endif