//
// MainMenu.cpp<2> for bomberMan in /home/couder_a/Depot/cpp/git/cpp_bomberman
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Fri Jun 13 11:26:23 2014 Arthur Coudert
// Last update Sat Jun 14 13:34:34 2014 Arthur Coudert
//

#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "AMenu.hpp"
# include "MyError.hpp"

class MainMenu: public AMenu{
public:
  MainMenu();
  ~MainMenu();
  bool initialize();
  int update(gdl::Clock, in::Input);
  void draw(gdl::AShader &shader, gdl::Clock const &);
};

#endif /* MAINMENU_HPP */
