#ifndef __MOVE_HPP__
#define __MOVE_HPP__

#include <math.h>

class Move {
    protected:
        //cast a ray from start to end and return false if there is a collision
        bool raycast(long long start, long long end, int slope, long long boardstate) const {
            int i = 1;
            if (end < start) { //>>
                while (start >> (slope * i) != end) {
                    if (start >> (slope * i) && boardstate != 0) { //if they collide
                        return false;
                    }
                    i++;
                }
            }
            else { //<<
                while (start << (slope * i) != end) {
                    if (start << (slope * i) && boardstate != 0) { //if they collide
                        return false;
                    }
                    i++;
                }
            }
            return true;
        }
    
    public:
        virtual bool testMove(long long position, long long newMove, long long playerState, long long boardState) const = 0;
};

#endif
