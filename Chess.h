#pragma once
#include<iostream>
using namespace std;
#include<windows.h>
#include"Move.h"
#include "Player.h"
#include "Board.h"





class Chess
{
	
	Player p1;
	Player p2;
public:
	Board b1;
	Chess();
	void playchess();
	void playkingrush();
	void playtalgambit();
	void kingrushcheckmate();
	void kingrushtoprowcondition(Move&);
	void currentposition(Move&);
	void play1();
	void play2();
	void makemove(int, int, int, int);
	Move getking(Move& m1);
	Move getqueen(Move&);
	Move getcamel(Move&);
	Move getrook(Move&, Move&);
	Move getbishop(Move&, Move&);
	Move getknight(Move&, Move&);
	bool check(Move&, Move&);
	bool queencheck(Move&, Move&, Move&, Move&);
	bool camelcheck(Move&, Move&, Move&, Move&);
	bool rookcheck(Move&, Move&, Move&, Move&);
	bool bishopcheck(Move&, Move&, Move&, Move&);
	bool knightcheck(Move&, Move&, Move&, Move&);
	void piecemaker(Move&, Color);
	bool kingsidecastle(Move&, Move&, Move&, Move&, Move&, Move&, Move&, Move&, Move&, Move&);
	bool queensidecastle(Move&, Move&, Move&, Move&, Move&, Move&, Move&, Move&, Move&, Move&, Move&);
	bool kingcapture(Move&, Move&, Move&, Move&, Move&, Move&, Move&, Move&, Move&);
	void checkmate();
	
	~Chess();
};


