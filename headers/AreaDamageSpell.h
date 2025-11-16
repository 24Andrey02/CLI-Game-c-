#ifndef AREADAMAGESPELL_H
#define AREADAMAGESPELL_H

#include "Spell.h"
#include "Enemy.h"
#include "EnemyTower.h"
#include <iostream>

using namespace std;

class AreaDamageSpell : public Spell {
private:
    int damage;
    int range;
    string name;
    
public:
    AreaDamageSpell(int dmg = 15, int rng = 2, string spellName = "Tornado");

    string getName() const override;
    string getDescription() const override;
    int getRange() const override;
    bool canCast(const Position& casterPos, const Position& targetPos, const GameField& field) const override;
    void cast(const Position& casterPos, const Position& targetPos, GameField& field, vector<shared_ptr<GameObject>>& objects) override;
    string serialize() const override;
};

#endif