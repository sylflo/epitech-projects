//
// AMenu.cpp for bomberman in /home/couder_a/Depot/cpp/git/cpp_bomberman
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Wed Jun 11 11:17:43 2014 Arthur Coudert
// Last update Sat Jun 14 18:25:31 2014 Arthur Coudert
//

#include "AMenu.hpp"

AMenu::AMenu(): _position(0, 0, 0), _rotation(0, 0, 0), _scale(1, 1, 1)
{}

AMenu::~AMenu(){}

void		AMenu::translate(glm::vec3 const &v)
{
  _position += v;
}

void		AMenu::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}

void		AMenu::setTranslate(const int &posX, const int &posY)
{
  translate(glm::vec3(posX - _position.x, posY - _position.y, 0));
}

glm::mat4	AMenu::getTransformation()
{
  glm::mat4 transform(1);
  transform = glm::translate(transform, _position);
  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(1, 0, 1));
  transform = glm::scale(transform, _scale);
  return (transform);
}

int		AMenu::getChose() const
{
  return ((_select / 2) + 1);
}
