//
// Game.cpp for ia in /home/storm/IA/Gomoku/src
//
// Made by caille_j
// Login   <caille_j@epitech.net>
//
// Started on  Mon Nov 10 21:34:35 2014
// Last update Wed Nov 12 14:16:08 2014 caille_j
//

#include "Game.hpp"
#include <boost/lexical_cast.hpp>

Game::Game(sf::RenderWindow *window, Sound *sound, sf::Event *event, const std::string &options) : _board()
{
  _window = window;
  _sound = sound;
  _event = event;
  _option1 = boost::lexical_cast<short>(options[0]);
  _option2 = boost::lexical_cast<short>(options[1]);
  _finish = false;
  _win = false;
  _player = 1;
}

Game::~Game()
{
}

bool	Game::initialize()
{
	//  int	i;

  if (!_textures.newTexture("./res/pictures/tatami.png", "tatami", sf::IntRect(0, 0, 40, 40)) ||
      !_textures.newTexture("./res/pictures/ui_panel.png", "ui_panel", sf::IntRect(0, 0, 264, 768)) ||
      !_textures.newTexture("./res/pictures/black.png", "black", sf::IntRect(0, 0, 40, 40)) ||
      !_textures.newTexture("./res/pictures/white.png", "white", sf::IntRect(0, 0, 40, 40)))
    return (false);
  if (!_font.loadFromFile("./res/fonts/ombre.ttf"))
    {
      throw Exception("[ERROR] : couldn't load font zentai.ttf");
      return (false);
    }
  _text.setFont(_font);
  // _board = new char[(19 * 19) + 1];
  // i = -1;
  // while (++i < 19 * 19)
  //   _board[i] = 0;
  _referee.initialize(&_board);
  return (true);
}

const std::string	Game::events()
{
  if (_window->isOpen())
    {
      if (_win)
	return ("again");
      if (_window->pollEvent(*_event))
	if (!hotKeys(_event->type))
	  {
	    return ("quit");
	  }
      return ("continue");
    }
  return ("quit");
}

void	Game::show()
{
  _window->clear();
  drawBoard();
  drawUi();
  verifyStones();
  _window->display();
}
