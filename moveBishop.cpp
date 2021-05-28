#include "moveBishop.hpp"

bool MoveBishop::testMove(long long position, long long newMove, long long playerState, long long boardState) const {
    long long attemptedMove = 0;
    
    for (int i = 1; i < 8; i++) {
        if (newMove == position << (7 * i) && raycast(position, newMove, 7, boardState)) {
            return true;
        }
        else if (newMove == position << (9 * i) && raycast(position, newMove, 9, boardState)) {
            return true;
        }
        else if (newMove == position >> (9 * i) && raycast(position, newMove, 9, boardState)) {
            return true;
        }
        else if (newMove == position >> (7 * i) && raycast(position, newMove, 7, boardState)) {
            return true;
        }
    }
    
    
    return false;
}
