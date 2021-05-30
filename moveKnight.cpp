#include "moveKnight.hpp"
#include <cstdint>

bool MoveKnight::testMove(uint64_t position, uint64_t newMove, uint64_t playerState, uint64_t boardState) const {
    int magicNumbers[4] = {6, 10, 15, 17};
    
    if (newMove & playerState == 0) { //disallow move if it would land on a friendly piece
        for (int i = 0; i < 4; i++) {
            if (newMove == position << magicNumbers[i]) {
                return true;
            }
            else if (newMove == position >> magicNumbers[i]) {
                return true;
            }
        }
    }
    return false;
}
