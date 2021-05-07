#ifndef __MOVE_HPP__
#define __MOVE_HPP__

class Move {
    virtual bool testMove(long long position, long long newMove) const = 0;
};

#endif
