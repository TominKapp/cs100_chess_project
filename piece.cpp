#include "piece.hpp"
#include "moveFactory.hpp"

Piece::Piece(int type, int team, int startPos) {
    this->type = type;
    this->team = team;
    this->position = startPos;
    
    MoveFactory factory;
    this->moveStrategy = factory.createMoveStrategy(type, team);
    
    this->captured = false;
}

Piece::~Piece() {
    delete moveStrategy;
}

bool Piece::testMove(long long newPosition, long long playerState, long long boardState) const {
    if (moveStrategy->testMove(position, newPosition, playerState, boardState)) {
        return true;
    }
    return false;
}

bool Piece::makeMove(long long newPosition, long long playerState, long long boardState) {
    if (testMove(newPosition, playerState, boardState)) {
        this->position = newPosition;
    }
}

long long Piece::getAllValidMoves(long long playerState, long long boardState) const {
    long long allMoves = 0;
    
    for (int i = 0; i < 64; i++) {
        if (testMove(1 << i, playerState, boardState)) {
            allMoves |= (1 << i);
        }
    }
    
    return allMoves;
}

long long Piece::getPosition() {
    return this->position;
}

bool Piece::isCaptured() {
    return this->captured;
}

void Piece::becomeCaptured() {
    this->position = 0; //effectively remove from board
    this->captured = true;
}