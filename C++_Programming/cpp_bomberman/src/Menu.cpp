//
// menu.cpp for bomberman in /home/storm/bomberman/cpp_bomberman/menu
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Mon May 26 19:07:31 2014 Julian Caille
// Last update Mon May 26 21:20:03 2014 Julian Caille
//

#include "Menu.hpp"

Menu::Menu() : _choice(0), _finish(0)
{
}

Menu::~Menu()
{
}

bool	Menu::initialize()
{
  if (!_context.start(1024, 768, "Menu"))
    return (false);
}

bool	Menu::events()
{
  _context.updateInputs(_input);
  if (_input.getInput(SDL_QUIT) || _input.getKey(SDLK_ESCAPE))
    _finish = 1;
}

int	Menu::getFinish() const
{
  return (_finish);
}

bool	Menu::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _context.flush();
}

int		main()
{
  Menu		menu;

  menu.initialize();
  while (!menu.getFinish())
    {
      menu.draw();
      menu.events();
    }
}
