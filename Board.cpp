#include "Board.h"

bool Board3�3::isVictoryX()
{
	if (_board3�3[0][0]._isX && _board3�3[0][1]._isX)
		if (_board3�3[0][2]._isX)
			return true;
	if (_board3�3[1][0]._isX && _board3�3[1][1]._isX)
		if (_board3�3[1][2]._isX)
			return true;
	if (_board3�3[2][0]._isX && _board3�3[2][1]._isX)
		if (_board3�3[2][2]._isX)
			return true;
	if (_board3�3[0][0]._isX && _board3�3[1][0]._isX)
		if (_board3�3[2][0]._isX)
			return true;
	if (_board3�3[0][1]._isX && _board3�3[1][1]._isX)
		if (_board3�3[2][1]._isX)
			return true;
	if (_board3�3[0][2]._isX && _board3�3[1][2]._isX)
		if (_board3�3[2][2]._isX)
			return true;
	if (_board3�3[0][0]._isX && _board3�3[1][1]._isX)
		if (_board3�3[2][2]._isX)
			return true;
	if (_board3�3[0][2]._isX && _board3�3[1][1]._isX)
		if (_board3�3[2][0]._isX)
			return true;	
	return false;
}
bool Board3�3::isVictory0()
{
	if (_board3�3[0][0]._isO && _board3�3[0][1]._isO) {
		if (_board3�3[0][2]._isO) {
			return true;
		}			
	}		
	else if (_board3�3[1][0]._isO && _board3�3[1][1]._isO)
		if (_board3�3[1][2]._isO)
			return true;
	if (_board3�3[2][0]._isO && _board3�3[2][1]._isO)
		if (_board3�3[2][2]._isO)
			return true;
	if (_board3�3[0][0]._isO && _board3�3[1][0]._isO)
		if (_board3�3[2][0]._isO)
			return true;
	if (_board3�3[0][1]._isO && _board3�3[1][1]._isO)
		if (_board3�3[2][1]._isO)
			return true;
	if (_board3�3[0][2]._isO && _board3�3[1][2]._isO)
		if (_board3�3[2][2]._isO)
			return true;
	if (_board3�3[0][0]._isO && _board3�3[1][1]._isO)
		if (_board3�3[2][2]._isO)
			return true;
	if (_board3�3[0][2]._isO && _board3�3[1][1]._isO)
		if (_board3�3[2][0]._isO)
			return true;
	return false;
}

void Board3�3::printBoard3x3()
{
	std::string horisont = "______________";
	std::cout << horisont << std::endl;
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			if (_board3�3[row][column]._isBusy) {
				if (_board3�3[row][column]._isX) {					
					std::cout << "| X |";					
				}
				else {					
					std::cout << "| O |";					
				}
			}
			else {				
				std::cout << "|   |";				
			}

		}
		std::cout << std::endl << horisont << std::endl;
	}
}

bool Board3�3::getIsCellBusy(int row, int column)
{
	if (_board3�3[row][column]._isBusy)
		return true;
	else
		return false;
}

void Board3�3::setVall(int row, int column, int XorY) //if X - return 1
{
	_board3�3[row][column]._isBusy = true;
	if (XorY == 1)
		_board3�3[row][column]._isX = true;
	else
		_board3�3[row][column]._isO = true;
}

bool Board5�5::isVictoryX()
{
	if (_board5�5[0][0]._isX && _board5�5[0][1]._isX)
		if (_board5�5[0][2]._isX && _board5�5[0][3]._isX)
			if (_board5�5[0][4]._isX)
				return true;
	if (_board5�5[1][0]._isX && _board5�5[1][1]._isX)
		if (_board5�5[1][2]._isX && _board5�5[1][3]._isX)
			if (_board5�5[1][4]._isX)
				return true;
	if (_board5�5[2][0]._isX && _board5�5[2][1]._isX)
		if (_board5�5[2][2]._isX && _board5�5[2][3]._isX)
			if (_board5�5[2][4]._isX)
				return true;
	if (_board5�5[3][0]._isX && _board5�5[3][1]._isX)
		if (_board5�5[3][2]._isX && _board5�5[3][3]._isX)
			if (_board5�5[3][4]._isX)
				return true;
	if (_board5�5[4][0]._isX && _board5�5[4][1]._isX)
		if (_board5�5[4][2]._isX && _board5�5[4][3]._isX)
			if (_board5�5[4][4]._isX)
				return true;
	if (_board5�5[0][0]._isX && _board5�5[1][0]._isX)
		if (_board5�5[2][0]._isX && _board5�5[3][0]._isX)
			if (_board5�5[4][0]._isX)
				return true;
	if (_board5�5[0][1]._isX && _board5�5[1][1]._isX)
		if (_board5�5[2][1]._isX && _board5�5[3][1]._isX)
			if (_board5�5[4][1]._isX)
				return true;
	if (_board5�5[0][2]._isX && _board5�5[1][2]._isX)
		if (_board5�5[2][2]._isX && _board5�5[3][2]._isX)
			if (_board5�5[4][2]._isX)
				return true;
	if (_board5�5[0][3]._isX && _board5�5[1][3]._isX)
		if (_board5�5[2][3]._isX && _board5�5[3][3]._isX)
			if (_board5�5[4][3]._isX)
				return true;
	if (_board5�5[0][4]._isX && _board5�5[1][4]._isX)
		if (_board5�5[2][4]._isX && _board5�5[3][4]._isX)
			if (_board5�5[4][4]._isX)
				return true;
	if (_board5�5[0][0]._isX && _board5�5[1][1]._isX)
		if (_board5�5[2][2]._isX && _board5�5[3][3]._isX)
			if (_board5�5[4][4]._isX)
				return true;
	if (_board5�5[4][0]._isX && _board5�5[3][1]._isX)
		if (_board5�5[2][2]._isX && _board5�5[1][3]._isX)
			if (_board5�5[0][4]._isX)
				return true;
	return false;
}

void Board3�3::popVall(int row, int column, int XorY)
{
	_board3�3[row][column]._isBusy = false;
	_board3�3[row][column]._isX = false;
	_board3�3[row][column]._isO = false;		
}

void Board5�5::printBoard5x5()
{
	std::string horisont = "________________________";
	std::cout << horisont << std::endl;
	for (int row = 0; row < 5; row++) {
		for (int column = 0; column < 5; column++) {
			if (_board5�5[row][column]._isBusy) {
				if (_board5�5[row][column]._isX) {
					std::cout << "| X |";
				}
				else {
					std::cout << "| O |";
				}
			}
			else {
				std::cout << "|   |";
			}
		}
		std::cout << std::endl << horisont << std::endl;
	}
}

bool Board3�3::isTie() {
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			if (!_board3�3[row][column]._isBusy)
				return false;
		}
	}
	if (isVictoryX() || isVictory0())
	{
		return false;
	}

		
	return true;
}

void Board5�5::setVall(int row, int column, int XorY) //if X - return 1
{
	_board5�5[row][column]._isBusy = true;
	if (XorY == 1)
		_board5�5[row][column]._isX = true;
	else
		_board5�5[row][column]._isO = true;
}

bool Board5�5::isVictory0()
{
	if (_board5�5[0][0]._isO && _board5�5[0][1]._isO) 
		if (_board5�5[0][2]._isO && _board5�5[0][3]._isO)
			if(_board5�5[0][4]._isO)
				return true;
	if (_board5�5[1][0]._isO && _board5�5[1][1]._isO)
		if (_board5�5[1][2]._isO && _board5�5[1][3]._isO)
			if (_board5�5[1][4]._isO)
				return true;
	if (_board5�5[2][0]._isO && _board5�5[2][1]._isO)
		if (_board5�5[2][2]._isO && _board5�5[2][3]._isO)
			if (_board5�5[2][4]._isO)
				return true;
	if (_board5�5[3][0]._isO && _board5�5[3][1]._isO)
		if (_board5�5[3][2]._isO && _board5�5[3][3]._isO)
			if (_board5�5[3][4]._isO)
				return true;
	if (_board5�5[4][0]._isO && _board5�5[4][1]._isO)
		if (_board5�5[4][2]._isO && _board5�5[4][3]._isO)
			if (_board5�5[4][4]._isO)
				return true;
	if (_board5�5[0][0]._isO && _board5�5[1][0]._isO)
		if (_board5�5[2][0]._isO && _board5�5[3][0]._isO)
			if (_board5�5[4][0]._isO)
				return true;
	if (_board5�5[0][1]._isO && _board5�5[1][1]._isO)
		if (_board5�5[2][1]._isO && _board5�5[3][1]._isO)
			if (_board5�5[4][1]._isO)
				return true;
	if (_board5�5[0][2]._isO && _board5�5[1][2]._isO)
		if (_board5�5[2][2]._isO && _board5�5[3][2]._isO)
			if (_board5�5[4][2]._isO)
				return true;
	if (_board5�5[0][3]._isO && _board5�5[1][3]._isO)
		if (_board5�5[2][3]._isO && _board5�5[3][3]._isO)
			if (_board5�5[4][3]._isO)
				return true;
	if (_board5�5[0][4]._isO && _board5�5[1][4]._isO)
		if (_board5�5[2][4]._isO && _board5�5[3][4]._isO)
			if (_board5�5[4][4]._isO)
				return true;
	if (_board5�5[0][0]._isO && _board5�5[1][1]._isO)
		if (_board5�5[2][2]._isO && _board5�5[3][3]._isO)
			if (_board5�5[4][4]._isO)
				return true;
	if (_board5�5[4][0]._isO && _board5�5[3][1]._isO)
		if (_board5�5[2][2]._isO && _board5�5[1][3]._isO)
			if (_board5�5[0][4]._isO)
				return true;
	return false;	
}

bool Board5�5::isTie() {
	for (int row = 0; row < 5; row++)
	{
		for (int column = 0; column < 5; column++)
		{
			if (!_board5�5[row][column]._isBusy)
				return false;
		}
	}
	if (isVictoryX() || isVictory0())
	{
		return false;
	}


	return true;
}

bool Board5�5::getIsCellBusy(int row, int column)
{
	if (_board5�5[row][column]._isBusy)
		return true;
	else
		return false;
}

void Board5�5::popVall(int row, int column, int XorY)
{
	_board5�5[row][column]._isBusy = false;
	_board5�5[row][column]._isX = false;
	_board5�5[row][column]._isO = false;
}
void Board5�5::clear()
{
	for (int row = 0; row < 5; row++) {
		for (int column = 0; column < 5; column++)
		{
			popVall(row, column, 0);
		}
	}
}

void Board3�3::clear()
{
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++)
		{
			popVall(row, column, 0);
		}
	}
}
