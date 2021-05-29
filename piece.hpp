#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#include "move.hpp"

class Board;

class Piece {
    private:
        Move* moveStrategy; 
        int type; //0 = pawn, 1 = rook, 2 = knight, 3 = bishop, 4 = queen, 5 = king
        int team; //0 = black, 1 = white
        long long position; //position states are stored as a 64 bit number with one bit for each square
	
    public:
    	Piece(int type, int team, int startPos);
        ~Piece();
        bool testMove(long long newPosition, long long playerState, long long boardState) const;
        bool makeMove(long long newPosition, long long playerState, long long boardState);
        long long getAllValidMoves(long long playerState, long long boardState) const;
        bool testCheck() const; //test if piece is in check
};

#endif
