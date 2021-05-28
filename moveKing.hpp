#ifndef __MOVEKING_HPP__
#define __MOVEKING_HPP__

#include "move.hpp"

class MoveKing: public Move {
    public:
        bool testMove(long long position, long long newMove, long long playerState, long long boardState) const;
};

#endif