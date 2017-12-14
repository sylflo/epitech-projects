//
// Menu.hpp for bomberman in /home/storm/bomberman/cpp_bomberman/menu
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Mon May 26 19:24:13 2014 Julian Caille
// Last update Mon May 26 21:19:08 2014 Julian Caille
//

#ifndef _MENU_HPP_
# define _MENU_HPP_
/*
# include <Game.hh>
# include <SdlContext.hh>
# include <glm/glm.hpp>
*/

# include "../GameEngine.hpp"

class Menu
{
public:
  Menu();
  ~Menu();
  bool	initialize();
  bool	events();
  bool	draw();
  int	getFinish() const;
private:
  gdl::SdlContext _context;
  gdl::Input _input;
  int _choice;
  int _finish;
};

#endif /* !_MENU_HPP_ */
