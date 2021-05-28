#ifndef __MOVEKNIGHT_HPP__
#define __MOVEKNIGHT_HPP__

#include "move.hpp"

class MoveKnight: public Move {
    public:
        bool testMove(long long position, long long newMove, long long playerState, long long boardState) const;
};

#endif