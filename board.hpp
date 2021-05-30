#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#pragma once

#include <cstdint>

#include "player.hpp"

class Board {
    private:
        Player* white;
        Player* black;
        
        uint64_t boardstate;
    
    public:
        Board(Player* w, Player* b);
        //~Board();
        
        void updateBoardState();
        uint64_t getBoardState();
};

#endif
