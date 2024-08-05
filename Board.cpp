#include "Board.h"
#include"Queen.h"
#include"Camel.h"
#include<fstream>
ifstream fin;
ofstream fout;

Board::Board()
{
	boardptr = nullptr;
	fout.open("Chess1.txt", ios::app);
	fout.close();
	fout.open("Chess2.txt", ios::app);
	fout.close();
	fout.open("Chess3.txt", ios::app);
	fout.close();

}

void Board::createboard1()
{
	boardptr = new Piece * *[8];
	for (int i = 7; i >= 0; i--)
	{
		boardptr[i] = new Piece * [8];
		for (int j = 0; j < 8; j++)
		{
			if (i == 6) { boardptr[i][j] = new Pawn(Black, i, j); }
			else if (i == 1) { boardptr[i][j] = new Pawn(White, i, j); }
			else if (i == 7 && j == 0 || i == 7 && j == 7) { boardptr[i][j] = new Rook(Black, i, j); }
			else if (i == 0 && j == 0 || i == 0 && j == 7) { boardptr[i][j] = new Rook(White, i, j); }
			else if (i == 7 && j == 1 || i == 7 && j == 6) { boardptr[i][j] = new Knight(Black, i, j); }
			else if (i == 0 && j == 1 || i == 0 && j == 6) { boardptr[i][j] = new Knight(White, i, j); }
			else if (i == 7 && j == 2 || i == 7 && j == 5) { boardptr[i][j] = new Bishop(Black, i, j); }
			else if (i == 0 && j == 2 || i == 0 && j == 5) { boardptr[i][j] = new Bishop(White, i, j); }
			else if (i == 0 && j == 3) { boardptr[i][j] = new Queen(White, i, j); }
			else if (i == 7 && j == 3) { boardptr[i][j] = new Queen(Black, i, j); }
			else if (i == 0 && j == 4) { boardptr[i][j] = new King(White, i, j); }
			else if (i == 7 && j == 4) { boardptr[i][j] = new King(Black, i, j); }

			else
			{
				boardptr[i][j] = nullptr;

			}
		}
	}

}

void Board::drawboard()
{
	system("cls");
	cout << "\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "\t\t\t\t\t~\t    Chess Board            ~\n";
	cout << "\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	int alpha = 96;
	char a;
	cout << "   ";
	for (int i = 1; i < 9; i++)
	{
		a = alpha + i;
		cout << "      " << a << "       ";

	}
	cout << "\n   ";

	for (int i = 113; i > 0; i--)
	{
		cout << "_";
	}
	cout << "\n   ";
	for (int i = 7; i >= 0; i--)
	{
		cout << "|";
		for (int j = 1; j < 9; j++)
		{
			cout << "             |";

		}
		cout << "\n " << i + 1 << " ";

		cout << "|";

		for (int j = 0; j < 8; j++)
		{
			if (boardptr[i][j] != nullptr)
			{

				if (boardptr[i][j]->colour == Black && boardptr[i][j]->symbol == 'P') { cout << " Black Pawn  |"; }
				else if (boardptr[i][j]->colour == White && boardptr[i][j]->symbol == 'P') { cout << " White Pawn  |"; }
				else if (boardptr[i][j]->colour == Black && boardptr[i][j]->symbol == 'R') { cout << " Black Rook  |"; }
				else if (boardptr[i][j]->colour == White && boardptr[i][j]->symbol == 'R') { cout << " White Rook  |"; }
				else if (boardptr[i][j]->colour == Black && boardptr[i][j]->symbol == 'N') { cout << " Black Knight|"; }
				else if (boardptr[i][j]->colour == White && boardptr[i][j]->symbol == 'N') { cout << " White Knight|"; }
				else if (boardptr[i][j]->colour == Black && boardptr[i][j]->symbol == 'B')
				{
					cout << " Black Bishop|";
				}
				else if (boardptr[i][j]->colour == White && boardptr[i][j]->symbol == 'B')
				{
					cout << " White Bishop|";
				}
				else if (boardptr[i][j]->colour == Black && boardptr[i][j]->symbol == 'K') { cout << " Black King  |"; }
				else if (boardptr[i][j]->colour == White && boardptr[i][j]->symbol == 'K') { cout << " White King  |"; }
				else if (boardptr[i][j]->colour == Black && boardptr[i][j]->symbol == 'Q') { cout << " Black Queen |"; }
				else if (boardptr[i][j]->colour == White && boardptr[i][j]->symbol == 'Q') { cout << " White Queen |"; }
				else if (boardptr[i][j]->colour == Black && boardptr[i][j]->symbol == 'C') { cout << " Black Camel |"; }
				else if (boardptr[i][j]->colour == White && boardptr[i][j]->symbol == 'C') { cout << " White Camel |"; }
			}

			else
				cout << "             |";

		}
		cout << "\n   ";
		cout << "|";
		for (int j = 1; j < 9; j++)
		{
			cout << "_____________|";
		}
		cout << "\n   ";
	}
	cout << "\n   ";
	for (int i = 1; i < 9; i++)
	{
		a = alpha + i;
		cout << "      " << a << "       ";

	}
	cout << endl;
	cout << endl;

}



void Board::createboard2()
{
	boardptr = new Piece * *[8];
	for (int i = 7; i >= 0; i--)
	{
		boardptr[i] = new Piece * [8];
		for (int j = 0; j < 8; j++)
		{
			if (i == 6) { boardptr[i][j] = new Pawn(Black, i, j); }
			else if (i == 1) { boardptr[i][j] = new Pawn(White, i, j); }
			else if (i == 7 && j == 0 || i == 7 && j == 7) { boardptr[i][j] = new Rook(Black, i, j); }
			else if (i == 0 && j == 0 || i == 0 && j == 7) { boardptr[i][j] = new Rook(White, i, j); }
			else if (i == 7 && j == 1 || i == 7 && j == 6) { boardptr[i][j] = new Knight(Black, i, j); }
			else if (i == 0 && j == 1 || i == 0 && j == 6) { boardptr[i][j] = new Knight(White, i, j); }
			else if (i == 7 && j == 2 || i == 7 && j == 5) { boardptr[i][j] = new Bishop(Black, i, j); }
			else if (i == 0 && j == 2 || i == 0 && j == 5) { boardptr[i][j] = new Bishop(White, i, j); }
			else if (i == 0 && j == 3) {boardptr[i][j] = new Camel(White, i, j);
		
			}
			else if (i == 7 && j == 3) { boardptr[i][j] = new Camel(Black, i, j);
			
			}
			
			else if (i == 0 && j == 4) { boardptr[i][j] = new King(White, i, j); }
			else if (i == 7 && j == 4) { boardptr[i][j] = new King(Black, i, j); }

			else
			{
				boardptr[i][j] = nullptr;

			}
		}
	}

}



void Board::drawboard2()
{
	system("cls");
	cout << "\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "\t\t\t\t\t~\t    Chess Board            ~\n";
	cout << "\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	int alpha = 96;
	char a;
	cout << "   ";
	for (int i = 1; i < 9; i++)
	{
		a = alpha + i;
		cout << "      " << a << "       ";

	}
	cout << "\n   ";

	for (int i = 113; i > 0; i--)
	{
		cout << "_";
	}
	cout << "\n   ";
	for (int i = 7; i >= 0; i--)
	{
		cout << "|";
		for (int j = 1; j < 9; j++)
		{
			cout << "             |";

		}
		cout << "\n " << i + 1 << " ";

		cout << "|";

		for (int j = 0; j < 8; j++)
		{
			if (boardptr[i][j] != nullptr)
			{


				if (boardptr[i][j]->colour == Black && boardptr[i][j]->symbol == 'P') { cout << " Black Pawn  |"; }
				else if (boardptr[i][j]->colour == White && boardptr[i][j]->symbol == 'P') { cout << " White Pawn  |"; }
				else if (boardptr[i][j]->colour == Black && boardptr[i][j]->symbol == 'R') { cout << " Black Rook  |"; }
				else if (boardptr[i][j]->colour == White && boardptr[i][j]->symbol == 'R') { cout << " White Rook  |"; }
				else if (boardptr[i][j]->colour == Black && boardptr[i][j]->symbol == 'N') { cout << " Black Knight|"; }
				else if (boardptr[i][j]->colour == White && boardptr[i][j]->symbol == 'N') { cout << " White Knight|"; }
				else if (boardptr[i][j]->colour == Black && boardptr[i][j]->symbol == 'B')
				{
					cout << " Black Bishop|";
				}
				else if (boardptr[i][j]->colour == White && boardptr[i][j]->symbol == 'B')
				{
					cout << " White Bishop|";
				}
				else if (boardptr[i][j]->colour == Black && boardptr[i][j]->symbol == 'K') { cout << " Black King  |"; }
				else if (boardptr[i][j]->colour == White && boardptr[i][j]->symbol == 'K') { cout << " White King  |"; }
				else if (boardptr[i][j]->colour == Black && boardptr[i][j]->symbol == 'C') { cout << " Black Camel |"; }
				else if (boardptr[i][j]->colour == White && boardptr[i][j]->symbol == 'C') { cout << " White Camel |"; }
			}
			else
				cout << "             |";

		}
		cout << "\n   ";
		cout << "|";
		for (int j = 1; j < 9; j++)
		{
			cout << "_____________|";
		}
		cout << "\n   ";
	}
	cout << "\n   ";
	for (int i = 1; i < 9; i++)
	{
		a = alpha + i;
		cout << "      " << a << "       ";

	}
	cout << endl;
	cout << endl;

}

void Board::createboard3()
{
	boardptr = new Piece * *[8];
	for (int i = 7; i >= 0; i--)
	{
		boardptr[i] = new Piece * [8];
		for (int j = 0; j < 8; j++)
		{

			if (i == 0 && j == 6 || i == 1 && j == 6) { boardptr[i][j] = new Rook(Black, i, j); }
			else if (i == 0 && j == 1 || i == 1 && j == 1) { boardptr[i][j] = new Rook(White, i, j); }
			else if (i == 0 && j == 4 || i == 1 && j == 4) { boardptr[i][j] = new Knight(Black, i, j); }
			else if (i == 0 && j == 3 || i == 1 && j == 3) { boardptr[i][j] = new Knight(White, i, j); }
			else if (i == 0 && j == 5 || i == 1 && j == 5) { boardptr[i][j] = new Bishop(Black, i, j); }
			else if (i == 0 && j == 2 || i == 1 && j == 2) { boardptr[i][j] = new Bishop(White, i, j); }
			else if (i == 0 && j == 0) { boardptr[i][j] = new Queen(White, i, j); }
			else if (i == 0 && j == 7) { boardptr[i][j] = new Queen(Black, i, j); }
			else if (i == 1 && j == 0) { boardptr[i][j] = new King(White, i, j); }
			else if (i == 1 && j == 7) { boardptr[i][j] = new King(Black, i, j); }

			else
			{
				boardptr[i][j] = nullptr;

			}
		}
	}

}

void Board:: writeinfile(Board& b1, const string& filename)
{
	fout.open(filename);
	if (!fout) {
		cout << "\nCustomer file not opened for writng\n"; 
		system("pause");
		return;
	}

	

	for (int i = 7; i >= 0; i--)
	{

		for (int j = 0; j < 8; j++)
		{
			if (b1.boardptr[i][j] == nullptr)
				fout << "**";
			else
			{
				
				fout << b1.boardptr[i][j]->colour;
				fout << b1.boardptr[i][j]->symbol;
			}
		}
		fout << endl;
	}
	fout.close();

}

bool Board::readfromfile(Board& b1, const string& filename)
{
	fin.open(filename);
	if (!fin) {
		cout << "\nCustomer file not opened for reading\n";
		system("pause");
		return 0;
	}
	int counter = 0;
	
	char sym;
	char col;
	b1.boardptr = new Piece * *[8];
	for (int i = 7; i >= 0; i--)
	{
		b1.boardptr[i] = new Piece * [8];
		for (int j = 0; j < 8; j++)
		{
			fin >> col;
			fin >> sym;
			if (sym == 'P' && col == '0') { b1.boardptr[i][j] = new Pawn(Black, i, j); }
			else if (sym == 'P' && col == '1') { b1.boardptr[i][j] = new Pawn(White, i, j); }
			else if (sym=='R'&&col=='0') { b1.boardptr[i][j] = new Rook(Black, i, j); }
			else if (sym=='R'&&col=='1') { b1.boardptr[i][j] = new Rook(White, i, j); }
			else if (sym=='N'&&col=='0') { b1.boardptr[i][j] = new Knight(Black, i, j); }
			else if (sym=='N'&&col=='1') { b1.boardptr[i][j] = new Knight(White, i, j); }
			else if (sym=='B'&&col=='0') { b1.boardptr[i][j] = new Bishop(Black, i, j); }
			else if (sym=='B'&&col=='1') { b1.boardptr[i][j] = new Bishop(White, i, j); }
			else if (sym=='Q'&&col=='1') { b1.boardptr[i][j] = new Queen(White, i, j); }
			else if (sym=='Q'&&col=='0') { b1.boardptr[i][j] = new Queen(Black, i, j); }
			else if (sym=='K'&&col=='1') { b1.boardptr[i][j] = new King(White, i, j); }
			else if (sym=='K'&&col=='0') { b1.boardptr[i][j] = new King(Black, i, j); }
			else if (sym == 'C' && col == '1') { b1.boardptr[i][j] = new Camel(White, i, j); }
			else if (sym == 'C' && col == '0') { b1.boardptr[i][j] = new Camel(Black, i, j); }

			else
			{
				b1.boardptr[i][j] = nullptr;
				++counter;
			}
		}
	}
	if (counter == 64)
	{
		cout << "\n\n\n\t\t\t\t\tFile is empty unable to load the game";
		return 0;
	}
	else
		return 1;
}




Board::~Board()
{
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < 8; j++)
		{
			delete[] boardptr[i][j];
		}
		delete[] boardptr[i];
	}
	delete[] boardptr;
}
