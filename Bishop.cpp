#include "Bishop.h"
#include<algorithm>
using namespace std;
Bishop::Bishop(Color c, int num1, int num2)
{
	colour = c;
	symbol = 'B';
	row = num1;
	column = num2;
	occupied = 1;
}
Bishop::Bishop()
{}
bool Bishop::legalsquarestomove(Board& b1, Move& m1, Move& m2)
{
	
	if (m1.row == m2.row || m1.column == m2.column)
		return false;
	if (leftdiagnolfree(b1, m1, m2) || rightdiagnolfree(b1, m1, m2))
		return true;
	else 
		return false;
}
bool Bishop::leftdiagnolfree(Board& b1, Move& m1, Move& m2) 
{ 
	int num = abs(m1.row- m2.row);
	int row=min(m1.row , m2.row);
	int column = min(m1.column, m2.column);
	if (column + num == m1.column || column + num == m2.column)
	{
		if (row == m1.row && column == m1.column || column == m2.column && row == m2.row)
		{
			for (int i = 1; i < num; i++)
			{
				if (b1.boardptr[row + i][column + i] != nullptr)
					return false;
			
			}
			return true;
		}
		else
			return false;
	}
	else
		return false;
}


bool Bishop::rightdiagnolfree(Board& b1, Move& m1, Move& m2)
{
	int num = abs(m1.row - m2.row);
	int row = max(m1.row, m2.row);
	int column = min(m1.column, m2.column);
	if (column + num == m1.column || column + num == m2.column)
	{
		if (row == m1.row && column == m1.column || column == m2.column && row == m2.row)
		{
			for (int i = 1; i < num; i++)
			{
				if (b1.boardptr[row - i][column + i] != nullptr)
					return false;
				

			}
			return true;
		}
		else
			return false;
	}

	else
		return false;

}
bool Bishop::capture(Board& b1, Move& m1, Move& m2) 
{
	if (m1.colour != m2.colour)
	{
		if(legalsquarestomove(b1,m1,m2))
			return true;
		else
			return false;

	}
	else
		return false;
}