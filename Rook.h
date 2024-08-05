#pragma once
#include "Piece.h"
#include"Board.h"
class Rook : virtual public Piece
{
public:
	Rook(Color c, int num1, int num2);
	Rook();
	bool legalsquarestomove(Board& b1, Move& m1, Move& m2) override;
	bool verticalfree(Board& b1, Move& m1, Move& m2);
	bool horizontalfree(Board& b1, Move& m1, Move& m2);
	bool capture(Board& b1, Move& m1, Move& m2) override;
};

