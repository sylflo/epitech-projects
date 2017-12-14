//
// MainMenu.cpp for bomberman in /home/couder_a/Depot/cpp/git/cpp_bomberman
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Fri Jun 13 11:34:06 2014 Arthur Coudert
// Last update Sun Jun 15 16:00:43 2014 Arthur Coudert
//

#include "MainMenu.hpp"

MainMenu::MainMenu() : AMenu()
{
  _select = 0;
  _sameKey = false;
}

MainMenu::~MainMenu()
{}

bool MainMenu::initialize()
{
  if (!_bgT.load("./assets/texture/background.tga"))
    {
      throw MyError("Error the texture fleche.tga is not present");
      return (false);
    }
  if (!_selecterT.load("./assets/texture/selecter.tga"))
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

  _selecter.pushVertex(glm::vec3(0.f, 0.0f, 0.0f));
  _selecter.pushVertex(glm::vec3(40.0f, 0.0f, 0.0f));
  _selecter.pushVertex(glm::vec3(40.0f, 40.0f, 0.0f));
  _selecter.pushVertex(glm::vec3(0.0f, 40.0f, 0.0f));
  _selecter.pushUv(glm::vec2(0.0f, 1.0f));
  _selecter.pushUv(glm::vec2(1.0f, 1.0f));
  _selecter.pushUv(glm::vec2(1.0f, 0.0f));
  _selecter.pushUv(glm::vec2(0.0f, 0.0f));
  _selecter.build();

  _posSelect.push_back(470);
  _posSelect.push_back(90);
  _posSelect.push_back(470);
  _posSelect.push_back(150);
  _posSelect.push_back(470);
  _posSelect.push_back(210);
  _posSelect.push_back(470);
  _posSelect.push_back(270);
  translate(glm::vec3(470, 90, 0));
  return (true);
}

int MainMenu::update(gdl::Clock clock, in::Input input)
{
  if (input.getKey(SDL_SCANCODE_UP))
    {
      if (_sameKey == false)
	{
	  _sameKey = true;
	  _select -= 2;
	  if (_select < 0)
	    _select = 6;
	  setTranslate(_posSelect[_select], _posSelect[_select + 1]);
	}
    }
  else if (input.getKey(SDL_SCANCODE_DOWN))
    {
      if (_sameKey == false)
	{
	  _sameKey = true;
	  _select += 2;
	  if (_select >= 8)
	    _select = 0;
	  setTranslate(_posSelect[_select], _posSelect[_select + 1]);
	}
    }
  else if (input.getKey(SDL_SCANCODE_RETURN))
    {
      if (_sameKey == false)
	{
	  _sameKey = true;
	  return (0);
	}
    }
  else
    _sameKey = false;
  return (1);
}

void MainMenu::draw(gdl::AShader &shader, gdl::Clock const & clock)
{
  _bgT.bind();
  _bg.draw(shader, glm::mat4(1), GL_QUADS);
  _selecterT.bind();
  _selecter.draw(shader, getTransformation(), GL_QUADS);
}
