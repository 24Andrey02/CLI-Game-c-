#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "Cell.h"
#include "Position.h"
#include "GameException.h"
#include <vector>
#include <random>
#include <chrono>
#include <sstream>

using namespace std;

class GameField {
private:
    vector<vector<Cell>> grid;
    int width;
    int height;

    void initializeBlockedCells();

public:
    GameField(int w = 15, int h = 15);
    
    GameField(const GameField& other);
    GameField(GameField&& other) noexcept;
    GameField& operator=(const GameField& other);
    GameField& operator=(GameField&& other) noexcept;
    
    bool isValidPosition(const Position& pos) const;
    bool isCellFree(const Position& pos) const;
    bool isCellBlocked(const Position& pos) const;
    
    void setPlayerPosition(const Position& pos);
    void setEnemyPosition(const Position& pos);
    void setTowerPosition(const Position& pos);
    void setTrapPosition(const Position& pos);
    void removeTrapPosition(const Position& pos);
    void clearCell(const Position& pos);
    
    Cell getCell(const Position& pos) const;
    
    int getWidth() const;
    int getHeight() const;
    
    string serialize() const;
    void deserialize(istream& stream);
};

#endif