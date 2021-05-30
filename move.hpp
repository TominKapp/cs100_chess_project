#ifndef __MOVE_HPP__
#define __MOVE_HPP__

#include <math.h>
#include <cstdint>

class Move {
    protected:
        //cast a ray from start to end and return false if there is a collision
        bool raycast(uint64_t start, uint64_t end, int slope, uint64_t boardstate) const {
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
        virtual bool testMove(uint64_t position, uint64_t newMove, uint64_t playerState, uint64_t boardState) const = 0;
};

#endif
