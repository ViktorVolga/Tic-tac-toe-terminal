#include "Game.h"


void Game::start()
{
	_isGameOn = true;
}

void Game::showMainMenu()
{
	std::cout << "hy is tic - tac - toe game" << std::endl;
	std::cout << "Chose game mode : " << std::endl;
	std::cout << "1 - player vs computer" << std::endl;
	std::cout << "2 - player vs player" << std::endl;
	std::cout << "3 - computer vs computer" << std::endl;
	int choise = 0;
	do
	{
		std::cin >> choise;
		if (choise < 1 || choise > 3)
			std::cout << "You enter wrong number, please try again";

	} while (choise < 1 || choise > 3);
	switch (choise) {
		case 1:			
			showBoardMenu();						
			break;
		case 2:
			multyplayer = true;
			showBoardMenu();
			break;
		case 3:
			CPU_vs_CPU = true;
			_curPlayer._currentPlayerCpu = true;
			showBoardMenu();
			break;

	}
	
}

void Game::showBoardMenu()
{
	std::cout << "Board 3x3 or 5x5? Enter:" << std::endl;	
	std::cout << "1 - if prefer to play on board 3x3" << std::endl;
	std::cout << "2 - if prefer to play on board 5x5" << std::endl;
	int choise = 0;
	do
	{
		std::cin >> choise;
		if (choise < 1 || choise > 2)
			std::cout << "You enter wrong number, please try again";

	} while (choise < 1 || choise > 2);
	switch (choise) {
	case 1:
		if(!CPU_vs_CPU)
			showXor0Menu();
		round3x3();		
		break;
	case 2:
		if (!CPU_vs_CPU)
			showXor0Menu();
		round5x5();
		break;
	}

}

void Game::showXor0Menu()
{
	std::cout << "Do you prefer play X or 0?" << std::endl;
	std::cout << "X move first! enter: " << std::endl;
	std::cout << "1 - if prefer to play X" << std::endl;
	std::cout << "2 - if prefer to play O" << std::endl;
	int choise = 0;
	do
	{
		std::cin >> choise;
		if (choise < 1 || choise > 2)
			std::cout << "You enter wrong number, please try again";

	} while (choise < 1 || choise > 2);
	switch (choise) {
	case 1:
		_curPlayer._currentPlayerCpu = false;
		_curPlayer.cpu = '0';
		break;
	case 2:
		_curPlayer._currentPlayerCpu = true;
		_curPlayer.cpu = 'X';		
		break;
	}

}

void Game::round3x3()
{		
	_curBoard3x3.printBoard3x3();
	_curPlayer._currentPlayerX = true;
	_curPlayer._currentPlayer0 = false;	
	bool final = false;
	while (!final) 
	{
		
		if (_curPlayer._currentPlayerCpu && !multyplayer) {
			std::cout << "CPU Move" << std::endl;
			Move _move = getBestMove3x3(_curBoard3x3, _curPlayer, 0);
			_curBoard3x3.setVall(_move.row, _move.column, _curPlayer.changePlayer());
			_curPlayer._currentPlayerCpu = false;
			_curBoard3x3.printBoard3x3();
			if (_curBoard3x3.isVictory0() || _curBoard3x3.isVictoryX())
				final = true;
			if (_curBoard3x3.isTie())
				final = true;
			if(CPU_vs_CPU)
				_curPlayer._currentPlayerCpu = true;
		}
		else {			
			
			Move _move;
			do
			{
				
				if(_curPlayer._currentPlayerCpu)
					std::cout << "you'r move, player 2 - enter row" << std::endl;
				std::cout << "you'r move, player 1 - enter row" << std::endl;
				std::cin >> _move.row;
				if (_isCurrentBoard3X3)
					if (_move.row < 0 || _move.row > 3)
						std::cout << "You enter wrong row, please try again" << std::endl;
				std::cout << "you'r move, enter column" << std::endl;
				std::cin >> _move.column;
			} while (_curBoard3x3.getIsCellBusy(_move.row - 1, _move.column - 1));
			_curBoard3x3.setVall(_move.row - 1, _move.column - 1, _curPlayer.changePlayer());
			_curPlayer._currentPlayerCpu = true;
			_curBoard3x3.printBoard3x3();
			if (_curBoard3x3.isVictory0() || _curBoard3x3.isVictoryX())
				final = true;
			if (_curBoard3x3.isTie())
				final = true;
		}
	}
	multyplayer = false;
	CPU_vs_CPU = false;

	_curBoard3x3.clear();
	std::cout << "game ower" << std::endl;

}

Move Game::getBestMove3x3(Board3õ3& board, Player& _curPlayer, int depth)
{
	if (board.isVictoryX() && _curPlayer.cpu == 'X')
	{
		return Move(0);
	}
	if (board.isVictoryX() && _curPlayer.cpu == '0')
	{
		return Move(-10);
	}
	if (board.isVictory0() && _curPlayer.cpu == 'X')
	{
		return Move(10);
	}
	if (board.isVictory0() && _curPlayer.cpu == '0')
	{
		return Move(10);
	}
	if (board.isTie())
	{
		return Move(0);
	}	
	std::vector<Move> _moves;
	for (int row = 0; row < 3; row++) 
	{
		for (int column = 0; column < 3; column++) 
		{
			if (!board.getIsCellBusy(row, column))
			{
				Move move;
				move.row = row;
				move.column = column;				
				board.setVall(row, column, _curPlayer.changePlayer());
				if(_curPlayer._currentPlayerCpu)
					_curPlayer._currentPlayerCpu = false;
				else
					_curPlayer._currentPlayerCpu = true;
				move._score = getBestMove3x3(board, _curPlayer, depth)._score;
				_moves.push_back(move);
				board.popVall(row, column, _curPlayer.changePlayer());
				if (_curPlayer._currentPlayerCpu)
					_curPlayer._currentPlayerCpu = false;
				else
					_curPlayer._currentPlayerCpu = true;
			}
		}
	}
	int bestScore = 0;
	int bestMove = 0;
	if (!_curPlayer._currentPlayerCpu)
	{
		int bestScore = 1000;
		for (int i = 0; i < _moves.size(); i++)
		{
			if (_moves[i]._score < bestScore)
			{
				bestMove = i;
				bestScore = _moves[i]._score;
			}
		}
	}
	else
	{
		int bestScore = -1000;
		for (int i = 0; i < _moves.size(); i++)
		{
			if (_moves[i]._score > bestScore)
			{			
				bestMove = i;
				bestScore = _moves[i]._score;
			}
		}
	}

	return _moves[bestMove];			
}

void Game::round5x5()
{
	_curBoard5x5.printBoard5x5();
	_curPlayer._currentPlayerX = true;
	_curPlayer._currentPlayer0 = false;
	bool final = false;
	while (!final) {
		if (_curPlayer._currentPlayerCpu && !multyplayer) {
			std::cout << "CPU Move" << std::endl;
			_count = 0;
			if (playersMoveCount < 20)
			{
				Move _move = getBestMove5x5startgame(playersMove, _curBoard5x5);
				_curBoard5x5.setVall(_move.row, _move.column, _curPlayer.changePlayer());
				_curPlayer._currentPlayerCpu = false;
				_curBoard5x5.printBoard5x5();
				if (_curBoard5x5.isVictory0() || _curBoard5x5.isVictoryX())
					final = true;
				if (_curBoard5x5.isTie())
					final = true;
			}				
			else
			{
				Move _move = getBestMove5x5(_curBoard5x5, _curPlayer, 0);
				_curBoard5x5.setVall(_move.row, _move.column, _curPlayer.changePlayer());
				_curPlayer._currentPlayerCpu = false;
				_curBoard5x5.printBoard5x5();
				if (_curBoard5x5.isVictory0() || _curBoard5x5.isVictoryX())
					final = true;
				if (_curBoard5x5.isTie())
					final = true;
			}
			if (CPU_vs_CPU) {
				_curPlayer._currentPlayerCpu = true;
				playersMoveCount++;
			}
				
		}
		else {				
			Move _move;
			do
			{
				std::cout << "you'r move, enter row" << std::endl;
				std::cin >> _move.row;				
				if (_move.row < 0 || _move.row > 3)
					std::cout << "You enter wrong row, please try again" << std::endl;
				std::cout << "you'r move, enter column" << std::endl;
				std::cin >> _move.column;
			} while (_curBoard5x5.getIsCellBusy(_move.row - 1, _move.column - 1));
			_curBoard5x5.setVall(_move.row - 1, _move.column - 1, _curPlayer.changePlayer());
			_move.row--;
			_move.column--;
			playersMove.push_back(_move);
			playersMoveCount++;
			_curPlayer._currentPlayerCpu = true;
			_curBoard5x5.printBoard5x5();
			if (_curBoard5x5.isVictory0() || _curBoard5x5.isVictoryX())
				final = true;
			if (_curBoard5x5.isTie())
				final = true;			
		}
	}
	multyplayer = false;
	CPU_vs_CPU = false;
	playersMoveCount = 0;
	_curBoard5x5.clear();
	std::cout << "game ower" << std::endl;
}

Move Game::getBestMove5x5(Board5õ5& board, Player& _curPlayer, int depth)
{
	if (board.isVictoryX() && _curPlayer.cpu == 'X')
	{
		return Move(0);
	}
	if (board.isVictoryX() && _curPlayer.cpu == '0')
	{
		return Move(-10);
	}
	if (board.isVictory0() && _curPlayer.cpu == 'X')
	{
		return Move(10);
	}
	if (board.isVictory0() && _curPlayer.cpu == '0')
	{
		return Move(10);
	}
	if (board.isTie())
	{
		return Move(0);
	}	
	std::vector<Move> _moves;
	for (int row = 0; row < 5; row++)
	{
		for (int column = 0; column < 5; column++)
		{
			if (!board.getIsCellBusy(row, column))
			{
				_count++;
				Move move;
				move.row = row;
				move.column = column;				
				board.setVall(row, column, _curPlayer.changePlayer());
				if (_curPlayer._currentPlayerCpu)
					_curPlayer._currentPlayerCpu = false;
				else
					_curPlayer._currentPlayerCpu = true;
				
				move._score = getBestMove5x5(board, _curPlayer, depth)._score;
				_moves.push_back(move);
				board.popVall(row, column, _curPlayer.changePlayer());
				if (_curPlayer._currentPlayerCpu)
					_curPlayer._currentPlayerCpu = false;
				else
					_curPlayer._currentPlayerCpu = true;
			}
		}
	}
	int bestScore = 0;
	int bestMove = 0;
	if (!_curPlayer._currentPlayerCpu)
	{
		int bestScore = 1000;
		for (int i = 0; i < _moves.size(); i++)
		{
			if (_moves[i]._score < bestScore)
			{
				bestMove = i;
				bestScore = _moves[i]._score;
			}
		}
	}
	else
	{
		int bestScore = -1000;
		for (int i = 0; i < _moves.size(); i++)
		{
			if (_moves[i]._score > bestScore)
			{
				bestMove = i;
				bestScore = _moves[i]._score;
			}
		}
	}

	return _moves[bestMove];
}

Move  Game::getBestMove5x5startgame(std::vector<Move> playersMove, Board5õ5& board){
	variable.clear();
	r0 = 0;
	r1 = 0;
	r2 = 0;
	r3 = 0;
	r4 = 0;
	c0 = 0;
	c1 = 0;
	c2 = 0;
	c3 = 0;
	c4 = 0;	
	d1 = 0;
	d2 = 0;
	for (int i = 0; i < playersMove.size(); i++)
	{
		if (playersMove[i].row == 0)
		{
			r0++;

		}
		if (playersMove[i].row == 1)
		{
			r1++;
		}
		if (playersMove[i].row == 2)
		{
			r2++;
		}
		if (playersMove[i].row == 3)
		{
			r3++;
		}
		if (playersMove[i].row == 4)
		{
			r4++;
		}
		if (playersMove[i].column == 0)
		{
			c0++;
		}
		if (playersMove[i].column == 1)
		{
			c1++;
		}
		if (playersMove[i].column == 2)
		{
			c2++;
		}
		if (playersMove[i].column == 3)
		{
			c3++;
		}
		if (playersMove[i].column == 4)
		{
			c4++;
		}
		if (playersMove[i].column == 0 && playersMove[i].row == 0)
		{
			d1++;
		}
		if (playersMove[i].column == 4 && playersMove[i].row == 1)
		{
			d2++;
		}
		if (playersMove[i].column == 1 && playersMove[i].row == 1)
		{
			d1++;
		}
		if (playersMove[i].column == 3 && playersMove[i].row == 2)
		{
			d2++;
		}
		if (playersMove[i].column == 2 && playersMove[i].row == 2)
		{
			d1++;
		}
		if (playersMove[i].column == 2 && playersMove[i].row == 3)
		{
			d2++;
		}
		if (playersMove[i].column == 3 && playersMove[i].row == 3)
		{
			d1++;
		}
		if (playersMove[i].column == 1 && playersMove[i].row == 3)
		{
			d2++;
		}
	}
		variable.push_back(r0);
		variable.push_back(r1);
		variable.push_back(r2);
		variable.push_back(r3);
		variable.push_back(r4);
		variable.push_back(c0);
		variable.push_back(c1);
		variable.push_back(c2);
		variable.push_back(c3);
		variable.push_back(c4);
		variable.push_back(d1);
		variable.push_back(d2);
		int max = 0;
		int count = 0;
		for (int i = 0; i < variable.size(); i++)
		{
			if (variable[i] > max) {
				max = variable[i];
				count = i;
			}				
		}
		if (playersMoveCount > 12)
			count = 0;
		if (count == 0) //check row 1
		{
			for (int column = 0; column < 5; column++)
			{
				if (!board.getIsCellBusy(0, column))
				{
					Move _move;
					_move.column = column;
					_move.row = 0;
					return _move;
				}
				
			}			
				count++;			
		}
		if (count == 1) //check row 2
		{
			for (int column = 0; column < 5; column++)
			{
				if (!board.getIsCellBusy(1, column))
				{
					Move _move;
					_move.column = column;
					_move.row = 1;
					return _move;
				}				
			}
			count++;
		}
		if (count == 2) //check row 3
		{
			for (int column = 0; column < 4; column++)
			{
				if (!board.getIsCellBusy(2, column))
				{
					Move _move;
					_move.column = column;
					_move.row = 2;
					return _move;
				}
				else
				{
					count++;
				}
			}
		}
		if (count == 3) //check row 4
		{
			for (int column = 0; column < 5; column++)
			{
				if (!board.getIsCellBusy(3, column))
				{
					Move _move;
					_move.column = column;
					_move.row = 3;
					return _move;
				}
				else
				{
					count++;
				}
			}
		}
		if (count == 4) //check row 5
		{
			for (int column = 0; column < 5; column++)
			{
				if (!board.getIsCellBusy(4, column))
				{
					Move _move;
					_move.column = column;
					_move.row = 4;
					return _move;
				}
				else
				{
					count++;
				}
			}
		}
		if (count == 5) //check column 1
		{
			for (int row = 0; row < 5; row++)
			{
				if (!board.getIsCellBusy(row, 0))
				{
					Move _move;
					_move.column = 0;
					_move.row = row;
					return _move;
				}
				else
				{
					count++;
				}
			}
		}
		if (count == 6) //check column 2
		{
			for (int row = 0; row < 5; row++)
			{
				if (!board.getIsCellBusy(row, 1))
				{
					Move _move;
					_move.column = 1;
					_move.row = row;
					return _move;
				}
				else
				{
					count++;
				}
			}
		}
		if (count == 7) //check column 3
		{
			for (int row = 0; row < 5; row++)
			{
				if (!board.getIsCellBusy(row, 2))
				{
					Move _move;
					_move.column = 2;
					_move.row = row;
					return _move;
				}
				else
				{
					count++;
				}
			}
		}
		if (count == 8) //check column 4
		{
			for (int row = 0; row < 5; row++)
			{
				if (!board.getIsCellBusy(row, 3))
				{
					Move _move;
					_move.column = 3;
					_move.row = row;
					return _move;
				}
				else
				{
					count++;
				}
			}
		}
		if (count == 9) //check column 5
		{
			for (int column = 0; column < 5; column++)
			{
				if (!board.getIsCellBusy(4, column))
				{
					Move _move;
					_move.column = column;
					_move.row = 4;
					return _move;
				}
				else
				{
					count++;
				}
			}
		}
		if (count == 10) //check d1
		{			
			for (int i = 0; i < 5; i++)
			{
				if (!board.getIsCellBusy(i, i))
				{
					Move _move;
					_move.column = i;
					_move.row = i;
					return _move;
				}
				else
				{
					count++;
				}
			}
		}
		if (count == 11) //check d2
		{
			for (int i = 0; i < 5; i++)
			{
				if (!board.getIsCellBusy(i, 4-i))
				{
					Move _move;
					_move.column = i;
					_move.row = i;
					return _move;
				}
			}
		}
		return getBestMove5x5(board, _curPlayer, 0);
	
		
}
	

void Game::round5x5CPU()
{
	bool final = false;
	playersMoveCount = 0;
	while (!final) {
		std::cout << "CPU Move" << std::endl;
		_count = 0;
		if (playersMoveCount < 10)
		{
			Move _move = getBestMove5x5startgame(playersMove, _curBoard5x5);
			_curBoard5x5.setVall(_move.row, _move.column, _curPlayer.changePlayer());
			_curPlayer._currentPlayerCpu = true;
			_curBoard5x5.printBoard5x5();
			if (_curBoard5x5.isVictory0() || _curBoard5x5.isVictoryX())
				final = true;
			if (_curBoard5x5.isTie())
				final = true;
			playersMoveCount++;
		}
		else
		{
			Move _move = getBestMove5x5(_curBoard5x5, _curPlayer, 0);
			_curBoard5x5.setVall(_move.row, _move.column, _curPlayer.changePlayer());
			_curPlayer._currentPlayerCpu = true;
			_curBoard5x5.printBoard5x5();
			if (_curBoard5x5.isVictory0() || _curBoard5x5.isVictoryX())
				final = true;
			if (_curBoard5x5.isTie())
				final = true;
		}
	}
}


