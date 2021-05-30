#include "moveBishop.hpp"

#include <cstdint>

bool MoveBishop::testMove(uint64_t position, uint64_t newMove, uint64_t playerState, uint64_t boardState) const {
    uint64_t attemptedMove = 0;
    
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
