#include "moveRook.hpp"
#include <math.h> 

bool MoveRook::testMove(long long position, long long newMove, long long playerState, long long boardState) const {
    for (int i = 1; i < 8; i++) {
        if (newMove == position << 8 && raycast(position, newMove, 8, boardState)) {
            return true;
        }
        else if (newMove == position >> 8 && raycast(position, newMove, 8, boardState)) {
            return true;
        }
        else if (newMove == position >> 1 && raycast(position, newMove, 1, boardState)) {
            return true;
        }
        else if (newMove == position << 1 && raycast(position, newMove, 1, boardState)) {
            return true;
        }
    }
    return false;
}