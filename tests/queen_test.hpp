#ifndef __QUEEN_TEST_HPP__
#define __QUEEN_TEST_HPP__

#include "../piece.hpp"
#include <math.h>

Test(QueenTest, testPosition){
   Piece p(4, 1, 0x8000000);
   EXPECT_EQ(0x8000000, p.getPosition());
}
TEST(QueenTest, possibleMoves) {
    Piece p(4, 1,0x8000000);
    EXPECT_EQ(0x925438ff38549211, p.getAllValidMoves(0x8000000,0x8000000));
}
#endif
