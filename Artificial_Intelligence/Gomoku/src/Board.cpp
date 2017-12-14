#include "Board.hh"

Board::Board() : tab()
{
	width = 19;
	height = 19;
	tab_length = 19 * 19;
	for (int i = 0; i < 19 * 19; ++i)
		tab[i] = Empty;
}

Board::~Board()
{
}

void		Board::addStone(int y, int x, Board::cell color)
{
	tab[y * width + x] = color;
}

void		Board::removeStone(int y, int x)
{
	tab[y * width + x] = Empty;
}

Board::cell	Board::operator()(int y, int x)
{
	if (y < 0 || y > 18)
		return (Out);
	else if (x < 0 || x > 18)
		return (Out);
	return ((Board::cell)tab[y * width + x]);
}

void		Board::debugBoard()
{
	for (int i = 0; i < tab_length; ++i)
	{
		if (i % width == 0 && i != 0)
			std::cout << std::endl;
		std::cout << (int)tab[i];
	}
	std::cout << std::endl;
}
