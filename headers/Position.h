#ifndef POSITION_H
#define POSITION_H

#include "Enums.h"
#include <string>
#include <cmath>
#include <stdexcept>

using namespace std;

class Position{
private:
    int x;
    int y;
public:
    Position(int x = 0, int y =0);

    int getX() const;
    int getY() const;

    void setX(int xNew);
    void setY(int yNew);

    bool operator==(const Position& other) const;
    bool operator!=(const Position& other) const;

    Position getNeighbour(Direction dir) const;
    double distanceTo(const Position& other) const;
    string toString() const;

    static Position fromString(const string& str);
};

#endif