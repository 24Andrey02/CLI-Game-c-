#ifndef ENEMYTOWER_H
#define ENEMYTOWER_H

#include "GameObject.h"
#include "Position.h"
#include <memory>
#include <sstream>

using namespace std;

class Player;

class EnemyTower : public GameObject {
private:
    Position position;
    int health;
    int damage;
    int attackRange;
    bool canAttack;
    int level;
    
public:
    EnemyTower(int x = 0, int y = 0, int lvl = 1);
    
    Position getPosition() const override;
    bool isAlive() const override;
    void takeDamage(int amount) override;
    
    void attackIfPossible(const Position& playerPos, shared_ptr<Player> player);    
    void resetAttack();
    
    int getHealth() const;
    int getLevel() const;
    
    string serialize() const override;
    
    static shared_ptr<EnemyTower> deserialize(const string& data);
};

#endif