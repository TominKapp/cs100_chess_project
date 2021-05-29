#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "piece.hpp"

class Player {
    private:
        long long boardstate;
        Piece* pieces[16] = {nullptr}; 
        int team;
        
    public:
        Player(int team);
        ~Player();
        
        void updateBoardState();
        long long getBoardState() const;
        bool makeMove(long long piecePosition, long long newPosition, long long boardState);
        void testCaptures(Player* enemy);
        long long getAllValidMoves(long long wholeBoardState);
};

#endif
