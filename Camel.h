#pragma once
#include "Rook.h"
class Camel :
    public Piece
{
public:
	Camel(Color c, int num1, int num2);
	Camel();
	bool lshapemove(Board& b1, Move& m1, Move& m2);
	bool capture(Board& b1, Move& m1, Move& m2);
	bool legalsquarestomove(Board& b1, Move& m1, Move& m2);
	bool rookmove(Board& b1, Move& m1, Move& m2);
	bool verticalfree(Board& b1, Move& m1, Move& m2);
	bool horizontalfree(Board& b1, Move& m1, Move& m2);
};

