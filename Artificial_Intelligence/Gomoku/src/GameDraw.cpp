//
// GameDraw.cpp for ia in /home/storm/IA/Gomoku/src
//
// Made by caille_j
// Login   <caille_j@epitech.net>
//
// Started on  Tue Nov 11 13:53:17 2014
// Last update Sun Jan  4 18:59:07 2015 caille_j
//

#include "Game.hpp"
#include <boost/lexical_cast.hpp>

void		Game::drawBoard()
{
  int		i;
  int		i2;
  sf::Vector2i	localPosition;

  i = -1;
  i2 = -1;
  localPosition = sf::Mouse::getPosition(*_window);
  while (++i < 19)
    {
      while (++i2 < 19)
	{
	  _textures.spriteLabel("tatami")->setPosition(sf::Vector2f(i2 * 40 , i * 40));
	  _window->draw(*_textures.spriteLabel("tatami"));
	  if (localPosition.x - 40 > (i2 - 1) * 40 && localPosition.x - 40 < i2 * 40 &&
	      localPosition.y - 40 > (i - 1) * 40 && localPosition.y - 40 < i * 40)
	    {
	      if (_board(i, i2) == 0)
		{
		  if (_player == 1)
		    {
		      _textures.spriteLabel("white")->setColor(sf::Color(255, 255, 255, 128));
		      _textures.spriteLabel("white")->setPosition(sf::Vector2f(i2 * 40 , i * 40));
		      _window->draw(*_textures.spriteLabel("white"));
		      _textures.spriteLabel("white")->setColor(sf::Color(255, 255, 255, 255));
		    }
		  else
		    {
		      _textures.spriteLabel("black")->setColor(sf::Color(255, 255, 255, 128));
		      _textures.spriteLabel("black")->setPosition(sf::Vector2f(i2 * 40 , i * 40));
		      _window->draw(*_textures.spriteLabel("black"));
		      _textures.spriteLabel("black")->setColor(sf::Color(255, 255, 255, 255));
		    }
		}
	    }
	  if (_board(i, i2) == 1)
	    {
	      _textures.spriteLabel("white")->setPosition(sf::Vector2f(i2 * 40 , i * 40));
	      _window->draw(*_textures.spriteLabel("white"));
	    }
	  else if (_board(i, i2) == 2)
	    {
	      _textures.spriteLabel("black")->setPosition(sf::Vector2f(i2 * 40 , i * 40));
	      _window->draw(*_textures.spriteLabel("black"));
	    }
	}
      i2 = -1;
    }
}

void		Game::drawUi()
{
  sf::Vector2i	localPosition = sf::Mouse::getPosition(*_window);

  _textures.spriteLabel("ui_panel")->setPosition(sf::Vector2f(760, 0));
  _window->draw(*_textures.spriteLabel("ui_panel"));
  _text.setCharacterSize(100);
  _text.setString("Gomoku");
  _text.setPosition(795, -50);
  _window->draw(_text);
  if (_player == 1)
    _text.setColor(sf::Color::Blue);
  _text.setString("Player 1");
  _text.setPosition(795, 50);
  _window->draw(_text);
  _text.setCharacterSize(70);
  _text.setString("Stones Taken");
  _text.setPosition(795, 150);
  _window->draw(_text);
  _text.setString(boost::lexical_cast<std::string>(_referee.getStonesPlayer1()));
  _text.setPosition(875, 225);
  _window->draw(_text);
  _text.setCharacterSize(100);
  _text.setColor(sf::Color::White);
  if (_player == 2)
    _text.setColor(sf::Color::Blue);
  _text.setString("Player 2");
  _text.setPosition(795, 300);
  _window->draw(_text);
  _text.setCharacterSize(70);
  _text.setString("Stones Taken");
  _text.setPosition(795, 400);
  _window->draw(_text);
    _text.setString(boost::lexical_cast<std::string>(_referee.getStonesPlayer2()));
  _text.setPosition(875, 475);
  _window->draw(_text);
  _text.setCharacterSize(100);
  _text.setColor(sf::Color::White);
  _text.setString("Quit");
  _text.setPosition(815, 550);
  if (localPosition.x >= 815 && localPosition.x <= 950 &&
      localPosition.y >= 550 && localPosition.y <= 650)
    _text.setColor(sf::Color::Red);
  _window->draw(_text);
  _text.setColor(sf::Color::White);
}
