#ifndef __BPAWN_TEST_HPP__
#define __BPAWN_TEST_HPP__

#include "../piece.hpp"
#include <math.h>
TEST(BlackPawnTest, testPosition) {
    Piece p(0, 1, 0x1000000000000);
    EXPECT_EQ(0x1000000000000, p.getPosition());
}

TEST(BlackPawnTest, possibleMoves) {
    Piece p(0, 1, 0x1000000000000);
    EXPECT_EQ(static_cast<uint64_t>(pow(2, 8) | static_cast<uint64_t>(pow(2, 16))), p.getAllValidMoves(0x1000000000000, 0x1000000000000));
}
#endif
