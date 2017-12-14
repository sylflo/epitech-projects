#pragma once
#include <vector>
#include <iostream>

class Board
{
public:
	typedef enum cell
	{
		Empty,
		White,
		Black,
		Out
	}	cell;
private:
	int							width;
	int							height;
	int							tab_length;
	char						tab[19 * 19];
public:
	Board();
	~Board();
public:
	void		addStone(int y, int x, Board::cell color);
	void		removeStone(int y, int x);
	Board::cell	operator()(int y, int x);
	void		debugBoard();
};
