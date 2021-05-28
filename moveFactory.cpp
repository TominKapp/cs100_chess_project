#include "moveFactory.hpp"

#include "moveBlackPawn.hpp"
#include "moveWhitePawn.hpp"
#include "moveRook.hpp"

Move* MoveFactory::createMoveStrategy(int type, int team) { //0 = pawn, 1 = rook, 2 = knight, 3 = bishop, 4 = queen, 5 = king 
    switch(type) {
        case 0:
            if (team == 0) { //black
                return new MoveBlackPawn();
            }
            else { //assume white otherwise
                return new MoveWhitePawn();
            }
            break;
            
        case 1:
            return new MoveRook();
            break;
            
        case 2:
            //TODO: make MoveKnight
            break;
            
        case 3:
            return new MoveBishop();
            break;
            
        case 4:
            //TODO: make MoveQueen
            break;
            
        case 5:
            //TODO: make MoveKing
            break;
        
        default:
            return nullptr;
            break;
    }
}