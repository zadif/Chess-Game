#pragma once
#include<algorithm>
#include "Piece.h"
#include"Board.h"
class Bishop : virtual public Piece
{
public:
	Bishop(Color c, int num1, int num2);
	Bishop();
	bool legalsquarestomove(Board& b1, Move& m1, Move& m2) override;

	bool leftdiagnolfree(Board& b1, Move& m1, Move& m2);
	bool rightdiagnolfree(Board& b1, Move& m1, Move& m2);
	bool capture(Board& b1, Move& m1, Move& m2) override;
};

