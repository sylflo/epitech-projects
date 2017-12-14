//
// Animate.cpp for zappy in /home/storm/zappy/zappy/src
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Fri Jun 20 19:38:09 2014 Julian Caille
// Last update Sun Jul 13 18:23:07 2014 Arthur Coudert
//

#include "Animate.hpp"
#include <unistd.h>

Frame::Frame(std::vector<sf::IntRect > *positions,
	     std::string const &label)
{
  _label = label;
  _positions = positions;
  _current = 0;
}

Frame::~Frame()
{
}

std::string	Frame::getLabel() const
{
  return (_label);
}

unsigned int	Frame::getCurrent() const
{
  return (_current);
}

std::vector<sf::IntRect > *Frame::getPositions() const
{
  return (_positions);
}

void			Frame::setCurrent(unsigned int const current)
{
  _current = current;
}
Animated::Animated()
{
  _frames = new std::vector<Frame *>;
}

Animated::~Animated()
{
}

void	Animated::setTimer(int const &timer)
{
  _elTimer = timer;
}

void	Animated::setSprite(sf::Sprite sprite, std::string const &name, int const &timer)
{
  _name = name;
  _sprite = new sf::Sprite();
  *_sprite = sprite;
  _elTimer = timer;
}

std::string	Animated::getAnimationName() const
{
  return (_name);
}

sf::Sprite *Animated::getSprite()
{
  return (_sprite);
}

void	Animated::addNewAnimation(std::string const &label,
				  std::vector<sf::IntRect > *frames)
{
  _frames->push_back(new Frame(frames, label));
}

int	Animated::playAnimation(std::string const &label, sf::Vector2f const &pos,
				sf::Time const &currentTime)
{
  unsigned int i;
  unsigned int current;

  if (_timer.asMilliseconds() == 0)
    {
      i = 0;
      while (i < _frames->size())
	{
	  if (_frames->at(i)->getLabel() == label)
	    break ;
	  i++;
	}
      if (i == _frames->size())
	{
	  throw MyError("Error : couldn\'t find animation in the list !");
	  return (-1);
	}
      current = _frames->at(i)->getCurrent();
      if (current == _frames->at(i)->getPositions()->size())
	{
	  current = 0;
	  _frames->at(i)->setCurrent(0);
	}
      _sprite->setTextureRect(_frames->at(i)->getPositions()->at(current));
      _sprite->setPosition(pos);
      _frames->at(i)->setCurrent(current + 1);
      _timer = currentTime;
      return (1);
    }
  else
    if (currentTime.asMilliseconds() - _timer.asMilliseconds() >= _elTimer)
      _timer = sf::milliseconds(0);
  return (0);
}
