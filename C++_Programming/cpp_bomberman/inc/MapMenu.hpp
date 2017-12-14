//
// MapMenu.hpp for bomberman in /home/couder_a/Depot/cpp/git/tmp/cpp_bomberman
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Sat Jun 14 11:46:17 2014 Arthur Coudert
// Last update Sat Jun 14 19:08:44 2014 Arthur Coudert
//

#ifndef MAPMENU_HPP
#define MAPMENU_HPP

#include "AMenu.hpp"
#include "MyError.hpp"

class MapMenu: public AMenu{
public:
  MapMenu();
  ~MapMenu();
  bool initialize();
  int update(gdl::Clock, in::Input);
  void draw(gdl::AShader &shader, gdl::Clock const &);
  void	drawNumber(int x, int y, gdl::AShader &shader, int nb);
  int	getNbPlayer() const;
  int	getWidh() const;
  int	getHeight() const;

private:
  int	_player;
  int	_width;
  int	_height;
  gdl::Texture	_checkT;
  std::vector<gdl::Texture>	_numbers;
  gdl::Geometry	_check;
  gdl::Geometry	_num;
};

#endif /* MAPMENU_HPP */
