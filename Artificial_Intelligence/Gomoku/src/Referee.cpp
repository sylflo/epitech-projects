//
// Referee.cpp for gomoku in /home/storm/IA/Gomoku/src
//
// Made by caille_j
// Login   <caille_j@epitech.net>
//
// Started on  Tue Nov 11 16:33:39 2014
// Last update Wed Jan 14 12:14:08 2015 pierre
//

#include "Referee.hpp"

Referee::Referee()
{
  _player1 = 0;
  _player2 = 0;
  win = 0;
  winType = 0;
  threeRule = false;
  optionalEndRule = false;
}

Referee::~Referee()
{
}

void	Referee::initialize(Board *board)
{
  _board = board;
}

void	Referee::check(const int &x, const int &y, int *player)
{
	if (canPlaceStone(y, x, *player) == true)
		{
			_board->addStone(y, x, (Board::cell)*player);
			captureStone(y,x,*player);
			if (checkFive(y, x, *player) == true)
				{
					if (*player == 1)
						win = 1;
					else if (*player == 2)
						win = 2;
					if (optionalEndRule == true)
						if (optionalEnd(x,y,*player) == false)
							win = 0;
				}
			if (*player == 1)
				*player = 2;
			else
				*player = 1;
		}
}

const int	&Referee::getStonesPlayer1() const
{
  return (_player1);
}

const int	&Referee::getStonesPlayer2() const
{
  return (_player2);
}

bool	Referee::canCapture(int y, int x, int player)
{
    int me = player;
    int op = me == Board::Black ? Board::White : Board::Black;

    if ((*_board)(y, x - 3) == me && ((*_board)(y, x - 2) == op && (*_board)(y, x - 1) == op))
		return true;
    if ((*_board)(y, x + 3) == me && ((*_board)(y, x + 2) == op && (*_board)(y, x + 1) == op))
		return true;
    if ((*_board)(y - 3, x) == me && ((*_board)(y - 2, x) == op && (*_board)(y - 1, x) == op))
		return true;
    if ((*_board)(y + 3, x) == me && ((*_board)(y + 2, x) == op && (*_board)(y + 1, x) == op))
		return true;
    if ((*_board)(y-3, x - 3) == me && ((*_board)(y-2, x - 2) == op && (*_board)(y-1, x - 1) == op))
		return true;
    if ((*_board)(y+3, x - 3) == me && ((*_board)(y+2, x - 2) == op && (*_board)(y+1, x - 1) == op))
		return true;
    if ((*_board)(y-3, x + 3) == me && ((*_board)(y-2, x + 2) == op && (*_board)(y-1, x + 1) == op))
		return true;
    if ((*_board)(y+3, x + 3) == me && ((*_board)(y+2, x + 2) == op && (*_board)(y+1, x + 1) == op))
		return true;
	return false;
}

void    Referee::captureStone(int y, int x, int player)
{
    int me = player;
    int op = me == Board::Black ? Board::White : Board::Black;

    if ((*_board)(y, x - 3) == me && ((*_board)(y, x - 2) == op && (*_board)(y, x - 1) == op))
		{
			if (player == Board::White)
				_player1 += 2;
			else
				_player2 += 2;
			_board->removeStone(y, x - 1);
			_board->removeStone(y, x - 2);
		}
    if ((*_board)(y, x + 3) == me && ((*_board)(y, x + 2) == op && (*_board)(y, x + 1) == op))
		{
			if (player == Board::White)
				_player1 += 2;
			else
				_player2 += 2;
			_board->removeStone(y, x + 1);
			_board->removeStone(y, x + 2);
		}
    if ((*_board)(y - 3, x) == me && ((*_board)(y - 2, x) == op && (*_board)(y - 1, x) == op))
		{
			if (player == Board::White)
				_player1 += 2;
			else
				_player2 += 2;
			_board->removeStone(y - 2, x);
			_board->removeStone(y - 1, x);
		}
    if ((*_board)(y + 3, x) == me && ((*_board)(y + 2, x) == op && (*_board)(y + 1, x) == op))
		{
			if (player == Board::White)
				_player1 += 2;
			else
				_player2 += 2;
			_board->removeStone(y + 2, x);
			_board->removeStone(y + 1, x);
		}
    if ((*_board)(y-3, x - 3) == me && ((*_board)(y-2, x - 2) == op && (*_board)(y-1, x - 1) == op))
		{
			if (player == Board::White)
				_player1 += 2;
			else
				_player2 += 2;
			_board->removeStone(y-1, x - 1);
			_board->removeStone(y-2, x - 2);
		}
    if ((*_board)(y+3, x - 3) == me && ((*_board)(y+2, x - 2) == op && (*_board)(y+1, x - 1) == op))
		{
			if (player == Board::White)
				_player1 += 2;
			else
				_player2 += 2;
			_board->removeStone(y+1, x - 1);
			_board->removeStone(y+2, x - 2);
		}
    if ((*_board)(y-3, x + 3) == me && ((*_board)(y-2, x + 2) == op && (*_board)(y-1, x + 1) == op))
		{
			if (player == Board::White)
				_player1 += 2;
			else
				_player2 += 2;
			_board->removeStone(y-1, x + 1);
			_board->removeStone(y-2, x + 2);
		}
    if ((*_board)(y+3, x + 3) == me && ((*_board)(y+2, x + 2) == op && (*_board)(y+1, x + 1) == op))
		{
			if (player == Board::White)
				_player1 += 2;
			else
				_player2 += 2;
			_board->removeStone(y+1, x + 1);
			_board->removeStone(y+2, x + 2);
		}
}

bool	Referee::checkFive(int _y, int _x, int player)
{
	int	count = 0;
	int y = _y;
	int x = _x;

	while ((*_board)(y--, x) == player)
		++count;
	if (count == 5)
		return true;
	y = _y+1;
	while ((*_board)(y++, x) == player)
		++count;
	if (count == 5)
		return true;
	winType = 1;
	count = 0;
	y = _y;
	while ((*_board)(y, x--) == player)
		++count;
	if (count == 5)
		return true;
	x = _x+1;
	while ((*_board)(y, x++) == player)
		++count;
	if (count == 5)
		return true;
	x = _x;
	y = _y;
	count = 0;
	winType = 2;
	while ((*_board)(y--, x--) == player)
		++count;
	if (count == 5)
		return true;
	x = _x+1;
	y = _y+1;
	while ((*_board)(y++, x++) == player)
		++count;
	if (count == 5)
		return true;
	x = _x;
	y = _y;
	count = 0;
	winType = 3;
	while ((*_board)(y++, x--) == player)
		++count;
	if (count == 5)
		return true;
	x = _x+1;
	y = _y-1;
	while ((*_board)(y--, x++) == player)
		++count;
	if (count == 5)
		return true;
	return false;

}

int Referee::getWin()
{
	return (win);
}

bool    Referee::doubleThreeCheck(int y, int x, int player)
{
	(void)y;
	(void)x;
	(void)player;
	return false;
}

bool    Referee::optionalEnd(int _x, int _y, int player)
{
	int x = _x;
	int y = _y;
	if (winType == 0)
		{
			while ((*_board)(y--, x) == player)
				if (canCapture(x, y, player) == true)
					return false;
			y = _y+1;
			while ((*_board)(y++, x) == player)
				if (canCapture(x, y, player) == true)
					return false;
		}
	if (winType == 1)
		{
			while ((*_board)(y, x--) == player)
				if (canCapture(x, y, player) == true)
					return false;
			x = _x+1;
			while ((*_board)(y, x++) == player)
				if (canCapture(x, y, player) == true)
					return false;
		}
	if (winType == 2)
		{
			while ((*_board)(y--, x--) == player)
				if (canCapture(x, y, player) == true)
					return false;
			x = _x+1;
			y = _y+1;
			while ((*_board)(y++, x++) == player)
				if (canCapture(x, y, player) == true)
					return false;
		}
	if (winType == 3)
		{
			while ((*_board)(y++, x--) == player)
				if (canCapture(x, y, player) == true)
					return false;
			x = _x+1;
			y = _y-1;
			while ((*_board)(y--, x++) == player)
				if (canCapture(x, y, player) == true)
					return false;
		}
	return true;
}

bool    Referee::canPlaceStone(int y, int x, int player)
{
	(void)(player);
    if ((*_board)(y, x) != Board::Empty)
        return (false);
    else
        return (true);
}