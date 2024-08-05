#include<iostream>
#include<Windows.h>
using namespace std;
#include"Piece.h"
Piece::Piece()

{
	colour = Yellow;
	symbol = 'A';
	row = -1;
	column = -1;
	occupied = 0;


}

void Piece::printcantmove() const
{
	cout << "\nCan't move";
}


bool Piece::check(Move& m1)
{
	if (m1.symbol == 'K')
		return 1;
	else
		return 0;
}
void Piece::printcheck(Move& m2) const
{ 
	if (m2.colour == 1)
	{
		cout << "\nWhite King is in Check";
		}
	else
	{
		cout << "\nBlack King is in Check";
	}
	Sleep(800);
}

void Piece::printcantcapture() const
{
	cout << "\nCan't capture";
}
void Piece::moveapiece(Move& m1)
{//is main main check nhi kr rha kuch directly tb call kr rha hoon jb piece move krni ha

	row = m1.row;
	column = m1.column;
	m1.row = -1;
	m1.column = -1;
	occupied = 0;
}

bool Piece::checkmate()
{
	return 0;
}
void Piece::printcheckmate()const
{
	cout << "\nCheck Mate!!";
	exit(0);
}