#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Position.h"
#include <string>

using namespace std;

class GameObject {
public:
    virtual ~GameObject() = default;
    virtual Position getPosition() const = 0;
    virtual bool isAlive() const = 0;
    virtual void takeDamage(int damage) = 0;
    virtual string serialize() const = 0;
};

#endif