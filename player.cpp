#include "player.hpp"

Player::Player(int team) {
    this->team = team;
}

Player::~Player() {
    for (int i = 0; i < 16; i++) {
        if (pieces[i] != nullptr) {
            delete pieces[i];
        }
    }
}

void Player::updateBoardState() {
    this->boardstate = 0;
    
    for (int i = 0; i < 16; i++) {
        this->boardstate |= pieces[i]->getPosition();
    }
}

long long Player::getBoardState() const {
    return this->boardstate;
}

bool Player::makeMove(long long piecePosition, long long newPosition, long long wholeBoardState) {
    for (int i = 0; i < 16; i++) { //find if there is a piece at x position
        if (pieces[i]->getPosition() == piecePosition) {
            return pieces[i]->makeMove(newPosition, this->boardstate, wholeBoardState);
            this->updateBoardState();
        }
    }
    return false;
} //returns true if the move was made and false otherwise

void Player::testCaptures(Player* enemy) { //set a piece to captured if it coincides with enemy position
    for (int i = 0; i < 16; i++) {
        if (pieces[i]->getPosition() & enemy->getBoardState() != 0) {
            pieces[i]->becomeCaptured();
        }
    }
}