#include "Player.h"

Player::Player() { name = "Allen"; c = Yellow; }
Player::Player(string a, Color c) :name(a), c(c) {}
Move Player:: makeamove()
{
	string st;
	Move m1;
	

	if (c == White)
		st = "White";
	else
		st = "Black";

	m1.colour = c;

	cout << "\nMove of " << st << " is: ";

	string str;
	cin >> str;
	int length = str.length();
	if (length > 2 && length < 6)

	{
		if (length == 3)
		{
			if (str == "0-0")//Agr king side castle ha phir direct m1 ja rha ha ismy colour yellow ha aur row aur column -1
				return m1;

			m1.symbol = str[0];
			m1.column = str[1] - 97;
			m1.row = str[2] - '1';
			if (m1.column < 8 && m1.column>-1 && m1.row < 8 && m1.row>-1 && (m1.symbol == 'K' || m1.symbol == 'P' || m1.symbol == 'Q' || m1.symbol == 'R' || m1.symbol == 'N' || m1.symbol == 'B' || m1.symbol == 'C'))
				return m1;
			else {
				cout << "\nWrong move";
				makeamove();
			}

		}
		else if (length == 4)
		{
			if (str[1] == 'x')
			{
				m1.symbol = str[0];
				m1.column = str[2] - 97;
				m1.row = str[3] - '1';
				m1.occupied = 1;//jaha piece capture krna ha uska occupy 1 krdia 
				if (m1.column < 8 && m1.column>-1 && m1.row < 8 && m1.row>-1 && (m1.symbol == 'K' || m1.symbol == 'P' || m1.symbol == 'Q' || m1.symbol == 'R' || m1.symbol == 'N' || m1.symbol == 'B' || m1.symbol == 'C'))
					return m1;
				else {
					cout << "\nWrong move";
					makeamove();
				}
			}
			else {
				cout << "\nWrong move";
				makeamove();
			}
		}
		else if (length == 5)
		{
			if (str == "0-0-0")
			{//agr longside castle ha phir row aur column 0 hain 
				//dono castling main colour yellow ha
				
				m1.occupied = 1;
				return m1;
			}
			else {
				cout << "\nWrong move";
				makeamove();
			}

		}
	}
	else
	{
		cout << "\nWrong move";
		makeamove();
	}




}

void Player:: setplayer1()
{
	cout << "\nEnter name of player with White: ";
	string str;
	cin >> str;
	name = str;
	c = White;
}
void Player:: setplayer2()
{
	cout << "\nEnter name of player with Black: ";
	string str;
	cin >> str;
	name = str;
	c = Black;
}

string Player::getname() { return name; }
Color  Player::getcolor() { return c; }