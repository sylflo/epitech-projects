//
// HelpMenu.cpp<2> for bmberman in /home/couder_a/Depot/cpp/git/tmp/cpp_bomberman
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Sat Jun 14 16:29:31 2014 Arthur Coudert
// Last update Sat Jun 14 16:33:48 2014 Arthur Coudert
//

#ifndef HELPMENU_HPP
# define HELPMENU_HPP

# include "AMenu.hpp"
# include "MyError.hpp"

class HelpMenu: public AMenu {
public:
  HelpMenu();
  ~HelpMenu();
  bool initialize();
  int update(gdl::Clock, in::Input);
  void draw(gdl::AShader &shader, gdl::Clock const &);
};

#endif /* HELPMENU_HPP */
