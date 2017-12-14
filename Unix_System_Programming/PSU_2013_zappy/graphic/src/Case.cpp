//
// Case.cpp for zappy in /home/couder_a/Depot/PSU/git/zappy
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Wed Jun 25 10:56:52 2014 Arthur Coudert
// Last update Sun Jul 13 23:51:15 2014 Julian Caille
//

#include "Case.hh"
#include <iostream>

Case::Case(){
  _type = -1;
}

Case::Case(const Case &){
  _type = -1;
}

Case::~Case(){
  while (_res.size() != 0)
    {
      delete _res.back();
      _res.pop_back();
    }
}

Case	&Case::operator=(const Case&copy){
  _pos = copy._pos;
  _res = copy._res;
  _type = copy._type;
  return (*this);
}

void				Case::parseCommand(const std::vector<std::string> &command){
  for (int i = 0; i < 7; i++)
    _res[i]->setNbRes(atoi(command[i + 3].c_str()));
}

static int				algoBiom(sf::Vector2u pos, sf::Vector2u map)
{
  int		ret;

  if ((map.x / 3) > pos.x)
  {
    if ((map.y / 3) > pos.y)
      ret = GRASS;
    else if ((map.y - (map.y / 3)) <= pos.y)
      ret = DIRT;
    else
      {
	if ((rand() % 2) == 1)
	  ret = GRASS;
	else
	  ret = DIRT;
      }
  }
  else if ((map.x -(map.x / 3)) <= pos.x)
  {
    if ((map.y / 3) > pos.y)
      ret = SAND;
    else if ((map.y - (map.y / 3)) <= pos.y)
      ret = STONE;
    else
      {
	if ((rand() % 2) == 1)
	  ret = SAND;
	else
	  ret = STONE;
      }
  }
  else
    {
    if ((map.y / 3) > pos.y)
      {
	if ((rand() % 2) == 1)
	  ret = SAND;
	else
	  ret = GRASS;
      }
    else if ((map.y - (map.y / 3)) <= pos.y)
      {
	if ((rand() % 2) == 1)
	  ret = STONE;
	else
	  ret = DIRT;
      }
    else
      {
	int	nb = (rand() % 4);
	if (nb == 1)
	  ret = STONE;
	else if (nb == 3)
	  ret = GRASS;
	else if (nb == 2)
	  ret = SAND;
	else
	  ret = DIRT;
      }
    }
  return (ret);
}

void				Case::Init(const std::vector<std::string> &command, sf::Vector2u sizemap){
  _pos = sf::Vector2u(atoi(command[1].c_str()), atoi(command[2].c_str()));
  _type = algoBiom(_pos, sizemap);
  for (int i = 0; i < 7; i++)
    _res.push_back(new Item(atoi(command[i + 3].c_str()) , i));
}


sf::Vector2u			Case::getPos() const{
  return (_pos);
}
std::vector<Item*>		Case::getRes() const{
  return (_res);
}
int				Case::getType() const{
  return (_type);
}

void				Case::pushNewItem(sf::Vector2i posRela, int type, int action){
  for (int i = 0; i < 7; i++)
    {
      if (_res[i]->getType() == type)
	{
	  _res.push_back(new Item(*(_res[i])));
	  if (action == 1)
	    {
	      _res.back()->setPosRela(posRela);
	      _res.back()->setPosRelaDest(_res[i]->getPosRela());
	    }
	  else
	    {
	      _res.back()->setPosRelaDest(posRela);
	      _res.back()->setPosRela(_res[i]->getPosRela());
	    }
	  break;
	}
    }
}

void			Case::update()
{
  for (unsigned int i = 7; i < _res.size(); i++)
    {
      if (_res[i]->move() == true)
	{
	  delete _res[i];
	  _res.erase(_res.begin() + i);
	  i--;
	}
    }
}
