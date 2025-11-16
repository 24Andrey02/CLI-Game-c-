#ifndef ENUMS_H
#define ENUMS_H

enum class Direction{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

enum class GameStatus{
    RUNNING,
    PLAYER_DIED,
    ALL_ENEMIES_DEFEATED,
    LEVEL_COMPLETED
};

enum class AttackType{
    MELEE,
    RANGED
};

#endif