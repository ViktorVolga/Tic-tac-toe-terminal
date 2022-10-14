#pragma once

class Cell
{
public:
	bool _isX = false;
	bool _isO = false;
	bool _isBusy = false;	
};

class Player {
public:
	Player(){}
	bool _currentPlayerCpu = false;
	bool _currentPlayerX = false;
	bool _currentPlayer0 = false;
	char cpu = '0';
	int changePlayer()
	{
		if (_currentPlayerX) {
			_currentPlayerX = false;
			_currentPlayer0 = true;
			return 1;
		}
		else {
			_currentPlayerX = true;
			_currentPlayer0 = false;
			return 0;

		}
			
	}
};



