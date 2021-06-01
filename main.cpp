#include "piece.hpp"
#include "move.hpp"
#include "player.hpp"
#include "board.hpp"

#include <cstdint>
#include <iostream>
#include <math.h>

void printFormatted(const uint64_t &l) {
    uint64_t comp = 0x8000000000000000;
    
    for (int i = 0; i < 64; i++) {
        if (comp & (l << i)) {
            std::cout <<"1";
        }
        else {
            std::cout << "0";
        }
        
        if ((i + 1) % 8 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int main () {
    Board* b = new Board();
    
    b->runTerminalGame();
    
    delete b;
    return 0;
}