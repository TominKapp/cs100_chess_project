#include "board.hpp"
#include "player.hpp"

#include <cstdint>
#include <iostream>
#include <math.h>

Board::Board() {
    this->white = new Player(1);
    this->black = new Player(0);
}

void Board::updateBoardState() {
    this->boardstate = white->getBoardState() | black->getBoardState();
}

uint64_t Board::getBoardState() const {
    return this->boardstate;
}

void Board::drawDebugBoard() const {
    char output;
    
    for (int i = 63; i >= 0; i--) {
        //output = '#';
        
        if (((i / 8) + (i % 8)) % 2 == 1) {
            output = 176;
        }
        else {
            output = 178;
        }
        
        switch(white->getPieceAt(pow(2,i))) {
            case 0:
                output = 'p';
                break;
            case 1:
                output = 'r';
                break;
            case 2:
                output = 'n';
                break;
            case 3:
                output = 'b';
                break;
            case 4:
                output = 'q';
                break;
            case 5:
                output = 'k';
                break;
        }
        
        switch(black->getPieceAt(pow(2,i))) {
            case 0:
                output = 'P';
                break;
            case 1:
                output = 'R';
                break;
            case 2:
                output = 'N';
                break;
            case 3:
                output = 'B';
                break;
            case 4:
                output = 'Q';
                break;
            case 5:
                output = 'K';
                break;
        }
        
        std::cout << output;
        
        if (i % 8 == 0) {
            std::cout << std::endl;
        }
    }
}