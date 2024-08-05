#pragma once
#include"Move.h"
#include<iostream>
using namespace std;
class Player
{
	string name;
	Color c;
public:
	Player();
	Player(string a, Color c);
	string getname();
	Color getcolor();
	void setplayer1();
	void setplayer2();


	Move makeamove();
	
};
