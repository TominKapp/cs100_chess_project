#ifndef __MOVEROOK_HPP__
#define __MOVEROOK_HPP__

#include "move.hpp"

class MoveRook: public move {
    bool testMove(long long position, long long newMove);
};

#endif