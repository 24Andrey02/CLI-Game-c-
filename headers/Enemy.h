#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "Position.h"
#include <memory>
#include <sstream>

using namespace std;

class Enemy : public GameObject {
private:
    Position position;
    int health;
    int damage;
    int level;

public:
    Enemy(int x = 0, int y = 0, int lvl = 1);
    
    bool isAlive() const override;
    void takeDamage(int mount_damage) override;
    void moving(const Position& new_pos);
    
    int getHealth() const;
    int getDamage() const;
    Position getPosition() const override;
    int getLevel() const;
    
    string serialize() const override;
    
    static shared_ptr<Enemy> deserialize(const string& data);
};

#endif