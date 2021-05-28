#ifndef __MOVEBISHOP_HPP__
#define __MOVEBISHOP_HPP__

#include "move.hpp"

class MoveBishop: public Move {
    public:
        bool testMove(long long position, long long newMove, long long playerState, long long boardState) const;
};

#endif
