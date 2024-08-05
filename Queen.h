#pragma once
#include "Rook.h"
#include"Bishop.h"
class Queen :
    public Rook, public Bishop
{
public:
	Queen(Color c, int num1, int num2);
	Queen();
	bool capture(Board& b1, Move& m1, Move& m2);
	bool legalsquarestomove(Board& b1, Move& m1, Move& m2);
};

