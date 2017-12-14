//
// Collision.cpp for  in /home/chatea_s/cpp_bomberman
//
// Made by
// Login   <chatea_s@epitech.net>
//
// Started on  Sat May 17 22:15:52 2014
// Last update Fri Jun 13 16:49:52 2014 
//

#include "Collision.hpp"
#include "Player.hpp"

#include <iostream>

Collision::Collision(const int &width, const int &height,
		     std::vector<AObject *> *map):
  _width(width), _height(height), _map(map)
{
  _move = true;
}

Collision::~Collision()
{

}

int	Collision::find_case(const float &posX, const float &posZ)
{
  int	case_player;
  int	new_posZ;
  int	new_posX;

  case_player = static_cast<int>(posZ) * _width + static_cast<int>(posX);
  return (case_player);
}

bool	Collision::check_right(const float &posX, const float &posZ,
			       const int &pos_bomb, const int &pos_player)
{
  int	case_player;

  if (pos_bomb != -1)
    {
      if (pos_player == pos_bomb && (*_map)[pos_player - 1] &&
	  ((*_map)[pos_player - 1]->getType() == AObject::BLOCK ||
	   (*_map)[pos_player - 1]->getType() == AObject::UNBREAK ||
	   (*_map)[pos_player - 1]->getType() == AObject::BOMB))
	return (true);
      if (pos_player == pos_bomb)
	return (false);
    }
  case_player = find_case(posX, posZ);
  if ((*_map)[case_player] && ((*_map)[case_player]->getType() == AObject::BLOCK ||
			    (*_map)[case_player]->getType() == AObject::UNBREAK ||
			    (*_map)[case_player]->getType() == AObject::BOMB))
    return (true);
  return (false);
}

bool	Collision::check_left(const float &posX, const float &posZ,
			      const int &pos_bomb, const int &pos_player)
{
  int	case_player;

  if (pos_bomb != -1)
    {
      if (pos_player == pos_bomb && (*_map)[pos_player + 1])
	return (true);
      if (pos_player == pos_bomb)
	return (false);
    }
  case_player = find_case(posX, posZ);
  if ((*_map)[case_player] && ((*_map)[case_player]->getType() == AObject::BLOCK ||
			    (*_map)[case_player]->getType() == AObject::UNBREAK ||
			    (*_map)[case_player]->getType() == AObject::BOMB))
    return (true);
  return (false);
}

bool	Collision::check_up(const float &posX, const float &posZ,
			    const int &pos_bomb, const int &pos_player)
{
  int	case_player;

  if (pos_bomb != -1)
    {
      if (pos_player == pos_bomb && (*_map)[pos_player + _width] &&
	  ((*_map)[pos_player + _width]->getType() == AObject::BLOCK ||
	   (*_map)[pos_player + _width]->getType() == AObject::UNBREAK ||
	   (*_map)[pos_player + _width]->getType() == AObject::BOMB))
	return (true);
      if (pos_player == pos_bomb)
	return (false);
    }
  case_player = find_case(posX, posZ);
  if ((*_map)[case_player] && ((*_map)[case_player]->getType() == AObject::BLOCK ||
			    (*_map)[case_player]->getType() == AObject::UNBREAK ||
			    (*_map)[case_player]->getType() == AObject::BOMB))
    return (true);
  return (false);
}

bool	Collision::check_down(const float &posX, const float &posZ,
			      const int &pos_bomb, const int &pos_player)
{
  int	case_player;

  if (pos_bomb != -1)
    {
      if (pos_player == pos_bomb && (*_map)[pos_player - _width] &&
	  ((*_map)[pos_player - _width]->getType() == AObject::BLOCK ||
	   (*_map)[pos_player - _width]->getType() == AObject::UNBREAK ||
	   (*_map)[pos_player - _width]->getType() == AObject::BOMB))
	return (true);
      if (pos_player == pos_bomb)
	return (false);
    }
  case_player = find_case(posX, posZ);
  if ((*_map)[case_player] && ((*_map)[case_player]->getType() == AObject::BLOCK ||
			    (*_map)[case_player]->getType() == AObject::UNBREAK ||
			    (*_map)[case_player]->getType() == AObject::BOMB))
    return (true);
  return (false);
}

void	Collision::setWorldMap(std::vector<AObject *> *map)
{
  _map = map;
}
