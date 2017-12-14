//
// ABomber.cpp for bomberman in /home/duboy_m/final/cpp_bomberman
//
// Made by maxime duboy
// Login   <duboy_m@epitech.net>
//
// Started on  Sun Jun 15 22:31:49 2014 maxime duboy
// Last update Sun Jun 15 22:31:50 2014 maxime duboy
//

#include	"ABomber.hpp"

ABomber::ABomber() : _alive(true)
{}

ABomber::~ABomber()
{}

bool	ABomber::getAlive() const
{
  return (_alive);
}

void	ABomber::setDead()
{
  _alive = false;
}

float	ABomber::getSpeed() const
{
  return (_speed);
}
