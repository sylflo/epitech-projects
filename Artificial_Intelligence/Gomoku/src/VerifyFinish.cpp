//
// VerifyFinish.cpp for gomoku in /home/storm/IA/Gomoku/src
//
// Made by caille_j
// Login   <caille_j@epitech.net>
//
// Started on  Wed Nov 12 14:12:22 2014
// Last update Wed Nov 12 14:45:08 2014 pierre
//

#include "Game.hpp"

void	Game::verifyStones()
{
	if (_referee.getStonesPlayer1() == 10)
		{
			_text.setCharacterSize(100);
			_text.setString("Player 1 wins !");
			_text.setPosition(200, 300);
			_window->draw(_text);
			_window->display();
			_win = !_win;
			usleep(1000000);
		}
	else if (_referee.getStonesPlayer2() == 10)
		{
			_text.setCharacterSize(100);
			_text.setString("Player 2 wins !");
			_text.setPosition(200, 300);
			_window->draw(_text);
			_window->display();
			_win = !_win;
			usleep(1000000);
		}
	if (_referee.getWin() != 0)
		{
			if (_referee.getWin() == 1)
				{
					_text.setCharacterSize(100);
					_text.setString("Player 1 wins !");
					_text.setPosition(200, 300);
					_window->draw(_text);
					_window->display();
					_win = !_win;
					usleep(1000000);
				}
			else if (_referee.getWin() == 2)
				{
					_text.setCharacterSize(100);
					_text.setString("Player 2 wins !");
					_text.setPosition(200, 300);
					_window->draw(_text);
					_window->display();
					_win = !_win;
					usleep(1000000);
				}
		}
}
