#pragma once

#include <iostream>
#include <memory>
#include "Board.h"
#include <vector>
#include <set>

struct Move {
public:
	Move(){}
	Move(int Score) : _score(Score) {}
	Move(int Score, int _row, int _column) : _score(Score), row(_row), column(_column) {}
	int row = 1;
	int column = 1;
	int _score = 0;
	
};

class Game
{	

	bool _isCurrentBoard3X3 = false;	
	Board3õ3 _curBoard3x3;
	Board5õ5 _curBoard5x5;
	Player _curPlayer;
	int _player = 1;
	int _cpu = 2;
	std::vector<Move> playersMove;
	int playersMoveCount = 0;
	int r0, r1, r2, r3, r4;
	int c1, c2, c3, c4, c0;
	int d1, d2;
	std::vector<int> variable;
	bool multyplayer = false;
	bool CPU_vs_CPU = false;

public:

	

	int _count;
	bool _isGameOn = false;
	void start();
	void showMainMenu();
	void showBoardMenu();
	void showXor0Menu();
	void round3x3();
	Move getBestMove3x3(Board3õ3& board, Player& _curPlayer, int depth);
	void round5x5();
	Move getBestMove5x5(Board5õ5& board, Player& _curPlayer, int depth);
	Move getBestMove5x5startgame(std::vector<Move> playersMove, Board5õ5& board);
	
	
	void round3x3CPU();
	void round5x5CPU();
	


	
};



