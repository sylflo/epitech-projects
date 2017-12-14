//
// Menu.cpp for Menu in /home/storm/IA/Gomoku/src
//
// Made by caille_j
// Login   <caille_j@epitech.net>
//
// Started on  Mon Nov  3 11:38:17 2014
// Last update Tue Nov 11 13:02:14 2014 caille_j
//

#include "Menu.hpp"
#include <boost/lexical_cast.hpp>

Menu::Menu(sf::RenderWindow *window, Sound *sound,
	    sf::Event *event)
{
  _window = window;
  _sound = sound;
  _event = event;
  subMenu = 0;
  line = 1;
  _mode = 0;
  _option1 = 0;
  _option2 = 0;
}

Menu::~Menu()
{
}

bool	Menu::initialize()
{
  if (!_sound->newChannel("./res/sound/menu.ogg", "menu_theme"))
    return (false);
  if (!_textures.newTexture("./res/pictures/menu_background.jpg", "background", sf::IntRect(0, 0, 1024, 768)))
    return (false);
  if (!_font.loadFromFile("./res/fonts/zentai.ttf"))
    {
      throw Exception("[ERROR] : couldn't load font zentai.ttf");
      return (false);
    }
  _text.setFont(_font);
  _sound->soundLabel("menu_theme")->setLoop(true);
  _window->setKeyRepeatEnabled(false);
  return (true);
}

const std::string	Menu::parseOptions()
{
  std::string		options;

  options += boost::lexical_cast<std::string>(_option1);
  options += boost::lexical_cast<std::string>(_option2);
  _sound->removeAll();
  return (options);
}

const std::string	Menu::events()
{
  if (_window->isOpen())
    {
      if (_window->pollEvent(*_event))
	if (!hotKeys(_event->type))
	  {
	    if (_finish)
	      return (parseOptions());
	    return ("quit");
	  }
      return ("continue");
    }
  return ("quit");
}

void	Menu::show()
{
  _window->clear();
  showStatic();
  showWritten();
  _window->display();
}
