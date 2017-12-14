//
// team.cpp for zappy in /home/couder_a/Depot/PSU/git/zappy
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Thu Jun 26 10:38:05 2014 Arthur Coudert
// Last update Mon Jul  7 20:22:53 2014 Arthur Coudert
//

#include "Team.hh"

Team::Team(const std::string name) : _name(name){
  _color = rand() % 13;
  _nb = 0;
}

Team::~Team(){}

const std::string		Team::getName() const{
  return (_name);
}

int				Team::getColor() const{
  return (_color);
}

int			Team::getNb() const{
  return (_nb);
}
void			Team::incNb(){
  _nb++;
}

void			Team::decNb(){
  if (_nb != 0)
    _nb--;
}
