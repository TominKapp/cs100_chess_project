#ifndef __MOVEBLACKPAWN_HPP__
#define __MOVEBLACKPAWN_HPP__

#include "move.hpp"

class MoveBlackPawn: public Move {
    public:
        bool testMove(long long position, long long newMove, long long playerState, long long boardState) const;
};

#endif