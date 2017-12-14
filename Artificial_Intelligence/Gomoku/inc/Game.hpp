//
// Game.hpp for Game in /home/storm/IA/Gomoku/src
//
// Made by caille_j
// Login   <caille_j@epitech.net>
//
// Started on  Mon Nov  3 11:20:58 2014
// Last update Wed Nov 12 14:13:22 2014 caille_j
//

#ifndef _GAME_HPP_
# define _GAME_HPP_

# include "Display.hpp"
# include "Referee.hpp"
# include <unistd.h>
# include "Board.hh"

class	Game : public Display
{
public:
	Game(sf::RenderWindow *window, Sound *sound, sf::Event *event, const std::string &);
	~Game();
	virtual bool initialize();
	const std::string	events();
	bool			hotKeys(const sf::Event::EventType &type);
	void			show();
	void			drawBoard();
	void			drawUi();
  void			verifyStones();
private:
	Board	_board;
	Referee _referee;
	short	_option1;
	short	_option2;
	int		_player;
	//	char	*_board;
	bool	_finish;
	bool	_win;
};

#endif /* !_GAME_HPP_ */
