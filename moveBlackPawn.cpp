#include "moveBlackPawn.hpp"
#include <math.h> 

bool MoveBlackPawn::testMove(long long position, long long newMove, long long playerState, long long boardState) const {
    if (newMove == position << 8) {
        return true;
    }
    else if ((newMove == position << 16) && (position > pow(2,48)) && ((position << 8) & boardState) == 0) {
        return true; //if in starting position the pawn can move two squares
    }
    return false;
}