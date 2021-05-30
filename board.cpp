#include "board.hpp"

#include <cstdint>

Board::Board(Player* w, Player* b) {
    this->white = w;
    this->black = b;
}

void Board::updateBoardState() {
    this->boardstate = white->getBoardState() | black->getBoardState();
}

uint64_t Board::getBoardState() {
    return this->boardstate;
}