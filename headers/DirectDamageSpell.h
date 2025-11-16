#ifndef DIRECTDAMAGESPELL_H
#define DIRECTDAMAGESPELL_H

#include "Spell.h"
#include "Enemy.h"
#include "EnemyTower.h"
#include <iostream>

using namespace std;

class DirectDamageSpell : public Spell {
private:
    int damage;
    int range;
    string name;
    
public:
    DirectDamageSpell(int dmg = 25, int rng = 3, string spellName = "Fireball");

    string getName() const override;
    string getDescription() const override;
    int getRange() const override;
    bool canCast(const Position& casterPos, const Position& targetPos, const GameField& field) const override;
    void cast(const Position& casterPos, const Position& targetPos, GameField& field, vector<shared_ptr<GameObject>>& objects) override;
    string serialize() const override;
};

#endif