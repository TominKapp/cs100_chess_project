#include "moveBishop.h"

bool MoveBishop::testMove(long long position, long long newMove) const {
    for (int i = 1; i < 8; i++) {
        if (newMove == position << (7 * i)) {
            return true;
        }
        else if (newMove == position << (9 * i)) {
            return true;
        }
        else if (newMove == position >> (9 * i)) {
            return true;
        }
        else if (newMove == position >> (7 * i)) {
            return true;
        }
    }
    return false;
}
