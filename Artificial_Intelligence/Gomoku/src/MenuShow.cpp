//
// MenuShow.cpp for gomoku in /home/storm/IA/Gomoku/src
//
// Made by caille_j
// Login   <caille_j@epitech.net>
//
// Started on  Sun Nov  9 17:16:55 2014
// Last update Tue Nov 11 12:46:12 2014 caille_j
//

#include "Menu.hpp"

void	Menu::homeScreen()
{
  std::string	mode;

  if (!_mode)
    mode = "Mode Player vs Player";
  else
    mode = "Mode Player vs Computer";
  _text.setPosition(300, 250);
  _text.setString(mode);
  if (line == 1)
    _text.setColor(sf::Color::Red);
  _window->draw(_text);
  _text.setColor(sf::Color::White);
  if (line == 2)
    _text.setColor(sf::Color::Red);
  _text.setPosition(450, 350);
  _text.setString("Options");
  _window->draw(_text);
  _text.setColor(sf::Color::White);
  if (line == 3)
    _text.setColor(sf::Color::Red);
  _text.setPosition(350, 420);
  _text.setCharacterSize(80);
  _text.setString("start   the game");
  _window->draw(_text);
  _text.setCharacterSize(60);
  _text.setColor(sf::Color::White);
    if (line == 4)
    _text.setColor(sf::Color::Red);
  _text.setPosition(470, 550);
  _text.setString("Quit");
  _window->draw(_text);
  _text.setColor(sf::Color::White);
}

void	Menu::verifyPos()
{
  if (subMenu == 0)
    {
      if (line < 1)
	line = 4;
      if (line > 4)
	line = 1;
    }
  else if (subMenu == 1)
    {
      if (line < 1)
	line = 3;
      if (line > 3)
	line = 1;
    }
}

void	Menu::optionsScreen()
{
  _text.setString("Five in a row breaker");
  _text.setPosition(200, 250);
  if (line == 1)
    _text.setColor(sf::Color::Red);
  _window->draw(_text);
  _text.setPosition(600, 250);
  if (_option1 == 0)
    _text.setString("Disabled");
  else
    _text.setString("Enabled");
  _window->draw(_text);
  _text.setColor(sf::Color::White);
  _text.setString("Double three forbidding");
  _text.setPosition(200, 350);
  if (line == 2)
    _text.setColor(sf::Color::Red);
  _window->draw(_text);
  _text.setPosition(650, 350);
  if (_option2 == 0)
    _text.setString("Disabled");
  else
    _text.setString("Enabled");
  _window->draw(_text);
  _text.setColor(sf::Color::White);
    if (line == 3)
    _text.setColor(sf::Color::Red);
  _text.setPosition(470, 550);
  _text.setString("Back");
  _window->draw(_text);
  _text.setColor(sf::Color::White);
}

void	Menu::showWritten()
{
  verifyPos();
  _text.setPosition(230, -60);
  _text.setCharacterSize(200);
  _text.setString("g o m o k u");
  _window->draw(_text);
  _text.setCharacterSize(60);
  if (subMenu == 0)
    homeScreen();
  else if (subMenu == 1)
    optionsScreen();
}

void	Menu::showStatic()
{
  _window->draw(*_textures.spriteLabel("background"));
}
