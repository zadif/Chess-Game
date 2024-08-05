#pragma once
#include "Piece.h"
#include"Board.h"
#include"Rook.h"
#include"Knight.h"
#include"Bishop.h"
class Pawn :
    public Piece
{

public:

	Pawn(Color c, int num1, int num2);

	bool legalsquarestomove(Board& b1, Move& m1, Move& m2) override;

	bool leftdiagnolcapture(Move& m1, Move& m2);
	bool rightdiagnolcapture(Move& m1, Move& m2);
	bool capture(Board& b1, Move& m1, Move& m2) override;
	void pawnpromotion(Board& b1, Move& m1, Move& m2);
};

