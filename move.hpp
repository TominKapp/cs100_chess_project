#ifndef __MOVE_HPP__
#define __MOVE_HPP__

class Move {
    public:
        virtual bool testMove(long long position, long long newMove, long long playerState, long long boardState) const = 0;
};

#endif
