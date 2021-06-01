#ifndef __KNIGHT_TEST_HPP__
#define __KNIGHT_TEST_HPP__

#include "../piece.hpp"

TEST(KnightTest, testPosition) {
    Piece p(0, 1, 0b1);
    EXPECT_EQ(0b1, p.getPosition());
}

#endif
