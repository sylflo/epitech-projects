//
// LoadMenu.hpp for Bomberman in /home/lousta_o/tmp/cpp_bomberman
//
// Made by Olivier Loustaunau
// Login   <lousta_o@epitech.net>
//
// Started on  Fri Jun 13 17:00:03 2014 Olivier Loustaunau
// Last update Sat Jun 14 16:48:23 2014 Olivier Loustaunau
//


#ifndef LOADMENU_HPP
#define LOADMENU_HPP

#include "AMenu.hpp"
# include "MyError.hpp"

enum	menuSelection
  {
    MAP1,
    MAP2,
    MAP3,
    MAP4,
    MAP5,
    LASTSAVE
  };

class LoadMenu: public AMenu {
public:
  LoadMenu();
  ~LoadMenu();
  bool initialize();
  int update(gdl::Clock, in::Input);
  void draw(gdl::AShader &shader, gdl::Clock const &);
};

#endif /* LOADMENU_HPP */
