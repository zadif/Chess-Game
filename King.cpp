#include"King.h"
King::King(){}
King::King(Color c,int num,int num2)
{
	colour = c;
	symbol = 'K';
	row = num;
	column = num2;
	occupied = 1;
}
bool King::capture(Board& b1, Move& m1, Move& m2)
{
	if (m1.colour != m2.colour)
	{
		if (legalsquarestomove(b1, m1, m2))
			return true;
		else
			return false;
	}
	else
		return false;

}
bool King::legalsquarestomove(Board& b1, Move& m1, Move& m2)
{
	if (m1.row + 1 == m2.row && m1.column == m2.column ||
		m1.row + 1 == m2.row && m1.column + 1 == m2.column ||
		m1.row + 1 == m2.row && m1.column - 1 == m2.column ||
		m1.row == m2.row && m1.column - 1 == m2.column ||
		m1.row == m2.row && m1.column + 1 == m2.column ||
		m1.row - 1 == m2.row && m1.column - 1 == m2.column ||
		m1.row - 1 == m2.row && m1.column == m2.column ||
		m1.row - 1 == m2.row && m1.column + 1 == m2.column)
		return true;
	else
		return false;
}





