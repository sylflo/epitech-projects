//
// Camera.cpp for  in /home/chatea_s/cpp_bomberman
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Fri May  9 14:22:53 2014 Sylvain Chateau
// Last update Wed Jun 11 23:26:36 2014 
//

#include "Camera.hpp"

#include <iostream>

Camera::Camera(const glm::vec3 &position, const glm::vec3 &target,
	       const glm::vec3 &verticalAxis, const int &width,
	       const int &height, const SDL_Scancode &left,
	       const SDL_Scancode &right,
	       const SDL_Scancode &up, const SDL_Scancode &down):
  _phi(-35.26), _theta(-135), _speed(10.0f), _orientation(), _verticalAxis(verticalAxis),
  _lateralMove(), _position(position), _target(target),
  _width(width), _height(height), _left(left), _right(right),
  _up(up), _down(down)
{
}

Camera::~Camera()
{
}

void	Camera::move(in::Input &input, const gdl::Clock &clockn, const float &new_time)
{

  if (input.getKey(_up) && input.getKey(_right) ||
      input.getKey(_up) && input.getKey(_left) ||
      input.getKey(_down) && input.getKey(_left) ||
      input.getKey(_down) && input.getKey(_right) ||
      input.getKey(_down) && input.getKey(_up) ||
      input.getKey(_right) && input.getKey(_left))
    return ;

  if (input.getKey(_up))
    {
      _position = _position + glm::vec3(0, 0, 1) * new_time;
      _target = _target + glm::vec3(0, 0, 1) * new_time;
    }
  if (input.getKey(_down))
    {
      _position = _position + glm::vec3(0, 0, -1) * new_time;
      _target = _target + glm::vec3(0, 0, -1) * new_time;
    }
  if (input.getKey(_left))
    {
      _position = _position + glm::vec3(1, 0, 0) * new_time;
      _target = _target + glm::vec3(1, 0, 0) * new_time;
    }
  if (input.getKey(_right))
    {
      _position = _position + glm::vec3(-1, 0, 0) * new_time;
      _target = _target + glm::vec3(-1, 0, 0) * new_time;
    }
}

void	Camera::lookAt(glm::mat4 &modelView)
{
  modelView = glm::lookAt(_position, _target, _verticalAxis);
}

std::list<int>	Camera::down(const int &posX, const int &posZ,
			     const int &pos_player)
{
  std::list<int> list_visual;
  int	case_player;
  int	new_posZ;
  int	new_posX;
  int	new_posX_second;
  int	i;
  int	nb_return_line = 0;

  new_posX_second = new_posX = posX;
  new_posZ = posZ;
  while (nb_return_line < 10 && new_posZ >= 0)
    {
      i = 0;
      while (new_posX >= 0 && i < 11)
	{
	  int new_new_posZ = new_posZ * _width;
	  case_player = new_new_posZ + new_posX;
	  if (pos_player != case_player)
	    list_visual.push_back(case_player);
	  i++;
	  new_posX--;
	}
      i = 0;
      while (new_posX_second < _width && i < 11)
	{
	  int new_new_posZ = new_posZ * _width;
	  case_player = new_new_posZ + new_posX_second;
	  if (pos_player != case_player)
	    list_visual.push_back(case_player);
	  new_posX_second++;
	  i++;
	  }
      new_posX_second = new_posX = posX;
      new_posZ--;
      nb_return_line++;
    }
  return (list_visual);
}

std::list<int>	Camera::up(const int &posX, const int &posZ,
			   const int &pos_player)
{
  std::list<int> list_visual_up;
  int	case_player;
  int	new_posZ;
  int	new_posX;
  int	new_posX_second;
  int	i;
  int	nb_return_line = 0;

  new_posX_second = new_posX = posX;
  new_posZ = posZ;
  nb_return_line = 0;
  while (nb_return_line < 10 && new_posZ < _height)
    {
      i = 0;

      while (new_posX >= 0 && i < 11)
	{
	  int new_new_posZ = new_posZ * _width;
	  case_player = new_new_posZ + new_posX;
	  if (pos_player != case_player)
	    list_visual_up.push_back(case_player);
	  i++;
	  new_posX--;
	}

      i = 0;
      while (new_posX_second < _width && i < 11)
	{
	  int new_new_posZ = new_posZ * _width;
	  case_player = new_new_posZ + new_posX_second;
	  if (pos_player != case_player)
	    list_visual_up.push_back(case_player);
	  i++;
	  new_posX_second++;
	}

      new_posX_second = new_posX = posX;
      new_posZ++;
      nb_return_line++;
    }
  return (list_visual_up);
}

std::list<int>	Camera::find_around(const int &posX, const int &posZ, const int &pos_player)
{
  std::list<int> list_visual;
  std::list<int> list_visual_up;


  list_visual = down(posX, posZ, pos_player);
  list_visual_up = up(posX, posZ, pos_player);
  list_visual.merge(list_visual_up);
  list_visual.push_back(pos_player);
  return (list_visual);
}
