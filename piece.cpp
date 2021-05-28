#include "piece.hpp"
#include "moveFactory.hpp"

Piece::Piece(int type, int team, int startPos) {
    MoveFactory factory;
    moveStrategy = factory.createMoveStrategy(type, team);
    position = startPos;
}

Piece::~Piece() {
    delete moveStrategy;
}
