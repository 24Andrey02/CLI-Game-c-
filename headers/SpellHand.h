#ifndef SPELLHAND_H
#define SPELLHAND_H

#include "Spell.h"
#include "DirectDamageSpell.h"
#include "AreaDamageSpell.h"
#include "TrapSpell.h"
#include "GameException.h"
#include <vector>
#include <memory>
#include <random>
#include <chrono>
#include <map>
#include <functional>
#include <sstream>

using namespace std;

class SpellHand {
private:
    vector<shared_ptr<Spell>> spells;
    int maxSize;
    
public:
    SpellHand(int size = 3);
    
    void addSpell(shared_ptr<Spell> spell);
    void addRandomSpell();
    
    bool castSpell(int index, const Position& casterPos, const Position& targetPos, GameField& field, vector<shared_ptr<GameObject>>& objects);
    
    void displaySpells() const;
    
    size_t getSpellCount() const;
    int getMaxSize() const;
    
    void removeRandomSpells(int count);
    
    string serialize() const;
    void deserialize(istream& stream);
};

#endif