#include "board.hpp"

Board::Board(Player* w, Player* b) {
    this->white = w;
    this->black = b;
}

void Board::updateBoardState() {
    this->boardstate = white->getBoardState() | black->getBoardState();
}

long long Board::getBoardState() {
    return this->boardstate;
}