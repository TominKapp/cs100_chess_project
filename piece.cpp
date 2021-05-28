#include "piece.hpp"

Piece::Piece(int type, int team, int startPos) {
    
}

Piece::~Piece() {
    delete moveStrategy;
}
