//
// Item.cpp for zappy in /home/couder_a/Depot/PSU/git/zappy
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Wed Jun 25 11:05:41 2014 Arthur Coudert
// Last update Mon Jul  7 14:39:43 2014 Arthur Coudert
//

#include "Item.hh"
#include <iostream>

Item::Item(int nb, int type){
  _nbRes = nb;
  _type = type;
  _posRela = sf::Vector2i((rand() % (128 - 36)), (rand() % (128 - 36)));
}

Item::Item(const Item &copy){
  _nbRes = 1;
  _type = copy._type;
}

Item::~Item(){}

sf::Vector2i	Item::getPosRela() const{
  return (_posRela);
}

void		Item::setPosRela(int nb){
  _posRela = sf::Vector2i(nb,nb);
}

void		Item::setPosRela(sf::Vector2i posRela){
  _posRela = posRela;
}

void		Item::setPosRelaDest(sf::Vector2i posRela){
  _posRelaDest = posRela;
}


int			Item::getNbRes() const{
  return (_nbRes);
}

void			Item::setNbRes(int nbRes){
  _nbRes = nbRes;
}

int			Item::getType() const{
  return (_type);
}

bool			Item::move(){
  if (_posRela.x != _posRelaDest.x)
    {
      if (_posRela.x < _posRelaDest.x)
	_posRela.x++;
      else
	_posRela.x--;
    }
  if (_posRela.y != _posRelaDest.y)
    {
      if (_posRela.y < _posRelaDest.y)
	_posRela.y++;
      else
	_posRela.y--;
    }
  if (_posRela.x == _posRelaDest.x && _posRela.y == _posRelaDest.y)
    {
      _nbRes = 0;
      return (true);
    }
  return (false);
}
