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

long long Player::getBoardState() const {
    return this->boardstate;
}