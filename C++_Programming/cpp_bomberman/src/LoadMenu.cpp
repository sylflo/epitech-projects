//
// LoadMenu.cpp for Bomberman in /home/lousta_o/tmp/cpp_bomberman
//
// Made by Olivier Loustaunau
// Login   <lousta_o@epitech.net>
//
// Started on  Fri Jun 13 16:59:53 2014 Olivier Loustaunau
// Last update Sat Jun 14 19:15:33 2014 Arthur Coudert
//

#include "LoadMenu.hpp"

LoadMenu::LoadMenu() : AMenu()
{
  _select = 0;
  _sameKey = false;
}

LoadMenu::~LoadMenu()
{}

bool LoadMenu::initialize()
{
  if (!_bgT.load("./assets/texture/load_menu.tga"))
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

  _posSelect.push_back(120);
  _posSelect.push_back(220);
  _posSelect.push_back(385);
  _posSelect.push_back(220);
  _posSelect.push_back(650);
  _posSelect.push_back(220);

  _posSelect.push_back(120);
  _posSelect.push_back(380);
  _posSelect.push_back(385);
  _posSelect.push_back(380);
  _posSelect.push_back(650);
  _posSelect.push_back(380);
  translate(glm::vec3(120, 220, 0));
  return (true);
}

int	LoadMenu::update(gdl::Clock clock, in::Input input)
{
  if (input.getKey(SDL_SCANCODE_UP))
    {
      if (_sameKey == false)
	{
	  _sameKey = true;
	  _select -= 2;
	  if (_select < 0)
	    _select = 10;
	  setTranslate(_posSelect[_select], _posSelect[_select + 1]);
	}
    }
  else if (input.getKey(SDL_SCANCODE_DOWN))
    {
      if (_sameKey == false)
	{
	  _sameKey = true;
	  _select += 2;
	  if (_select >= 12)
	    _select = 0;
	  setTranslate(_posSelect[_select], _posSelect[_select + 1]);
	}
    }
  else if (input.getKey(SDL_SCANCODE_BACKSPACE))
    {
      if (_sameKey == false)
	{
	  _sameKey = true;
	  return (-1);
	}
    }
  else if (input.getKey(SDL_SCANCODE_RETURN))
    {
      if (_sameKey == false)
	{
	  _sameKey = true;
	  return 0;
	}
    }
  else
    _sameKey = false;
  return 1;
}

void LoadMenu::draw(gdl::AShader &shader, gdl::Clock const & clock)
{
  _bgT.bind();
  _bg.draw(shader, glm::mat4(1), GL_QUADS);
  _selecterT.bind();
  _selecter.draw(shader, getTransformation(), GL_QUADS);
}
