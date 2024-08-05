#include "Queen.h"

Queen::Queen(Color c, int num1, int num2) :Rook(c, num1, num2) { Rook::symbol = 'Q'; }
Queen::Queen() {}
bool Queen::capture(Board& b1, Move& m1, Move& m2)
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
bool Queen::legalsquarestomove(Board& b1, Move& m1, Move& m2)
{
	if (Rook::legalsquarestomove(b1, m1, m2) || Bishop::legalsquarestomove(b1, m1, m2))
		return true;
	else
		return false;

}