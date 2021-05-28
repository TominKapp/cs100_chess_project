#include "moveWhitePawn.hpp"

bool MoveWhitePawn::testMove(long long position, long long newMove, long long playerState, long long boardState) const {
    if (newMove & playerState == 0) { //disallow move if it would land on a friendly piece
        if (newMove == position >> 8) {
            return true;
        }
        else if ((newMove == position >> 16) && (position < 65536) && ((position >> 8) & boardState) == 0) { //if no collision in the next cell
            return true; //if in starting position the pawn can move two squares
        }
    }    
    
    return false;
}