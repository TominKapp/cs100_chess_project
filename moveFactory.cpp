#include "moveFactory.hpp"

#include "moveBlackPawn.hpp"
#include "moveWhitePawn.hpp"
#include "moveRook.hpp"
#include "moveKnight.hpp"
#include "moveBishop.hpp"
#include "moveQueen.hpp"
#include "moveKing.hpp"

Move* MoveFactory::createMoveStrategy(int type, int team) { //0 = pawn, 1 = rook, 2 = knight, 3 = bishop, 4 = queen, 5 = king 
    switch(type) {
        case 0:
            if (team == 0) { //black
                return new MoveBlackPawn();
            }
            else if (team == 1) { //white
                return new MoveWhitePawn();
            }
            else {
                return nullptr;
            }
            break;
            
        case 1:
            return new MoveRook();
            break;
            
        case 2:
            return new MoveKnight();
            break;
            
        case 3:
            return new MoveBishop();
            break;
            
        case 4:
            return new MoveQueen();
            break;
            
        case 5:
            return new MoveKing();
            break;
        
        default:
            return nullptr;
            break;
    }
}