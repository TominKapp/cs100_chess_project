#ifndef __MOVEQUEEN_HPP__
#define __MOVEQUEEN_HPP__

#include "move.hpp"

class MoveQueen: public Move {
    public:
        bool testMove(long long position, long long newMove, long long playerState, long long boardState) const;
};

#endif