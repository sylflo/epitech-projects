//
// MyInput.cpp for  in /home/chatea_s/cpp_bomberman
//
// Made by
// Login   <chatea_s@epitech.net>
//
// Started on  Sun May 18 15:13:49 2014
// Last update Fri Jun 13 15:45:44 2014 
//

#include "Input.hpp"

#include <iostream>

in::Input::Input():
  _x(0), _y(0), _xRel(0), _yRel(0), _quit(false)
{
  for (int i = 0; i < SDL_NUM_SCANCODES; i++)
    _keys[i] = false;

  for (int i = 0; i < 8; i++)
    _mouse[i] = false;
}

in::Input::~Input()
{

}

void	in::Input::updateEvents()
{
  _xRel = 0;
  _yRel = 0;
  while (SDL_PollEvent(&_events))
    {
      switch(_events.type)
	{
	case SDL_KEYDOWN:
	  _keys[_events.key.keysym.scancode] = true;
	  break;

	case SDL_KEYUP:
	  _keys[_events.key.keysym.scancode] = false;
	  break;

	case SDL_MOUSEBUTTONDOWN:
	  _mouse[_events.button.button] = true;
	  break;
	case SDL_MOUSEBUTTONUP:
	  _mouse[_events.button.button] = false;
	  break;

	case SDL_MOUSEMOTION:
	  _x = _events.motion.x;
	  _y = _events.motion.y;
	  _xRel = _events.motion.xrel;
	  _yRel = _events.motion.yrel;
	  break;

	case SDL_WINDOWEVENT:
	  if (_events.window.event == SDL_WINDOWEVENT_CLOSE)
	    _quit = true;
	  break;

	default:
	  break;
	}
    }
}

bool	in::Input::getKeyUp(const SDL_Scancode key) const
{
  if (_events.type == SDL_KEYUP)
    {
      if (_events.key.keysym.scancode == key)
	return (key);
    }
  return (false);
}

bool	in::Input::quit() const
{
  return (_quit);
}

bool	in::Input::getKey(const SDL_Scancode key) const
{
  return  (_keys[key]);
}

bool	in::Input::getMouseButton(const Uint8 button) const
{
  return (_mouse[button]);
}

bool	in::Input::mouseMove() const
{
  if (_xRel == 0 && _yRel == 0)
    return (false);
  return (true);
}

int	in::Input::getX() const
{
  return (_x);
}

int	in::Input::getY() const
{
  return (_y);
}

int	in::Input::getXRel() const
{
  return (_xRel);
}

int	in::Input::getYRel() const
{
  return (_yRel);
}

void	in::Input::printPointer(bool response) const
{
  if (response)
    SDL_ShowCursor(SDL_ENABLE);
  else
    SDL_ShowCursor(SDL_DISABLE);
}

void	in::Input::capturePointer(bool response) const
{
  if (response)
    SDL_SetRelativeMouseMode(SDL_TRUE);
  else
    SDL_SetRelativeMouseMode(SDL_FALSE);
}
