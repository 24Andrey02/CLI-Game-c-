#ifndef SPELL_H
#define SPELL_H

#include "Position.h"
#include "GameField.h"
#include "GameObject.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;

class Spell {
public:
    virtual ~Spell() = default;
    virtual string getName() const = 0;
    virtual string getDescription() const = 0;
    virtual bool canCast(const Position& casterPos, const Position& targetPos, const GameField& field) const = 0;
    virtual void cast(const Position& casterPos, const Position& targetPos, GameField& field, vector<shared_ptr<GameObject>>& objects) = 0;
    virtual int getRange() const = 0;
    virtual string serialize() const = 0;
};

#endif