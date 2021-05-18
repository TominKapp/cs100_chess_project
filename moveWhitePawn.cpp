#include "moveWhitePawn.hpp"

bool MoveWhitePawn::testMove(long long position, long long newMove) const {
    for (int i = 1; i < 8; i++) {
        if (newMove == position >> 8) {
            return true;
        }
        else if ((newMove == position >> 16) && (position < 65536)) {
            return true; //if in starting position the pawn can move two squares
        }
    }
    return false;
}