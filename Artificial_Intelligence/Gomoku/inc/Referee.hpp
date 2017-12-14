//
// Referee.hpp for gomoku in /home/storm/IA/Gomoku/inc
//
// Made by caille_j
// Login   <caille_j@epitech.net>
//
// Started on  Tue Nov 11 16:31:26 2014
// Last update Wed Jan 14 12:04:26 2015 pierre
//

#ifndef _REFEREE_HPP_
# define _REFEREE_HPP_

# include <iostream>
# include "Board.hh"

class	Referee
{
public:
	Referee();
	~Referee();
	void	initialize(Board *);
	void	check(const int &, const int &, int *);
	const int	&getStonesPlayer1() const;
	const int	&getStonesPlayer2() const;
	void		captureStone(int y, int x, int player);
	bool    doubleThreeCheck(int y, int x, int player);
	bool    optionalEnd(int,int,int player);
	bool    canPlaceStone(int y, int x, int player);
	int getWin();
	bool	checkFive(int _y, int _x, int player);
	bool	canCapture(int y, int x, int player);
private:
	bool threeRule;
	bool optionalEndRule;
	int	winType;
	bool  win;
	Board *_board;
	//	char *_board;
	int	_player1;
	int	_player2;
};

#endif /* !_REFEREE_HPP_ */
