//
// BroadCast.cpp for zappy in /home/couder_a/Depot/PSU/git/zappy
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Mon Jul  7 15:04:50 2014 Arthur Coudert
// Last update Thu Jul 10 19:47:29 2014 Arthur Coudert
//

#include "BroadCast.hh"

BroadCast::BroadCast(int x, int y, int id){
  _pos = sf::Vector2i(x, y);
  _id = id;
  _finish = false;
  _time = sf::Time::Zero;
}

BroadCast::~BroadCast(){
  while (_lines.size() != 0)
    {
      delete _lines.back();
      _lines.pop_back();
    }
}

bool	BroadCast::getFinish()const{
  return (_finish);
}

void	BroadCast::UpdateLine(sf::Time time){
  if (_time == sf::Time::Zero)
    _time = time;
  if ((time.asSeconds() - _time.asSeconds()) >= 3)
    _finish = true;
}

const std::vector<Line*>		&BroadCast::getLines() const{
  return (_lines);
}

sf::Vector2i				BroadCast::getPos() const{
  return (_pos);
}

int					BroadCast::getId() const{
  return (_id);
}

void					BroadCast::initDest(std::vector<LivingEntity*> entity, sf::Vector2u mapSize){
  for (unsigned int i = 0; i < entity.size(); i++)
    {
      if (entity[i]->getType() == AI && _id != entity[i]->getId())
	{
	  _lines.push_back(new Line(_pos
				    ,sf::Vector2i(entity[i]->getPos().x * 128 + entity[i]->getPosRela().x
						  ,entity[i]->getPos().y * 128 + entity[i]->getPosRela().y)
				    , mapSize));
	}
    }
}
