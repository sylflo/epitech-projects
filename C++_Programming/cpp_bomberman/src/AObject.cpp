//
// AObject.cpp for  in /home/chatea_s/project/c++/bomberman/LibBomberman_linux_x64
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Mon May  5 20:16:13 2014 Sylvain Chateau
// Last update Sun Jun 15 22:30:55 2014 maxime duboy
//

#include "AObject.hpp"

AObject::AObject():
_position(0, 0, 0),
_rotation(0, 0, 0),
_scale(1, 1, 1)
{
  _timeWait = 0;
  _crate = false;
}

AObject::~AObject()
{
}

void AObject::translate(glm::vec3 const &v)
{
  _position += v;
}

void AObject::rotate(glm::vec3 const& axis, const float &angle)
{
  _rotation += axis * angle;
}

void AObject::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}

glm::mat4 AObject::getTransformation()
{
  glm::mat4 transform(1);
  transform = glm::translate(transform, _position);
  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  transform = glm::scale(transform, _scale);
  return (transform);
}

void    AObject::setTranslate(const int &posX, const int &posZ)
{
  translate(glm::vec3(posX, 0, posZ));
}

int	AObject::getType() const
{
  return _type;
}

void	AObject::setPosX(const float &posX)
{
  _posX = posX;
}

void	AObject::setPosZ(const float &posZ)
{
  _posZ = posZ;
}

float	AObject::getPosX() const
{
  return (_posX);
}

float	AObject::getPosZ() const
{
  return (_posZ);
}

void	AObject::setPosCase(const int &pos_case)
{
  _pos_case = pos_case;
}

int	AObject::getPosCase() const
{
  return (_pos_case);
}

void	AObject::setTimeWait(double const _set)
{
  _timeWait = _set;
}

bool	AObject::isFadeOut()
{
  if (!_timeWait)
    return (false);
  return (true);
}

bool	AObject::did_it_explode(int const &_mode)
{
  if (!_mode)
    _timeWait = g_current_time;
  if (_mode == 1)
    {
      if (g_current_time - _timeWait >= 2.5)
	return (true);
    }
  else if (_mode == 2)
    {
      if (g_current_time - _timeWait >= 0.5)
	return (true);
    }
  return (false);
}

bool	AObject::wasItCrate(int const &_mode)
{
  if (!_mode)
    _crate = true;
  return (_crate);
}
