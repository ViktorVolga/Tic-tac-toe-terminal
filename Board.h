#pragma once
#include <iostream>
#include "Cell.h"
#include <string>

class Board3õ3
{
	Cell _board3õ3[3][3] {};
	int _scoreX = 0;
	int _scoreO = 0;
public:
	bool isVictoryX();
	bool isVictory0();
	void printBoard3x3();
	bool getIsCellBusy(int row, int column);
	void setVall(int row, int column, int XorY); //if X - return 1
	bool isTie();
	void popVall(int row, int column, int XorY);
	void clear();
	
};
class Board5õ5
{
	Cell _board5õ5[5][5]{};
	int _scoreX = 0;
	int _scoreO = 0;
public:
	bool isVictoryX();
	void printBoard5x5();
	void setVall(int row, int column, int XorY);
	bool isVictory0();
	bool isTie();
	bool getIsCellBusy(int row, int column);
	void popVall(int row, int column, int XorY);
	void clear();	
};



