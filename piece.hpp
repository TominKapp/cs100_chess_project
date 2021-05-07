#ifndef __PIECE_HPP__
#define __PIECE_HPP__

class Piece {
    private:
	Move* moveStrategy; 
	int type; //0 = pawn, 1 = rook, 2 = knight, 3 = bishop, 4 = queen, 5 = king
	int team; //0 = black, 1 = white
	long long position; //position states are stored as a 64 bit number with one bit for each square
	
    public:
    	Piece(type, position);
	bool makeMove(long long newPosition);
	bool testMove(long long newPosition);
	bool getAllValidMoves(long long moveArray*);
	bool testCheck(); //test if piece is in check
};

#endif
