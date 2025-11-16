#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Position.h"
#include "Enums.h"
#include "SpellHand.h"
#include <string>
#include <memory>
#include <sstream>

using namespace std;

class Player : public GameObject {
private:
    int max_health;
    int health;
    int score;
    int melee_damage;
    int ranged_damage;
    int ranged_range;
    bool is_switch_weapon;
    AttackType current_attack;
    Position position;
    SpellHand spellHand;
    int enemies_defeated;
    int level;

public:
    Player(int startX = 0, int startY = 0, int handSize = 3, int lvl = 1);

    void takeDamage(int mount_damage) override;
    void heal(int amount_heal);
    void addScore(int points);
    void addEnemyDefeated();
    bool isAlive() const override;
    void moving(const Position& new_pos);
    void switchWeapon();
    void prepareForNextLevel();

    bool getIsSwitchingWeapon() const;
    AttackType getAtackType() const;
    int getDamage() const;
    int getRangedRange() const;
    string getWeaponName() const;
    int getHealth() const;
    int getMaxHealth() const;
    int getScore() const;
    Position getPosition() const override;
    int getLevel() const;
    
    SpellHand& getSpellHand();
    bool buySpell();
    
    string serialize() const override;
    
    static shared_ptr<Player> deserialize(const string& data);
};

#endif