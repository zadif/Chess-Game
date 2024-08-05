#pragma once
#include "Piece.h"
class King :
    public Piece
{

public:
	King(Color c, int num1, int num2);
	King();
	bool capture(Board& b1, Move& m1, Move& m2);
	bool legalsquarestomove(Board& b1, Move& m1, Move& m2);
};

