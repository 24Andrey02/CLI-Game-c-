#ifndef TRAPSPELL_H
#define TRAPSPELL_H

#include "Spell.h"
#include "Trap.h"

using namespace std;

class TrapSpell : public Spell {
private:
    int damage;
    int range;
    string name;
    
public:
    TrapSpell(int dmg = 20, int rng = 2, string spellName = "BearTrap");

    string getName() const override;
    string getDescription() const override;
    int getRange() const override;
    bool canCast(const Position& casterPos, const Position& targetPos, const GameField& field) const override;
    void cast(const Position& casterPos, const Position& targetPos, GameField& field, vector<shared_ptr<GameObject>>& objects) override;
    string serialize() const override;
};

#endif