#include "moveKnight.hpp"

bool MoveKnight::testMove(long long position, long long newMove, long long playerState, long long boardState) const {
    int magicNumbers[4] = {6, 10, 15, 17};
    
    if (newMove && playerState == 0) { //disallow move if it would land on a friendly piece
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
