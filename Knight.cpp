#include "Knight.h"

Knight::Knight(Color c, int num1, int num2)
{
	colour = c;
	symbol = 'N';
	row = num1;
	column = num2;
	occupied = 1;
}
Knight::Knight(){}
bool Knight::legalsquarestomove(Board& b1, Move& m1, Move& m2)
{

	if (m1.row + 1 == m2.row && m1.column - 2 == m2.column ||
		m1.row + 1 == m2.row && m1.column + 2 == m2.column ||
		m1.row - 1 == m2.row && m1.column - 2 == m2.column ||
		m1.row - 1 == m2.row && m1.column + 2 == m2.column ||
		m1.row + 2 == m2.row && m1.column - 1 == m2.column ||
		m1.row + 2 == m2.row && m1.column + 1 == m2.column ||
		m1.row - 2 == m2.row && m1.column - 1 == m2.column ||
		m1.row - 2 == m2.row && m1.column + 1 == m2.column)
		return true;
	else
		return false;

}

bool Knight::capture(Board& b1, Move& m1, Move& m2)
{
	if (m1.colour != m2.colour)
	{
		bool choice = legalsquarestomove(b1, m1, m2);
		if (choice == 1)
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}