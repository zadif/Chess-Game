#include "Chess.h"
#include"Queen.h"


bool choose, wcheck = 0, bcheck = 0, wcheckmate = 0, bcheckmate = 0;
Move player1currentposition, player2currentposition, player1move, player2move, wkinglocation, bkinglocation, wqueenlocation, bqueenlocation, brook1location, brook2location, wrook1location, wrook2location, bbishop1location, bbishop2location, wbishop1location, wbishop2location, wknight1location, wknight2location, bknight1location, bknight2location, bcamellocation, wcamellocation;
char wpiecetocapture, bpiecetocapture;
bool talgambit = 0;
Chess::Chess()
{
	p1.setplayer1();
	p2.setplayer2();
}
void Chess::playchess()
{

	player1currentposition.colour = White;
	player2currentposition.colour = Black;
	wkinglocation.colour = White;
	bkinglocation.colour = Black;
	wqueenlocation.colour = White;
	bqueenlocation.colour = Black;
	brook1location.colour = Black;
	brook2location.colour = Black;
	wrook1location.colour = White;
	wrook2location.colour = White;
	bbishop1location.colour = Black;
	bbishop2location.colour = Black;
	wbishop1location.colour = White;
	wbishop2location.colour = White;
	wknight1location.colour = White;
	wknight2location.colour = White;
	bknight1location.colour = Black;
	bknight2location.colour = Black;
	

	do
	{

		b1.drawboard();
		play1();
		if (player1move.column != -1 && player1move.row != -1)//castling ka exception rokny ky liy
		{
			getking(bkinglocation);
			bcheck = check(player1move, bkinglocation);
			if (bcheck)
			{
				cout << "\nBlack King is in check";
				Sleep(800);
			}
		}
		if (wcheckmate)
		{
			checkmate();
			return;
		}
		b1.drawboard();
		b1.writeinfile(b1, "Chess1.txt");
		play2();
		if (player2move.column != -1 && player2move.row != -1)//castling ka exception rokny ky liy
		{
			getking(wkinglocation);
			wcheck = check(player2move, wkinglocation);
			if (wcheck)
			{
				cout << "\nWhite King is in check";
				Sleep(800);
			}
		}
		if (bcheckmate)
		{
			checkmate();
			return;
		}
		b1.writeinfile(b1, "Chess1.txt");
	} while (1);

}
void Chess::playkingrush()
{

	player1currentposition.colour = White;
	player2currentposition.colour = Black;
	wkinglocation.colour = White;
	bkinglocation.colour = Black;
	wqueenlocation.colour = White;
	bqueenlocation.colour = Black;
	brook1location.colour = Black;
	brook2location.colour = Black;
	wrook1location.colour = White;
	wrook2location.colour = White;
	bbishop1location.colour = Black;
	bbishop2location.colour = Black;
	wbishop1location.colour = White;
	wbishop2location.colour = White;
	wknight1location.colour = White;
	wknight2location.colour = White;
	bknight1location.colour = Black;
	bknight2location.colour = Black;
	

	do
	{

		b1.drawboard();
		play1();
		if (player1move.column != -1 && player1move.row != -1)//castling ka exception rokny ky liy
		{
			getking(wkinglocation);
			getking(bkinglocation);
			bcheck = check(player1move, bkinglocation);
			if (bcheck)
			{
				cout << "\nBlack King is in check";
				Sleep(1000);
				checkmate();
				return;
			}
			kingrushtoprowcondition(wkinglocation);
		}

		b1.drawboard();
		b1.writeinfile(b1, "Chess2.txt");
		play2();
		if (player2move.column != -1 && player2move.row != -1)//castling ka exception rokny ky liy
		{
			getking(bkinglocation);
			getking(wkinglocation);
			wcheck = check(player2move, wkinglocation);
			if (wcheck)
			{
				cout << "\nWhite King is in check";
				Sleep(1000);
				checkmate();
				return;
			}
			kingrushtoprowcondition(bkinglocation);
		}
		b1.writeinfile(b1, "Chess2.txt");

	} while (1);

}
void Chess::playtalgambit()
{
	talgambit = 1;
	player1currentposition.colour = White;
	player2currentposition.colour = Black;
	wkinglocation.colour = White;
	bkinglocation.colour = Black;
	wqueenlocation.colour = White;
	bqueenlocation.colour = Black;
	brook1location.colour = Black;
	brook2location.colour = Black;
	wrook1location.colour = White;
	wrook2location.colour = White;
	bbishop1location.colour = Black;
	bbishop2location.colour = Black;
	wbishop1location.colour = White;
	wbishop2location.colour = White;
	wknight1location.colour = White;
	wknight2location.colour = White;
	bknight1location.colour = Black;
	bknight2location.colour = Black;
	

	do
	{

		b1.drawboard();
		play1();
		if (player1move.column != -1 && player1move.row != -1)//castling ka exception rokny ky liy
		{
			getking(bkinglocation);
			bcheck = check(player1move, bkinglocation);
			if (bcheck)
			{
				cout << "\nBlack King is in check";
				Sleep(800);
			}
		}
		if (wcheckmate)
		{
			checkmate();
			return;
		}
		b1.drawboard();
		b1.writeinfile(b1, "Chess3.txt");

		play2();
		if (player2move.column != -1 && player2move.row != -1)//castling ka exception rokny ky liy
		{
			getking(wkinglocation);
			wcheck = check(player2move, wkinglocation);
			if (wcheck)
			{
				cout << "\nWhite King is in check";
				Sleep(800);
			}
		}
		if (bcheckmate)
		{
			checkmate();
			return;
		}
		b1.writeinfile(b1, "Chess3.txt");
	} while (1);

}



void Chess::currentposition(Move& m1)
{

	cout << "\nCurrent position of piece you want to move for ";
	if (m1.colour == 1)
		cout << "white: ";
	else
		cout << "black: ";
	string str;
	cin >> str;
	int length = str.length();
	if (length == 3)
	{
		m1.symbol = str[0];
		m1.column = str[1] - 97;
		m1.row = str[2] - '1';
		if (b1.boardptr[m1.row][m1.column] == nullptr)
		{
			cout << "\nThe piece is not where you mentioned";
			currentposition(m1);
		}
		if ((m1.row >= 0 || m1.row <= 7 && m1.column >= 0 || m1.column <= 7) && (m1.symbol == 'K' || m1.symbol == 'P' || m1.symbol == 'Q' || m1.symbol == 'R' || m1.symbol == 'N' || m1.symbol == 'B' || m1.symbol == 'C'))
		{
			if (b1.boardptr[m1.row][m1.column]->colour == m1.colour)
			{
				if (b1.boardptr[m1.row][m1.column]->symbol == m1.symbol)
					return;
				else {
					cout << "\nThe piece is not where you mentioned";
					currentposition(m1);
				}
			}
			else {
				cout << "\nThe piece is of not your colour";
				currentposition(m1);
			}
		}
		else {
			cout << "\nWrong move";
			currentposition(m1);
		}


	}
	else {
		cout << "\nWrong move";
		currentposition(m1);
	}

}
void Chess::play1()
{
	if (wcheck)
	{
		bool cancapturee = 1;
		getking(wkinglocation);
		
		if (talgambit)
			getcamel(bcamellocation);
		else
			getqueen(bqueenlocation);
		getrook(brook1location, brook2location);
		getbishop(bbishop1location, bbishop2location);
		getknight(bknight1location, bknight2location);
		player2move.colour = White;
		player2move.symbol = b1.boardptr[player2move.row][player2move.column]->symbol;
		if(talgambit)
			cancapturee = kingcapture(wkinglocation, player2move, bcamellocation, brook1location, brook2location, bbishop1location, bbishop2location, bknight1location, bknight2location);
		else
		cancapturee = kingcapture(wkinglocation, player2move, bqueenlocation, brook1location, brook2location, bbishop1location, bbishop2location, bknight1location, bknight2location);
		if (!cancapturee)
		{
			if (talgambit)
				getcamel(wcamellocation);
			else
			getqueen(wqueenlocation);
			getrook(wrook1location, wrook2location);
			getbishop(wbishop1location, wbishop2location);
			getknight(wknight1location, wknight2location);
			player2move.colour = Black;
			cancapturee = kingcapture(wkinglocation, player2move, wqueenlocation, wrook1location, wrook2location, wbishop1location, wbishop2location, wknight1location, wknight2location);
			if (cancapturee)//agr cancapture main 0 ha mtlb koi piece ha jo checkmate prevent kr rhi ha 
			{               //aur agr 1 ha mtlb koi cheez nhi rok skti checkmate function ki usability ko change kia ha yaha bs
				wcheckmate = true;

				return;
			}
		}

	}

	currentposition(player1currentposition);
	player1move = p1.makeamove();

	if (player1move.row == -1 && player1move.column == -1 && player1move.occupied == 0)//castling ka exception throw rokny ky liyy
	{
		Move dummymove1, dummymove2;
		dummymove1.row = 0;
		dummymove1.column = 5;
		dummymove1.colour = White;
		dummymove1.symbol = 'B';
		dummymove2.row = 0;
		dummymove2.column = 6;
		dummymove2.colour = White;
		dummymove2.symbol = 'N';
		getking(wkinglocation);
		if (talgambit)
			getcamel(bcamellocation);
		else
		getqueen(bqueenlocation);
		getrook(brook1location, brook2location);
		getbishop(bbishop1location, bbishop2location);
		getknight(bknight1location, bknight2location);


		bool castle = 1;

		if (!wkinglocation.piecemoved)
		{
			getrook(wrook1location, wrook2location);
			if (!wrook2location.piecemoved)
			{
				if (talgambit)
					castle = kingsidecastle(wkinglocation, dummymove1, dummymove2, bcamellocation, brook1location, brook2location, bbishop1location, bbishop2location, bknight1location, bknight2location);
				else
				castle = kingsidecastle(wkinglocation, dummymove1, dummymove2, bqueenlocation, brook1location, brook2location, bbishop1location, bbishop2location, bknight1location, bknight2location);
			}
			else
			{
				cout << "\nCan't castle king side because rook has moved from his home square";
				castle = 0;
			}
		}
		else
		{
			cout << "\nCan't castle king side because king has moved from his home square";
			castle = 0;
		}

		if (castle)
		{
			makemove(0, 4, 0, 6);
			makemove(0, 7, 0, 5);
			return;
		}
		else
		{

			play1();
		}
	}
	else if (player1move.row == -1 && player1move.column == -1 && player1move.occupied == 1)
	{
		Move dummymove1, dummymove2, dummymove3;
		dummymove1.row = 0;
		dummymove1.column = 3;
		dummymove1.colour = White;
		dummymove1.symbol = 'Q';
		dummymove2.row = 0;
		dummymove2.column = 2;
		dummymove2.colour = White;
		dummymove2.symbol = 'B';
		dummymove3.row = 0;
		dummymove3.column = 1;
		dummymove3.colour = White;
		dummymove3.symbol = 'N';
		getking(wkinglocation);
		if (talgambit)
			getcamel(bcamellocation);
		else
		getqueen(bqueenlocation);
		getrook(brook1location, brook2location);
		getbishop(bbishop1location, bbishop2location);
		getknight(bknight1location, bknight2location);

		bool castle = 1;

		if (!wkinglocation.piecemoved)
		{
			getrook(wrook1location, wrook2location);
			if (!wrook1location.piecemoved)
			{
				if (talgambit)
					castle = queensidecastle(wkinglocation, dummymove1, dummymove2, dummymove3, bcamellocation, brook1location, brook2location, bbishop1location, bbishop2location, bknight1location, bknight2location);
				else
				castle = queensidecastle(wkinglocation, dummymove1, dummymove2, dummymove3, bqueenlocation, brook1location, brook2location, bbishop1location, bbishop2location, bknight1location, bknight2location);
			}
			else
			{
				cout << "\nCan't castle queen side because rook has moved from his home square";
				castle = 0;
			}
		}
		else
		{
			cout << "\nCan't castle queen side because king has moved from his home square";
			castle = 0;
		}

		if (castle)
		{
			makemove(0, 4, 0, 2);
			makemove(0, 0, 0, 3);
			return;
		}
		else
		{

			play1();
		}
	}
	if (b1.boardptr[player1move.row][player1move.column] == nullptr)
	{
		player1move.colour = Yellow;
	}
	else
	{//Jo rang move wala square pr hoga(pointer sa dekha ha) wo player1move ko dia 
		player1move.colour = b1.boardptr[player1move.row][player1move.column]->colour;
	}


	if (player1move.occupied == 0)
	{//piece move krna ha
		if (player1move.colour == Yellow)
		{
			choose = b1.boardptr[player1currentposition.row][player1currentposition.column]->legalsquarestomove(b1, player1currentposition, player1move);


			if (choose == 1)
			{
				makemove(player1currentposition.row, player1currentposition.column, player1move.row, player1move.column);
				b1.boardptr[player1move.row][player1move.column]->piecemoved = 1;

				player1move.colour = White;

				if (wcheck)
				{
					getking(wkinglocation);
					wcheck = check(player2move, wkinglocation);
					if (wcheck)
					{
						cout << "\nYour king is in check\nYou can't make this move\nMake move again";
						Sleep(1000);
						makemove(player1move.row, player1move.column, player1currentposition.row, player1currentposition.column);

						b1.drawboard();
						play1();
					}

				}
				if (talgambit)
				{
					if (b1.boardptr[7][3] == nullptr || b1.boardptr[7][3]->symbol != 'C')
					{
						getking(wkinglocation);
						getcamel(bcamellocation);
						if (camelcheck(bcamellocation, wkinglocation, player1currentposition, player1move))
							play1();
					}
				}
				if (!talgambit)
				{
					if (b1.boardptr[7][3] == nullptr || b1.boardptr[7][3]->symbol != 'Q')
					{
						getking(wkinglocation);
						getqueen(bqueenlocation);
						if (queencheck(bqueenlocation, wkinglocation, player1currentposition, player1move))
							play1();
					}
				}
				if ((b1.boardptr[7][0] == nullptr || b1.boardptr[7][0]->symbol != 'R') || (b1.boardptr[7][7] == nullptr || b1.boardptr[7][7]->symbol != 'R'))
				{
					getking(wkinglocation);
					getrook(brook1location, brook2location);
					if (rookcheck(brook1location, wkinglocation, player1currentposition, player1move))
						play1();
					else if (rookcheck(brook2location, wkinglocation, player1currentposition, player1move))
						play1();
				}
				if ((b1.boardptr[7][2] == nullptr || b1.boardptr[7][2]->symbol != 'B') || (b1.boardptr[7][5] == nullptr || b1.boardptr[7][5]->symbol != 'B'))
				{
					getking(wkinglocation);
					getbishop(bbishop1location, bbishop2location);
					if (bishopcheck(bbishop1location, wkinglocation, player1currentposition, player1move))
						play1();
					else if (bishopcheck(bbishop2location, wkinglocation, player1currentposition, player1move))
						play1();
				}
				if ((b1.boardptr[7][1] == nullptr || b1.boardptr[7][1]->symbol != 'N') || (b1.boardptr[7][6] == nullptr || b1.boardptr[7][6]->symbol != 'N'))
				{
					getking(bkinglocation);
					getknight(wknight1location, wknight2location);
					if (knightcheck(wknight1location, bkinglocation, player2currentposition, player2move))
						play2();
					else if (bishopcheck(wknight2location, bkinglocation, player2currentposition, player2move))
						play2();
				}

				return;
			}
			else {
				cout << "\nIllegal move";
				Sleep(800);
				play1();
			}
		}
		else {
			cout << "\nIllegal move";
			Sleep(800);
			play1();
		}
	}
	else if (player1move.occupied == 1)
	{//piece  capture krna ha

		if (player1move.colour == Yellow)
		{
			cout << "\nCan't capture";
			Sleep(800);
			play1();
		}

		choose = b1.boardptr[player1currentposition.row][player1currentposition.column]->capture(b1, player1currentposition, player1move);

		if (choose == 1)
		{
			if (wcheck)
			{
				if ((player2move.row == player1move.row && player2move.column == player1move.column))
				{
					if (player1currentposition.symbol == 'K')
					{//agr badshah koi piece capture krny lga ha jb wo check main ha tb ye dekhna ha koi us piece ko protect tu nhi kr rha 
						bool cancapture = 1;
						getking(wkinglocation);
						getqueen(bqueenlocation);
						getrook(brook1location, brook2location);
						getbishop(bbishop1location, bbishop2location);
						getknight(bknight1location, bknight2location);
						player1move.colour = White;//iss liyy ta ka jbb aghy capture check krna ha waha msla na ho
						player1move.symbol = b1.boardptr[player1move.row][player1move.column]->symbol;

						cancapture = kingcapture(wkinglocation, player1move, bqueenlocation, brook1location, brook2location, bbishop1location, bbishop2location, bknight1location, bknight2location);
						if (!cancapture)
						{
							cout << "\nCan't capture";
							play1();
						}

					}
					makemove(player1currentposition.row, player1currentposition.column, player1move.row, player1move.column);
					b1.boardptr[player1move.row][player1move.column]->piecemoved = 1;
					player1move.colour = White;
				}
				else

				{
					cout << "\nYour king is in check\nYou can't make this move\nMake move again";
					Sleep(1000);
					b1.drawboard();
					play1();

				}

			}
			else
			{
				if (player1currentposition.symbol == 'K')
				{//agr king koi piece capture krny lga ha tu dekhna ka wo kahi kisi pawn sa protected na ho
					if (b1.boardptr[player1move.row + 1][player1move.column - 1]->symbol == 'P' || b1.boardptr[player1move.row + 1][player1move.column + 1]->symbol == 'P')
					{
						cout << "\nCan't capture";
						Sleep(800);
						play1();
					}
				}
				bpiecetocapture = b1.boardptr[player1move.row][player1move.column]->symbol;
				makemove(player1currentposition.row, player1currentposition.column, player1move.row, player1move.column);
				if (talgambit)
				{
					if (b1.boardptr[7][3] == nullptr || b1.boardptr[7][3]->symbol != 'C')
					{
						if (player1currentposition.symbol == 'K')//Agr badshah salamat capture kr rhy hain tu dubara sy badshah ki new location nikalni ha
							getking(wkinglocation);
						getcamel(bcamellocation);
						if (camelcheck(bcamellocation, wkinglocation, player1currentposition, player1move))
							play1();
					}
				}
				if (!talgambit)
				{
					if (b1.boardptr[7][3] == nullptr || b1.boardptr[7][3]->symbol != 'Q')
					{
						if (player1currentposition.symbol == 'K')//Agr badshah salamat capture kr rhy hain tu dubara sy badshah ki new location nikalni ha
							getking(wkinglocation);
						getqueen(bqueenlocation);
						if (queencheck(bqueenlocation, wkinglocation, player1currentposition, player1move))
							play1();
					}
				}
				if ((b1.boardptr[7][0] == nullptr || b1.boardptr[7][0]->symbol != 'R') || (b1.boardptr[7][7] == nullptr || b1.boardptr[7][7]->symbol != 'R'))
				{
					if (player1currentposition.symbol == 'K')//Agr badshah salamat capture kr rhy hain tu dubara sy badshah ki new location nikalni ha
						getking(wkinglocation);
					getrook(brook1location, brook2location);
					if (rookcheck(brook1location, wkinglocation, player1currentposition, player1move))
						play1();
					else if (rookcheck(brook2location, wkinglocation, player1currentposition, player1move))
						play1();
				}
				if ((b1.boardptr[7][2] == nullptr || b1.boardptr[7][2]->symbol != 'B') || (b1.boardptr[7][5] == nullptr || b1.boardptr[7][5]->symbol != 'B'))
				{
					if (player1currentposition.symbol == 'K')//Agr badshah salamat capture kr rhy hain tu dubara sy badshah ki new location nikalni ha
						getking(wkinglocation);
					getbishop(bbishop1location, bbishop2location);
					if (bishopcheck(bbishop1location, wkinglocation, player1currentposition, player1move))
						play1();
					else if (bishopcheck(bbishop2location, wkinglocation, player1currentposition, player1move))
						play1();
				}
				if ((b1.boardptr[7][1] == nullptr || b1.boardptr[7][1]->symbol != 'N') || (b1.boardptr[7][6] == nullptr || b1.boardptr[7][6]->symbol != 'N'))
				{
					if (player1currentposition.symbol == 'K')
						getking(bkinglocation);
					getknight(wknight1location, wknight2location);
					if (knightcheck(wknight1location, bkinglocation, player2currentposition, player2move))
						play2();
					else if (bishopcheck(wknight2location, bkinglocation, player2currentposition, player2move))
						play2();
				}
				player1move.colour = White;
				return;
			}
		}
		else {
			cout << "\nCan't capture";
			Sleep(800);
			play1();
		}

	}

}
void Chess::play2()
{
	if (bcheck)
	{
		bool cancapturee = 1;
		getking(bkinglocation);
		if (talgambit)
			getcamel(wcamellocation);
		else
		getqueen(wqueenlocation);
		getrook(wrook1location, wrook2location);
		getbishop(wbishop1location, wbishop2location);
		getknight(wknight1location, wknight2location);
		player1move.colour = Black;
		player1move.symbol = b1.boardptr[player1move.row][player1move.column]->symbol;
		if (talgambit)
			cancapturee = kingcapture(bkinglocation, player1move, wcamellocation, wrook1location, wrook2location, wbishop1location, wbishop2location, wknight1location, wknight2location);
		else
		cancapturee = kingcapture(bkinglocation, player1move, wqueenlocation, wrook1location, wrook2location, wbishop1location, wbishop2location, wknight1location, wknight2location);

		if (!cancapturee)
		{
			if (talgambit)
				getcamel(bcamellocation);
			else
			getqueen(bqueenlocation);
			getrook(brook1location, brook2location);
			getbishop(bbishop1location, bbishop2location);
			getknight(bknight1location, bknight2location);
			player2move.colour = White;
			if (talgambit)
				cancapturee = kingcapture(wkinglocation, player1move, bcamellocation, brook1location, brook2location, bbishop1location, bbishop2location, bknight1location, bknight2location);
			else
			cancapturee = kingcapture(wkinglocation, player1move, bqueenlocation, brook1location, brook2location, bbishop1location, bbishop2location, bknight1location, bknight2location);

			if (cancapturee)//agr cancapture main 0 ha mtlb koi piece ha jo checkmate prevent kr rhi ha 
			{               //aur agr 1 ha mtlb koi cheez nhi rok skti checkmate function ki usability ko change kia ha yaha bs
				bcheckmate = true;

				return;
			}
		}

	}
	currentposition(player2currentposition);
	player2move = p2.makeamove();
	if (player2move.row == -1 && player2move.column == -1 && player2move.occupied == 0)//castling ka exception throw rokny ky liyy
	{
		Move dummymove1, dummymove2;
		dummymove1.row = 7;
		dummymove1.column = 5;
		dummymove1.colour = Black;
		dummymove1.symbol = 'B';
		dummymove2.row = 7;
		dummymove2.column = 6;
		dummymove2.colour = Black;
		dummymove2.symbol = 'N';
		getking(bkinglocation);
		if (talgambit)
			getcamel(wcamellocation);
		else
		getqueen(wqueenlocation);
		getrook(wrook1location, wrook2location);
		getbishop(wbishop1location, wbishop2location);
		getknight(wknight1location, wknight2location);

		bool castle = 1;

		if (!bkinglocation.piecemoved)
		{
			getrook(brook1location, brook2location);
			if (!brook2location.piecemoved)
			{
				castle = kingsidecastle(bkinglocation, dummymove1, dummymove2, wqueenlocation, wrook1location, wrook2location, wbishop1location, wbishop2location, wknight1location, wknight2location);
			}
			else
			{
				cout << "\nCan't castle king side because rook has moved from his home square";
				castle = 0;
			}
		}
		else
		{
			cout << "\nCan't castle king side because king has moved from his home square";
			castle = 0;
		}

		if (castle)
		{
			makemove(7, 4, 7, 6);
			makemove(7, 7, 7, 5);
			return;
		}
		else
		{

			play1();
		}
	}
	else if (player2move.row == -1 && player2move.column == -1 && player2move.occupied == 1)
	{
		Move dummymove1, dummymove2, dummymove3;
		dummymove1.row = 7;
		dummymove1.column = 3;
		dummymove1.colour = Black;
		dummymove1.symbol = 'Q';
		dummymove2.row = 7;
		dummymove2.column = 2;
		dummymove2.colour = Black;
		dummymove2.symbol = 'B';
		dummymove3.row = 7;
		dummymove3.column = 1;
		dummymove3.colour = Black;
		dummymove3.symbol = 'N';
		getking(bkinglocation);
		if (talgambit)
			getcamel(wcamellocation);
		else
		getqueen(wqueenlocation);
		getrook(wrook1location, wrook2location);
		getbishop(wbishop1location, wbishop2location);
		getknight(wknight1location, wknight2location);


		bool castle = 1;

		if (!bkinglocation.piecemoved)
		{
			getrook(brook1location, brook2location);
			if (!brook1location.piecemoved)
			{
				if (talgambit)
					castle = queensidecastle(bkinglocation, dummymove1, dummymove2, dummymove3, wcamellocation, wrook1location, wrook2location, wbishop1location, wbishop2location, wknight1location, wknight2location);
				else
				castle = queensidecastle(bkinglocation, dummymove1, dummymove2, dummymove3, wqueenlocation, wrook1location, wrook2location, wbishop1location, wbishop2location, wknight1location, wknight2location);
			}
			else
			{
				cout << "\nCan't castle queen side because rook has moved from his home square";
				castle = 0;
			}
		}
		else
		{
			cout << "\nCan't castle queen side because king has moved from his home square";
			castle = 0;
		}

		if (castle)
		{
			makemove(7, 4, 7, 2);
			makemove(7, 0, 7, 3);
			return;
		}
		else
		{

			play2();
		}
	}
	if (b1.boardptr[player2move.row][player2move.column] == nullptr)
	{
		player2move.colour = Yellow;
	}
	else
	{//Jo rang move wala square pr hoga(pointer sa dekha ha) wo player1move ko dia 
		player2move.colour = b1.boardptr[player2move.row][player2move.column]->colour;
	}

	if (player2move.occupied == 0)
	{
		if (player2move.colour == Yellow)
		{
			choose = b1.boardptr[player2currentposition.row][player2currentposition.column]->legalsquarestomove(b1, player2currentposition, player2move);

			if (choose == 1)
			{
				makemove(player2currentposition.row, player2currentposition.column, player2move.row, player2move.column);
				b1.boardptr[player2move.row][player2move.column]->piecemoved = 1;


				player2move.colour = Black;
				if (bcheck)
				{
					getking(bkinglocation);
					bcheck = check(player1move, bkinglocation);
					if (bcheck)
					{
						cout << "\nYour king is in check\nYou can't make this move\nMake move again";
						Sleep(1000);
						makemove(player2move.row, player2move.column, player2currentposition.row, player2currentposition.column);

						b1.drawboard();
						play2();
					}

				}
				if (talgambit)
					{
					if (b1.boardptr[0][3] == nullptr || b1.boardptr[0][3]->symbol != 'C')
					{
						getking(bkinglocation);
						
							getcamel(wcamellocation);
						
						if (camelcheck(wcamellocation, bkinglocation, player2currentposition, player2move))
							play2();
					}
				}
				if (!talgambit)
				{
					if (b1.boardptr[0][3] == nullptr || b1.boardptr[0][3]->symbol != 'Q')
					{
						getking(bkinglocation);
						getqueen(wqueenlocation);
						if (queencheck(wqueenlocation, bkinglocation, player2currentposition, player2move))
							play2();
					}
				}
				if ((b1.boardptr[0][0] == nullptr || b1.boardptr[0][0]->symbol != 'R') || (b1.boardptr[0][7] == nullptr || b1.boardptr[0][7]->symbol != 'R'))
				{
					getking(bkinglocation);
					getrook(wrook1location, wrook2location);
					if (rookcheck(wrook1location, bkinglocation, player2currentposition, player2move))
						play2();
					else if (rookcheck(wrook2location, bkinglocation, player2currentposition, player2move))
						play2();
				}
				if ((b1.boardptr[0][2] == nullptr || b1.boardptr[0][2]->symbol != 'B') || (b1.boardptr[0][5] == nullptr || b1.boardptr[0][5]->symbol != 'B'))
				{
					getking(bkinglocation);
					getbishop(wbishop1location, wbishop2location);
					if (bishopcheck(wbishop1location, bkinglocation, player2currentposition, player2move))
						play2();
					else if (bishopcheck(wbishop2location, bkinglocation, player2currentposition, player2move))
						play2();
				}
				if ((b1.boardptr[0][1] == nullptr || b1.boardptr[0][1]->symbol != 'N') || (b1.boardptr[0][6] == nullptr || b1.boardptr[0][6]->symbol != 'N'))
				{
					getking(bkinglocation);
					getknight(wknight1location, wknight2location);
					if (knightcheck(wknight1location, bkinglocation, player2currentposition, player2move))
						play2();
					else if (bishopcheck(wknight2location, bkinglocation, player2currentposition, player2move))
						play2();
				}
				return;

			}
			else {
				cout << "\nIllegal move";
				Sleep(800);
				play2();
			}
		}
		else {
			cout << "\nIllegal move";
			Sleep(800);
			play2();
		}
	}
	else if (player2move.occupied == 1)
	{
		if (player2move.colour == Yellow)
		{
			cout << "\nCan't capture";
			Sleep(800);
			play2();
		}

		choose = b1.boardptr[player2currentposition.row][player2currentposition.column]->capture(b1, player2currentposition, player2move);

		if (choose == 1)
		{
			if (bcheck)
			{
				if ((player1move.row == player2move.row && player1move.column == player2move.column))
				{
					if (player2currentposition.symbol == 'K')
					{//agr badshah koi piece capture krny lga ha jb wo check main ha tb ye dekhna ha koi us piece ko protect tu nhi kr rha 
						bool cancapture = 1;
						getking(bkinglocation);
						if (talgambit)
							getcamel(wcamellocation);
						else
						getqueen(wqueenlocation);
						getrook(wrook1location, wrook2location);
						getbishop(wbishop1location, wbishop2location);
						getknight(wknight1location, wknight2location);
						player2move.colour = Black;//iss liyy ta ka jbb aghy capture check krna ha waha msla na ho
						player2move.symbol = b1.boardptr[player2move.row][player2move.column]->symbol;

						cancapture = kingcapture(bkinglocation, player2move, wqueenlocation, wrook1location, wrook2location, wbishop1location, wbishop2location, wknight1location, wknight2location);
						if (!cancapture)
						{
							cout << "\nCan't capture";
							play2();
						}

					}
					makemove(player2currentposition.row, player2currentposition.column, player2move.row, player2move.column);
					b1.boardptr[player2move.row][player2move.column]->piecemoved = 1;
					player2move.colour = Black;
				}
				else

				{
					cout << "\nYour king is in check\nYou can't make this move\nMake move again";
					Sleep(1000);
					b1.drawboard();
					play2();

				}
			}
			else
			{
				if (player2currentposition.symbol == 'K')
				{//agr king koi piece capture krny lga ha tu dekhna ka wo kahi kisi pawn sa protected na ho

					if ((b1.boardptr[player2move.row - 1][player2move.column - 1] != nullptr && b1.boardptr[player2move.row - 1][player2move.column - 1]->symbol == 'P') || (b1.boardptr[player2move.row - 1][player2move.column + 1] != nullptr && b1.boardptr[player2move.row - 1][player2move.column + 1]->symbol == 'P'))
					{
						cout << "\nCan't capture";
						Sleep(800);
						play2();
					}
				}
				wpiecetocapture = b1.boardptr[player2move.row][player2move.column]->symbol;

				makemove(player2currentposition.row, player2currentposition.column, player2move.row, player2move.column);
				if (talgambit)
				{
					if (b1.boardptr[0][3] == nullptr || b1.boardptr[0][3]->symbol != 'C')
					{
						if (player2currentposition.symbol == 'K')//Agr badshah salamat capture kr rhy hain tu dubara sy badshah ki new location nikalni ha
							getking(bkinglocation);

						getqueen(wqueenlocation);

						if (camelcheck(wcamellocation, bkinglocation, player2currentposition, player2move))
							play2();
					}
				}
				if (!talgambit)
				{
					if (b1.boardptr[0][3] == nullptr || b1.boardptr[0][3]->symbol != 'Q')
					{
						if (player2currentposition.symbol == 'K')//Agr badshah salamat capture kr rhy hain tu dubara sy badshah ki new location nikalni ha
							getking(bkinglocation);

						getqueen(wqueenlocation);

						if (queencheck(wqueenlocation, bkinglocation, player2currentposition, player2move))
							play2();
					}
				}
				if ((b1.boardptr[0][0] == nullptr || b1.boardptr[0][0]->symbol != 'R') || (b1.boardptr[0][7] == nullptr || b1.boardptr[0][7]->symbol != 'R'))
				{
					if (player2currentposition.symbol == 'K')//Agr badshah salamat capture kr rhy hain tu dubara sy badshah ki new location nikalni ha
						getking(bkinglocation);
					getrook(wrook1location, wrook2location);
					if (rookcheck(wrook1location, bkinglocation, player2currentposition, player2move))
						play2();
					else if (rookcheck(wrook2location, bkinglocation, player2currentposition, player2move))
						play2();
				}
				if ((b1.boardptr[0][2] == nullptr || b1.boardptr[0][2]->symbol != 'B') || (b1.boardptr[0][5] == nullptr || b1.boardptr[0][5]->symbol != 'B'))
				{
					if (player2currentposition.symbol == 'K')//Agr badshah salamat capture kr rhy hain tu dubara sy badshah ki new location nikalni ha
						getking(bkinglocation);
					getbishop(wbishop1location, wbishop2location);
					if (bishopcheck(wbishop1location, bkinglocation, player2currentposition, player2move))
						play2();
					else if (bishopcheck(wbishop2location, bkinglocation, player2currentposition, player2move))
						play2();
				}
				if ((b1.boardptr[0][1] == nullptr || b1.boardptr[0][1]->symbol != 'N') || (b1.boardptr[0][6] == nullptr || b1.boardptr[0][6]->symbol != 'N'))
				{
					if (player2currentposition.symbol == 'K')//Agr badshah salamat capture kr rhy hain tu dubara sy badshah ki new location nikalni ha
						getking(bkinglocation);

					getknight(wknight1location, wknight2location);
					if (knightcheck(wknight1location, bkinglocation, player2currentposition, player2move))
						play2();
					else if (bishopcheck(wknight2location, bkinglocation, player2currentposition, player2move))
						play2();
				}
				player2move.colour = Black;
				return;
			}
		}
		else {
			cout << "\nCan't capture";
			Sleep(800);
			play2();
		}
	}

}
void Chess::makemove(int r1, int c1, int r2, int c2)
{
	b1.boardptr[r2][c2] = b1.boardptr[r1][c1];
	b1.boardptr[r1][c1] = nullptr;

}

Move Chess::getking(Move& m1)
{
	if (m1.colour == 1)
	{
		for (int i = 7; i >= 0; i--)
		{
			for (int j = 0; j < 8; j++)
			{
				if (b1.boardptr[i][j] != nullptr)
				{
					if (b1.boardptr[i][j]->colour == White && b1.boardptr[i][j]->symbol == 'K')
					{

						m1.row = i;
						m1.column = j;
						m1.symbol = 'K';
						if (i == 0 && j == 4)
							m1.piecemoved = 0;
						else
							m1.piecemoved = 1;
						return m1;
					}
				}
			}
		}
	}
	else if (m1.colour == 0)
	{

		for (int i = 7; i >= 0; i--)
		{
			for (int j = 0; j < 8; j++)
			{
				if (b1.boardptr[i][j] != nullptr)
				{
					if (b1.boardptr[i][j]->colour == Black && b1.boardptr[i][j]->symbol == 'K')
					{

						m1.row = i;
						m1.column = j;
						m1.symbol = 'K';
						if (i == 7 && j == 4)
							m1.piecemoved = 0;
						else
							m1.piecemoved = 1;
						return m1;
					}
				}
			}
		}
	}

}
Move Chess::getqueen(Move& m1)
{
	if (m1.colour == 1)
	{
		for (int i = 7; i >= 0; i--)
		{
			for (int j = 0; j < 8; j++)
			{
				if (b1.boardptr[i][j] != nullptr)
				{
					if (b1.boardptr[i][j]->colour == White && b1.boardptr[i][j]->symbol == 'Q')
					{

						m1.row = i;
						m1.column = j;
						m1.symbol = 'Q';
						if (i == 0 && j == 3)
							m1.piecemoved = 0;
						else
							m1.piecemoved = 1;
						return m1;
					}
				}
			}
		}
	}
	else if (m1.colour == 0)
	{

		for (int i = 7; i >= 0; i--)
		{
			for (int j = 0; j < 8; j++)
			{
				if (b1.boardptr[i][j] != nullptr)
				{
					if (b1.boardptr[i][j]->colour == Black && b1.boardptr[i][j]->symbol == 'Q')
					{

						m1.row = i;
						m1.column = j;
						m1.symbol = 'Q';
						if (i == 7 && j == 3)
							m1.piecemoved = 0;
						else
							m1.piecemoved = 1;
						return m1;
					}
				}
			}
		}
	}

}
Move Chess::getcamel(Move& m1)
{
	if (m1.colour == 1)
	{
		for (int i = 7; i >= 0; i--)
		{
			for (int j = 0; j < 8; j++)
			{
				if (b1.boardptr[i][j] != nullptr)
				{
					if (b1.boardptr[i][j]->colour == White && b1.boardptr[i][j]->symbol == 'C')
					{

						m1.row = i;
						m1.column = j;
						m1.symbol = 'C';
						if (i == 0 && j == 3)
							m1.piecemoved = 0;
						else
							m1.piecemoved = 1;
						return m1;
					}
				}
			}
		}
	}
	else if (m1.colour == 0)
	{

		for (int i = 7; i >= 0; i--)
		{
			for (int j = 0; j < 8; j++)
			{
				if (b1.boardptr[i][j] != nullptr)
				{
					if (b1.boardptr[i][j]->colour == Black && b1.boardptr[i][j]->symbol == 'C')
					{

						m1.row = i;
						m1.column = j;
						m1.symbol = 'C';
						if (i == 7 && j == 3)
							m1.piecemoved = 0;
						else
							m1.piecemoved = 1;
						return m1;
					}
				}
			}
		}
	}

}
Move Chess::getrook(Move& m1, Move& m2)
{//call by reference ha issliy jo change ha direct variable main hoga
	// return jo bhi kia ha usko collect nhi kr rha kahi
	bool wgetrook = 0, bgetrook = 0;
	if (m1.colour == 1)
	{
		for (int i = 7; i >= 0; i--)
		{
			for (int j = 0; j < 8; j++)
			{
				if (b1.boardptr[i][j] != nullptr)
				{
					if (!wgetrook)
					{
						if (b1.boardptr[i][j]->colour == White && b1.boardptr[i][j]->symbol == 'R')
						{

							m1.row = i;
							m1.column = j;
							m1.symbol = 'R';
							if (i == 0 && j == 0 || i == 0 && j == 7)
								m1.piecemoved = 0;
							else
								m1.piecemoved = 1;
							wgetrook = 1;
						}
					}
					else
					{
						if (b1.boardptr[i][j]->colour == White && b1.boardptr[i][j]->symbol == 'R')
						{

							m2.row = i;
							m2.column = j;
							m2.symbol = 'R';
							if (i == 0 && j == 7 || i == 0 && j == 0)
								m2.piecemoved = 0;
							else
								m2.piecemoved = 1;
							return m1;
						}
					}
				}
			}
		}
	}
	else if (m1.colour == 0)
	{

		for (int i = 7; i >= 0; i--)
		{
			for (int j = 0; j < 8; j++)
			{
				if (b1.boardptr[i][j] != nullptr)
				{
					if (!bgetrook)
					{
						if (b1.boardptr[i][j]->colour == Black && b1.boardptr[i][j]->symbol == 'R')
						{

							m1.row = i;
							m1.column = j;
							m1.symbol = 'R';
							if (i == 7 && j == 0 || i == 7 && j == 7)
								m1.piecemoved = 0;
							else
								m1.piecemoved = 1;
							bgetrook = 1;
						}
					}
					else
					{
						if (b1.boardptr[i][j]->colour == Black && b1.boardptr[i][j]->symbol == 'R')
						{

							m2.row = i;
							m2.column = j;
							m2.symbol = 'R';
							if (i == 7 && j == 7 || i == 7 && j == 0)
								m2.piecemoved = 0;
							else
								m2.piecemoved = 1;
							return m1;
						}
					}
				}
			}
		}
	}

}
Move Chess::getbishop(Move& m1, Move& m2)
{//call by reference ha issliy jo change ha direct variable main hoga
	// return jo bhi kia ha usko collect nhi kr rha kahi
	bool wgetbishop = 0, bgetbishop = 0;
	if (m1.colour == 1)
	{
		for (int i = 7; i >= 0; i--)
		{
			for (int j = 0; j < 8; j++)
			{
				if (b1.boardptr[i][j] != nullptr)
				{
					if (!wgetbishop)
					{
						if (b1.boardptr[i][j]->colour == White && b1.boardptr[i][j]->symbol == 'B')
						{

							m1.row = i;
							m1.column = j;
							m1.symbol = 'B';
							if (i == 0 && j == 2 || i == 0 && j == 5)
								m1.piecemoved = 0;
							else
								m1.piecemoved = 1;

							wgetbishop = 1;
						}
					}
					else
					{
						if (b1.boardptr[i][j]->colour == White && b1.boardptr[i][j]->symbol == 'B')
						{

							m2.row = i;
							m2.column = j;
							m2.symbol = 'B';
							if (i == 0 && j == 5 || i == 0 && j == 2)
								m2.piecemoved = 0;
							else
								m2.piecemoved = 1;
							return m1;
						}
					}
				}
			}
		}
	}
	else if (m1.colour == 0)
	{

		for (int i = 7; i >= 0; i--)
		{
			for (int j = 0; j < 8; j++)
			{
				if (b1.boardptr[i][j] != nullptr)
				{
					if (!bgetbishop)
					{
						if (b1.boardptr[i][j]->colour == Black && b1.boardptr[i][j]->symbol == 'B')
						{

							m1.row = i;
							m1.column = j;
							m1.symbol = 'B';
							if (i == 7 && j == 2 || i == 7 && j == 5)
								m1.piecemoved = 0;
							else
								m1.piecemoved = 1;

							bgetbishop = 1;
						}
					}
					else
					{
						if (b1.boardptr[i][j]->colour == Black && b1.boardptr[i][j]->symbol == 'B')
						{

							m2.row = i;
							m2.column = j;
							m2.symbol = 'B';
							if (i == 7 && j == 5 || i == 7 && j == 2)
								m2.piecemoved = 0;
							else
								m2.piecemoved = 1;

							return m1;
						}
					}
				}
			}
		}
	}

}
Move Chess::getknight(Move& m1, Move& m2)
{//call by reference ha issliy jo change ha direct variable main hoga
	// return jo bhi kia ha usko collect nhi kr rha kahi
	bool wgetknight = 0, bgetknight = 0;
	if (m1.colour == 1)
	{
		for (int i = 7; i >= 0; i--)
		{
			for (int j = 0; j < 8; j++)
			{
				if (b1.boardptr[i][j] != nullptr)
				{
					if (!wgetknight)
					{
						if (b1.boardptr[i][j]->colour == White && b1.boardptr[i][j]->symbol == 'N')
						{

							m1.row = i;
							m1.column = j;
							m1.symbol = 'N';
							if (i == 0 && j == 1 || i == 0 && j == 6)
								m1.piecemoved = 0;
							else
								m1.piecemoved = 1;

							wgetknight = 1;
						}
					}
					else
					{
						if (b1.boardptr[i][j]->colour == White && b1.boardptr[i][j]->symbol == 'N')
						{

							m2.row = i;
							m2.column = j;
							m2.symbol = 'N';
							if (i == 0 && j == 6 || i == 0 && j == 1)
								m2.piecemoved = 0;
							else
								m2.piecemoved = 1;
							return m1;
						}
					}
				}
			}
		}
	}
	else if (m1.colour == 0)
	{

		for (int i = 7; i >= 0; i--)
		{
			for (int j = 0; j < 8; j++)
			{
				if (b1.boardptr[i][j] != nullptr)
				{
					if (!bgetknight)
					{
						if (b1.boardptr[i][j]->colour == Black && b1.boardptr[i][j]->symbol == 'N')
						{

							m1.row = i;
							m1.column = j;
							m1.symbol = 'N';
							if (i == 7 && j == 1 || i == 7 && j == 6)
								m1.piecemoved = 0;
							else
								m1.piecemoved = 1;

							bgetknight = 1;
						}
					}
					else
					{
						if (b1.boardptr[i][j]->colour == Black && b1.boardptr[i][j]->symbol == 'N')
						{

							m2.row = i;
							m2.column = j;
							m2.symbol = 'N';
							if (i == 7 && j == 6 || i == 7 && j == 1)
								m2.piecemoved = 0;
							else
								m2.piecemoved = 1;

							return m1;
						}
					}
				}
			}
		}
	}

}

bool Chess::check(Move& m1, Move& m2)
{

	if (m1.colour != m2.colour)
	{
		if (b1.boardptr[m1.row][m1.column]->capture(b1, m1, m2))
		{
			if (m2.colour == 1)
				return true;
			else
				return true;

		}
	}
	return false;
}
bool doze;
bool Chess::queencheck(Move& queenlocation, Move& kinglocation, Move& playercurrentposition, Move& playermove)
{
	if (queenlocation.piecemoved)
	{

		doze = check(queenlocation, kinglocation);
		if (doze)
		{
			cout << "\nYour king will be in check\nYou can't make this move\nMake move again";
			Sleep(1000);
			makemove(playermove.row, playermove.column, playercurrentposition.row, playercurrentposition.column);
			if (playermove.occupied)
			{
				if (playercurrentposition.colour == 0)
				{
					piecemaker(playermove, White);
				}
				else if (playercurrentposition.colour == 1)
				{
					piecemaker(playermove, Black);
				}
			}
			b1.drawboard();
			return true;
		}
		return false;
	}
	return false;
}
bool Chess::camelcheck(Move& camellocation, Move& kinglocation, Move& playercurrentposition, Move& playermove)
{
	if (camellocation.piecemoved)
	{

		doze = check(camellocation, kinglocation);
		if (doze)
		{
			cout << "\nYour king will be in check\nYou can't make this move\nMake move again";
			Sleep(1000);
			makemove(playermove.row, playermove.column, playercurrentposition.row, playercurrentposition.column);
			if (playermove.occupied)
			{
				if (playercurrentposition.colour == 0)
				{
					piecemaker(playermove, White);
				}
				else if (playercurrentposition.colour == 1)
				{
					piecemaker(playermove, Black);
				}
			}
			b1.drawboard();
			return true;
		}
		return false;
	}
	return false;
}
bool Chess::rookcheck(Move& rooklocation, Move& kinglocation, Move& playercurrentposition, Move& playermove)
{
	if (rooklocation.piecemoved)
	{

		doze = check(rooklocation, kinglocation);
		if (doze)
		{
			cout << "\nYour king will be in check\nYou can't make this move\nMake move again";
			Sleep(1000);
			makemove(playermove.row, playermove.column, playercurrentposition.row, playercurrentposition.column);
			if (playermove.occupied)
			{
				if (playercurrentposition.colour == 0)
				{
					piecemaker(playermove, White);
				}
				else if (playercurrentposition.colour == 1)
				{
					piecemaker(playermove, Black);
				}
			}
			b1.drawboard();
			return true;
		}
		return false;
	}
	return false;
}

bool Chess::bishopcheck(Move& bishoplocation, Move& kinglocation, Move& playercurrentposition, Move& playermove)
{
	if (bishoplocation.piecemoved)
	{

		doze = check(bishoplocation, kinglocation);
		if (doze)
		{
			cout << "\nYour king will be in check\nYou can't make this move\nMake move again";
			Sleep(1000);
			makemove(playermove.row, playermove.column, playercurrentposition.row, playercurrentposition.column);
			if (playermove.occupied)
			{
				if (playercurrentposition.colour == 0)
				{
					piecemaker(playermove, White);
				}
				else if (playercurrentposition.colour == 1)
				{
					piecemaker(playermove, Black);
				}
			}
			b1.drawboard();
			return true;
		}
		return false;
	}
	return false;
}
bool Chess::knightcheck(Move& knightlocation, Move& kinglocation, Move& playercurrentposition, Move& playermove)
{
	if (knightlocation.piecemoved)
	{

		doze = check(knightlocation, kinglocation);
		if (doze)
		{
			cout << "\nYour king will be in check\nYou can't make this move\nMake move again";
			Sleep(1000);
			makemove(playermove.row, playermove.column, playercurrentposition.row, playercurrentposition.column);
			if (playermove.occupied)
			{
				if (playercurrentposition.colour == 0)
				{
					piecemaker(playermove, White);
				}
				else if (playercurrentposition.colour == 1)
				{
					piecemaker(playermove, Black);
				}
			}
			b1.drawboard();
			return true;
		}
		return false;
	}
	return false;
}




void Chess::piecemaker(Move& playermove, Color c)
{
	char piecetocapture;
	if (c == White)
		piecetocapture = wpiecetocapture;
	else if (c == Black)
		piecetocapture = bpiecetocapture;

	switch (piecetocapture)
	{
	case 'P':
		b1.boardptr[playermove.row][playermove.column] = new Pawn(c, playermove.row, playermove.column);
		break;
	case 'R':
		b1.boardptr[playermove.row][playermove.column] = new Rook(c, playermove.row, playermove.column);
		break;
	case 'B':
		b1.boardptr[playermove.row][playermove.column] = new Bishop(c, playermove.row, playermove.column);
		break;
	case 'Q':
		b1.boardptr[playermove.row][playermove.column] = new Queen(c, playermove.row, playermove.column);
		break;
	case 'N':
		b1.boardptr[playermove.row][playermove.column] = new Knight(c, playermove.row, playermove.column);
		break;

	}
}

bool Chess::kingsidecastle(Move& kinglocation, Move& dummymove1, Move& dummymove2, Move& queenlocation, Move& rook1location, Move& rook2location, Move& bishop1location, Move& bishop2location, Move& knight1location, Move& knight2location)
{
	bool castle = 1;

	if (b1.boardptr[dummymove1.row][dummymove1.column] == nullptr && b1.boardptr[dummymove2.row][dummymove2.column] == nullptr)
	{


		if (queenlocation.piecemoved)
		{
			if (check(queenlocation, dummymove1) || check(queenlocation, dummymove2))
			{
				cout << "\nCan't castle";
				return false;
			}
		}
		if (rook1location.piecemoved && castle == 1)
		{
			if (check(rook1location, dummymove1) || check(rook1location, dummymove2))
			{
				cout << "\nCan't castle";
				return false;
			}
		}
		else if (rook2location.piecemoved && castle == 1)
		{
			if (check(rook2location, dummymove1) || check(rook2location, dummymove2))
			{
				cout << "\nCan't castle";
				return false;
			}
		}
		else if (bishop1location.piecemoved && castle == 1)
		{
			if (check(bishop1location, dummymove1) || check(bishop1location, dummymove2))
			{
				cout << "\nCan't castle";
				return false;
			}
		}
		else if (bishop2location.piecemoved && castle == 1)
		{
			if (check(bishop2location, dummymove1) || check(bishop2location, dummymove2))
			{
				cout << "\nCan't castle";
				return false;
			}
		}
		else if (knight1location.piecemoved && castle == 1)
		{
			if (check(knight1location, dummymove1) || check(knight1location, dummymove2))
			{
				cout << "\nCan't castle";
				return false;
			}
		}
		else if (knight2location.piecemoved && castle == 1)
		{
			if (check(knight2location, dummymove1) || check(knight2location, dummymove2))
			{
				cout << "\nCan't castle";
				return false;
			}
		}
	}
	else
	{
		cout << "\nThere is a piece between king and rook";
		castle = 0;
		return false;
	}


	return true;
}
bool Chess::queensidecastle(Move& kinglocation, Move& dummymove1, Move& dummymove2, Move& dummymove3, Move& queenlocation, Move& rook1location, Move& rook2location, Move& bishop1location, Move& bishop2location, Move& knight1location, Move& knight2location)
{
	bool castle = 1;

	if (b1.boardptr[dummymove1.row][dummymove1.column] == nullptr && b1.boardptr[dummymove2.row][dummymove2.column] == nullptr && b1.boardptr[dummymove3.row][dummymove3.column] == nullptr)
	{


		if (queenlocation.piecemoved)
		{
			if (check(queenlocation, dummymove1) || check(queenlocation, dummymove2) || check(queenlocation, dummymove3))
			{
				cout << "\nCan't castle";
				return false;
			}
		}
		if (rook1location.piecemoved && castle == 1)
		{
			if (check(rook1location, dummymove1) || check(rook1location, dummymove2) || check(rook1location, dummymove3))
			{
				cout << "\nCan't castle";
				return false;
			}
		}
		else if (rook2location.piecemoved && castle == 1)
		{
			if (check(rook2location, dummymove1) || check(rook2location, dummymove2) || check(rook2location, dummymove3))
			{
				cout << "\nCan't castle";
				return false;
			}
		}
		else if (bishop1location.piecemoved && castle == 1)
		{
			if (check(bishop1location, dummymove1) || check(bishop1location, dummymove2) || check(bishop1location, dummymove3))
			{
				cout << "\nCan't castle";
				return false;
			}
		}
		else if (bishop2location.piecemoved && castle == 1)
		{
			if (check(bishop2location, dummymove1) || check(bishop2location, dummymove2) || check(bishop2location, dummymove3))
			{
				cout << "\nCan't castle";
				return false;
			}
		}
		else if (knight1location.piecemoved && castle == 1)
		{
			if (check(knight1location, dummymove1) || check(knight1location, dummymove2) || check(knight1location, dummymove3))
			{
				cout << "\nCan't castle";
				return false;
			}
		}
		else if (knight2location.piecemoved && castle == 1)
		{
			if (check(knight2location, dummymove1) || check(knight2location, dummymove2) || check(knight2location, dummymove3))
			{
				cout << "\nCan't castle";
				return false;
			}
		}

	}
	else
	{
		cout << "\nThere is a piece between king and rook";
		castle = 0;
		return false;
	}


	return true;
}


bool Chess::kingcapture(Move& kinglocation, Move& dummymove, Move& queenlocation, Move& rook1location, Move& rook2location, Move& bishop1location, Move& bishop2location, Move& knight1location, Move& knight2location)
{
	bool cancapture = 1;
	if (queenlocation.piecemoved)
	{
		if (dummymove.symbol != 'Q')
		{
			if (check(queenlocation, dummymove))
			{
				cancapture = 0;

			}
		}
	}
	if (rook1location.piecemoved && cancapture == 1)
	{
		if (dummymove.symbol != 'R')
		{
			if (check(rook1location, dummymove))
			{
				cancapture = 0;
			}
		}
	}
	if (rook2location.piecemoved && cancapture == 1)
	{
		if (dummymove.symbol != 'R')
		{
			if (check(rook2location, dummymove))
			{
				cancapture = 0;
			}
		}
	}
	if (bishop1location.piecemoved && cancapture == 1)
	{
		cout << dummymove;
		cout << bishop1location;
		if (dummymove.symbol != 'B')
		{
			if (check(bishop1location, dummymove))
			{
				cancapture = 0;
			}
		}
	}
	if (bishop2location.piecemoved && cancapture == 1)
	{
		if (dummymove.symbol != 'B')
		{
			if (check(bishop2location, dummymove))
			{
				cancapture = 0;
			}
		}
	}
	if (knight1location.piecemoved && cancapture == 1)
	{
		if (dummymove.symbol != 'N')
		{
			if (check(knight1location, dummymove))
			{
				cancapture = 0;
			}
		}
	}
	if (knight2location.piecemoved && cancapture == 1)
	{

		if (dummymove.symbol != 'N')
		{
			if (check(knight2location, dummymove))
			{
				cancapture = 0;
			}
		}
	}
	cout << cancapture;
	return cancapture;
}

void Chess::checkmate()
{
	string str;
	system("cls");
	if (wcheckmate)
	{
		cout << "\n\n\n\t\t\t  Checkmate";
		cout << "\n\n\t\t\tBlack has won the game";
		cout << "\n\n\t\t\t    Press any key to continue ";
		cin >> str;
	}
	else
	{
		cout << "\n\n\n\t\t\t\t   Checkmate";
		cout << "\n\n\t\t\tWhite has won the game";
		cout << "\n\n\t\t   Press any key to continue ";
		cin >> str;
	}
	exit(0);//yaha abhi aik error a rha ha
}
void Chess::kingrushcheckmate()
{
	string str;
	system("cls");
	if (bcheck)
	{
		cout << "\n\n\n\t\t\t  Checkmate";
		cout << "\n\n\t\t\tWhite has won the game";
		cout << "\n\n\t\t\t  Press any key to continue ";
		cin >> str;
	}
	else
	{
		cout << "\n\n\n\t\t\t\t   Checkmate";
		cout << "\n\n\t\t\tBlack has won the game";
		cout << "\n\n\t\t Press any key to continue ";
		cin >> str;
	}
	exit(0);//yaha abhi aik error a rha ha

}
void Chess::kingrushtoprowcondition(Move& kinglocation)
{
	if (kinglocation.row == 7)
	{
		if (kinglocation.colour == White)
		{
			bcheck = 1;
			kingrushcheckmate();
		}
		else if (kinglocation.colour == Black)
		{
			wcheck = 1;
			kingrushcheckmate();
		}
	}
}


Chess::~Chess()
{
	
}