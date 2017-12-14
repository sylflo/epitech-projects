//
// HelpMenu.cpp for bomberman in /home/couder_a/Depot/cpp/git/tmp/cpp_bomberman
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Sat Jun 14 16:29:37 2014 Arthur Coudert
// Last update Sat Jun 14 16:38:04 2014 Arthur Coudert
//
#include "HelpMenu.hpp"

HelpMenu::HelpMenu() : AMenu()
{
  _sameKey = false;
}

HelpMenu::~HelpMenu()
{}

bool HelpMenu::initialize()
{
  if (!_bgT.load("./assets/texture/help.tga"))
    {
      throw MyError("Error the texture fleche.tga is not present");
      return (false);
    }
  _bg.pushVertex(glm::vec3(0.f, 0.0f, 0.0f));
  _bg.pushVertex(glm::vec3(800.0f, 0.0f, 0.0f));
  _bg.pushVertex(glm::vec3(800.0f, 600.0f, 0.0f));
  _bg.pushVertex(glm::vec3(0.0f, 600.0f, 0.0f));
  _bg.pushUv(glm::vec2(0.0f, 1.0f));
  _bg.pushUv(glm::vec2(1.0f, 1.0f));
  _bg.pushUv(glm::vec2(1.0f, 0.0f));
  _bg.pushUv(glm::vec2(0.0f, 0.0f));
  _bg.build();
  return (true);
}

int	HelpMenu::update(gdl::Clock clock, in::Input input)
{
  if (input.getKey(SDL_SCANCODE_BACKSPACE))
    {
      if (_sameKey == false)
	{
	  _sameKey = true;
	  return (-1);
	}
    }
  else
    _sameKey = false;
  return 1;
}

void HelpMenu::draw(gdl::AShader &shader, gdl::Clock const & clock)
{
  _bgT.bind();
  _bg.draw(shader, glm::mat4(1), GL_QUADS);
}
