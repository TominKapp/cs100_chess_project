#ifndef __KING_TEST_HPP__
#define __KING_TEST_HPP__

#include "../piece.hpp"

Test(KingTest, testPosition){
   Piece p(5, 0, 0x8000000);
   EXPECT_EQ((0x8000000), p.getPosition());
}
Test(KingTest, possibleMoves){
	Piece p(5, 0, static_cast<uint64_t>(pow(2,27)));
	EXPECT_EQ(382838000000,  p.getAllValidMoves(0x8000000, 0x8000000));
}
#endif
