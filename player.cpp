#include "player.hpp"

#include <cstdint>

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

uint64_t Player::getBoardState() const {
    return this->boardstate;
}

bool Player::makeMove(uint64_t piecePosition, uint64_t newPosition, uint64_t wholeBoardState) {
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

uint64_t Player::getAllValidMoves(uint64_t wholeBoardState) {
  uint64_t allmoves = 0;
  for (int i = 0; i< 16; i++) {
    allmoves |= pieces[i]->getAllValidMoves(this->boardstate, wholeBoardState);
  }
  
  return allmoves;
}

bool Player::testCheck(Player* enemy, uint64_t wholeBoardState) {
  if (enemy->getAllValidMoves(wholeBoardState) & pieces[3] != 0) { //king will always be index 3
    return true;
  }
  return false;
}