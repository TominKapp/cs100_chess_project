#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#pragma once

#include "player.hpp"

class Board {
    private:
        Player* white;
        Player* black;
        
        long long boardstate;
    
    public:
        Board(Player* w, Player* b);
        //~Board();
        
        void updateBoardState();
        long long getBoardState();
};

#endif
