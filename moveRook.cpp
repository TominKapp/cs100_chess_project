#include "moveRook.hpp"
#include <math.h> 
#include <cstdint>

bool MoveRook::testMove(uint64_t position, uint64_t newMove, uint64_t playerState, uint64_t boardState) const {
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