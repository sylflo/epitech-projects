//
// CountItems.cpp for zappy in /home/storm/zappy/zappy/src
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Sun Jun 29 20:20:34 2014 Julian Caille
// Last update Sat Jul  5 20:53:57 2014 Arthur Coudert
//

#include "Game.hpp"
#include <boost/lexical_cast.hpp>

void	Game::CountInventory(std::vector<Item*>  const &_case)
{
  _text.setPosition(_cameraX + 625, _cameraY + 510);
  _text.setString(boost::lexical_cast<std::string>(_case.at(0)->getNbRes()));
  _window->draw(_text);
  _text.setPosition(_cameraX + 675, _cameraY + 510);
  _text.setString(boost::lexical_cast<std::string>(_case.at(1)->getNbRes()));
  _window->draw(_text);
  _text.setPosition(_cameraX + 725, _cameraY + 510);
  _text.setString(boost::lexical_cast<std::string>(_case.at(2)->getNbRes()));
  _window->draw(_text);
  _text.setPosition(_cameraX + 775, _cameraY + 510);
  _text.setString(boost::lexical_cast<std::string>(_case.at(3)->getNbRes()));
  _window->draw(_text);
  _text.setPosition(_cameraX + 825, _cameraY + 510);
  _text.setString(boost::lexical_cast<std::string>(_case.at(4)->getNbRes()));
  _window->draw(_text);
  _text.setPosition(_cameraX + 875, _cameraY + 510);
  _text.setString(boost::lexical_cast<std::string>(_case.at(5)->getNbRes()));
  _window->draw(_text);
  _text.setPosition(_cameraX + 925, _cameraY + 510);
  _text.setString(boost::lexical_cast<std::string>(_case.at(6)->getNbRes()));
  _window->draw(_text);
}


void	Game::CountItems(std::vector<Item*>  const &_case)
{
  _text.setPosition(_cameraX + 150, _cameraY + 680);
  _text.setString(boost::lexical_cast<std::string>(_case.at(0)->getNbRes()));
  _window->draw(_text);
  _text.setPosition(_cameraX + 200, _cameraY + 680);
  _text.setString(boost::lexical_cast<std::string>(_case.at(1)->getNbRes()));
  _window->draw(_text);
  _text.setPosition(_cameraX + 250, _cameraY + 680);
  _text.setString(boost::lexical_cast<std::string>(_case.at(2)->getNbRes()));
  _window->draw(_text);
  _text.setPosition(_cameraX + 300, _cameraY + 680);
  _text.setString(boost::lexical_cast<std::string>(_case.at(3)->getNbRes()));
  _window->draw(_text);
  _text.setPosition(_cameraX + 350, _cameraY + 680);
  _text.setString(boost::lexical_cast<std::string>(_case.at(4)->getNbRes()));
  _window->draw(_text);
  _text.setPosition(_cameraX + 400, _cameraY + 680);
  _text.setString(boost::lexical_cast<std::string>(_case.at(5)->getNbRes()));
  _window->draw(_text);
  _text.setPosition(_cameraX + 450, _cameraY + 680);
  _text.setString(boost::lexical_cast<std::string>(_case.at(6)->getNbRes()));
  _window->draw(_text);
}
