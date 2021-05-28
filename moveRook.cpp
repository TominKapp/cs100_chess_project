#include "moveRook.hpp"
#include <math.h> 

bool MoveRook::testMove(long long position, long long newMove, long long playerState, long long boardState) const {
    for (int i = 1; i < 8; i++) {
        if (newMove == position << 8) {
            return true;
        }
        else if (newMove == position >> 8) {
            return true;
        }
        else if (newMove == position >> 1) {
            return true;
        }
        else if (newMove == position << 1) {
            return true;
        }
    }
    return false;
}