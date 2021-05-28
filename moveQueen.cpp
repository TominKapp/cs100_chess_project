#include "moveQueen.hpp"
#include <math.h> 

bool MoveQueen::testMove(long long position, long long newMove, long long playerState, long long boardState) const {
    int magicNumbers[4] = {1, 7, 8, 9};
    
    for (int i = 1; i < 8; i++) { 
        for (int j = 0; j < 4; i++) {
            if (newMove == position << (magicNumbers[j] * i)) {
                return true;
            }
            else if (newMove == position >> (magicNumbers[j] * i)) {
                return true;
            }
        }
    }

    return false;
}