//
// AMenu.hpp for bomberman in /home/couder_a/Depot/cpp/git/cpp_bomberman
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Wed Jun 11 11:17:35 2014 Arthur Coudert
// Last update Sat Jun 14 11:34:13 2014 Arthur Coudert
//

#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Texture.hh>
#include <Geometry.hh>
#include <AShader.hh>
#include <Clock.hh>
#include "Input.hpp"

class AMenu{
public:
  AMenu();
  ~AMenu();
  virtual bool initialize() = 0;
  virtual int update(gdl::Clock, in::Input) = 0;
  virtual void draw(gdl::AShader &shader, gdl::Clock const &) = 0;
  void		translate(glm::vec3 const &v);
  void		scale(glm::vec3 const& scale);
  void		setTranslate(const int &posX, const int &posY);
  glm::mat4	getTransformation();
  int		getChose() const;
protected:
  glm::vec3	_position;
  glm::vec3	_rotation;
  glm::vec3	_scale;
  gdl::Texture	_bgT;
  gdl::Texture	_selecterT;
  gdl::Geometry	_bg;
  gdl::Geometry	_selecter;
  std::vector<int>	_posSelect;
  int		_select;
  bool		_sameKey;
};
