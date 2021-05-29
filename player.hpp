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
        
        long long getBoardState() const;
    
};

#endif
