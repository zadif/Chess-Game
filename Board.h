#pragma once
#include<iostream>
using namespace std;
#include"Piece.h"
#include"Move.h"
#include"Pawn.h"
#include"Rook.h"
#include"Knight.h"
#include"Bishop.h"
#include "Player.h"
#include"King.h"



class Board
{
public:
	Piece*** boardptr;
	

	Board();
	void drawboard();
	void drawboard2();


	void createboard1();
	void createboard2();
	void createboard3();
	void writeinfile(Board&, const string&);
	static bool readfromfile(Board&, const string&);

	~Board();
};

