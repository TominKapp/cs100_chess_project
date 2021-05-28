#ifndef __MOVEWHITEPAWN_HPP__
#define __MOVEWHITEPAWN_HPP__

#include "move.hpp"

class MoveWhitePawn: public Move {
    public:
        bool testMove(long long position, long long newMove, long long playerState, long long boardState) const;
};

#endif
