#include "moveQueen.hpp"
#include <math.h> 
#include <cstdint>

bool MoveQueen::testMove(uint64_t position, uint64_t newMove, uint64_t playerState, uint64_t boardState) const {
    int magicNumbers[4] = {1, 7, 8, 9};
    
    for (int i = 1; i < 8; i++) { 
        for (int j = 0; j < 4; i++) {
            if (newMove == position << (magicNumbers[j] * i) && raycast(position, newMove, magicNumbers[j], boardState)) {
                return true;
            }
            else if (newMove == position >> (magicNumbers[j] * i) && raycast(position, newMove, magicNumbers[j], boardState)) {
                return true;
            }
        }
    }

    return false;
}