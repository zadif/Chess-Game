#pragma once
#include"Move.h"
class Piece :
    public Move
{
public:
	Piece();

	//protected:

	virtual  bool legalsquarestomove(Board& b1, Move& m1, Move& m2) = 0;
	void printcantmove() const;

	virtual bool capture(Board& b1, Move& m1, Move& m2) = 0;
	void printcantcapture() const;
	bool check(Move& m1);
	void printcheck(Move&)const;
	bool checkmate();
	void printcheckmate()const;
	void moveapiece(Move& m1);
	virtual ~Piece(){}
};

