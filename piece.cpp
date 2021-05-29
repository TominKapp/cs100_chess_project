#include "piece.hpp"
#include "moveFactory.hpp"

Piece::Piece(int type, int team, int startPos) {
    this->type = type;
    this->team = team;
    this->position = startPos;
    
    MoveFactory factory;
    this->moveStrategy = factory.createMoveStrategy(type, team);
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
        //TODO: put code here to update board
    }
}

long long Piece::getAllValidMoves(long long playerState, long long boardState) const {
    long long allMoves = 0;
    
    for (int i = 0; i < 64; i++) {
        if (testMove(1 << i, playerState, boardState)) {
            allMoves &= (1 << i);
        }
    }
    
    return allMoves;
}

bool Piece::testCheck() const {
    //TODO: write actual code for this lol
    return false;
}