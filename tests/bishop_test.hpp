#ifndef __BISHOP_TEST_HPP__
#define __BISHOP_TEST_HPP__

#include "../piece.hpp"
#include <math.h>

Test(BishopTest, testPosition){
	Piece p( 3, 0, 0x8000000);
	EXPECT_EQ(0X8000000, p.getPosition());
}
TEST(BishopTest, possibleMoves) {
    Piece p(4, 1,static_cast<uint64_t>(pow(2,27)));
    EXPECT_EQ(0x8244281028448201, p.getAllValidMoves(static_cast<uint64_t>(pow(2,27)), static_cast<uint64_t>(pow(2,27))));
}
#endif
