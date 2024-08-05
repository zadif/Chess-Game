#include "Pawn.h"
#include"Queen.h"
#include<iostream>
using namespace std;

Pawn::Pawn(Color c, int num1, int num2)
{
	colour = c;
	symbol = 'P';
	row = num1;
	column = num2;
	occupied = 1;

}

bool Pawn::legalsquarestomove(Board& b1, Move& m1, Move& m2)
{


	if (m1.colour == 1)
	{
		if ((m1.row == 1 && m2.row == 3 || m1.row == 1 && m2.row == 2) && m1.column == m2.column)
			return true;
		else if ((m1.row) == 6 && (m2.row) == 7 )
			pawnpromotion(b1, m1, m2);
		else if ((m1.row + 1) == m2.row && m1.column == m2.column)
			return true;
		else
			return false;
	}
	else if (m1.colour == 0)
	{
		if (m1.row == 6 && m2.row == 5 || m1.row == 6 && m2.row == 4)
			return true;
		else if ((m1.row) == 1 && (m2.row) == 0)
			pawnpromotion(b1, m1, m2);
		else if ((m1.row - 1) == m2.row && m1.column == m2.column)
			return true;
		else return false;
	}

}
void Pawn::pawnpromotion(Board& b1, Move& m1, Move& m2)
{


	cout << "\nPawn Promotion";
	cout << "\nWhat do you want to promote your pawn into?";
	cout<<"\nPress 1 to promote to Queen";
	cout<<"\nPress 2 to promote to Rook";
	cout<<"\nPress 3 to promote to Bishop";
	cout <<"\nPress 4 to promote to Knight\nEnter Your choice: ";
	int num;
	cin >> num;
	switch (num)
	{
	case 1:
	
		b1.boardptr[m1.row][m1.column] = new Queen(m1.colour, m2.row, m2.column);
		break;
	case 2:
		
		b1.boardptr[m1.row][m1.column] = new Rook(m1.colour, m2.row, m2.column);
		break;
	case 3:
	
		b1.boardptr[m1.row][m1.column] = new Bishop(m1.colour, m2.row, m2.column);
		break;
	case 4:
		
		b1.boardptr[m1.row][m1.column] = new Knight(m1.colour, m2.row, m2.column);
		break;
	}
}
bool Pawn::leftdiagnolcapture(Move& m1, Move& m2)
{
	bool chose = 0;
	if (m1.colour == White)
	{
		if (m2.colour == Black)
		{
			if (m1.row + 1 == m2.row && m1.column - 1 == m2.column)
			{

				chose = 1;
			}
		}
		else
		{
			printcantcapture();
			chose = 0;
		}
	}
	else
	{
		if (m2.colour == White)
		{
			if (m1.row - 1 == m2.row && m1.column - 1 == m2.column)
			{

				chose = 1;
			}
		}

		else
		{
			printcantcapture();
			chose = 0;
		}
	}
	return chose;
}

bool Pawn::rightdiagnolcapture(Move& m1, Move& m2)
{
	bool chose = 0;
	if (m1.colour == White)
	{

		if (m2.colour == Black)
		{
			if (m1.row + 1 == m2.row && m1.column + 1 == m2.column)
			{
				chose = 1;
			}
		}
		else {
			printcantcapture();
			chose = 0;
		}
	}
	else
	{
		if (m2.colour == White)
		{
			if (m1.row - 1 == m2.row && m1.column + 1 == m2.column)
			{
				chose = 1;
			}
		}
		else
		{
			printcantcapture();
			chose = 0;
		}
	}
	return chose;
}

bool Pawn::capture(Board& b1, Move& m1, Move& m2)
{
	bool ch1, ch2;

	ch1 = leftdiagnolcapture(m1, m2);

	ch2 = rightdiagnolcapture(m1, m2);

	if (ch1 == 1 || ch2 == 1)
	{
		if ((m1.row) == 6 && (m2.row) == 7 || (m1.row) == 1 && (m2.row) == 0)
		pawnpromotion(b1, m1, m2);
		return true;
	}
	else
		return false;

}