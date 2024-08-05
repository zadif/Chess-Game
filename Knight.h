#pragma once
#include "Piece.h"
class Knight :
   virtual public Piece
{
public:
	Knight(Color c, int num1, int num2);
	Knight();
	bool legalsquarestomove(Board& b1, Move& m1, Move& m2) override;
   bool capture(Board& b1, Move& m1, Move& m2) override;
};

