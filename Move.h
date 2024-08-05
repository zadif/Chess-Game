#pragma once
#pragma once
#include<iostream>
using namespace std;
class Board;
class Piece;
enum Color
{
	Black, White, Yellow
};



class Move {

public:
	Color colour;
	char symbol;
	int row;
	int column;
	bool occupied;
	bool piecemoved = 0;

	Move()
	{
		colour = Yellow;
		symbol = ' ';
		row = -1;
		column = -1;
		occupied = 0;

	}
	static bool isthesquareempty(Move& m1)
	{
		if (m1.occupied == 0)
			return 1;
		else
			return 0;
	}
	friend ostream& operator <<(ostream& os,Move& m1)
	{
		cout << m1.colour<< m1.symbol<< m1.row+1<< m1.column+1<<endl;
		return os;
	}

};


