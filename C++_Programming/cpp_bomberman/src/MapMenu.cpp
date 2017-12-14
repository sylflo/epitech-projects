//
// MapMenu.cpp for bomberman in /home/couder_a/Depot/cpp/git/tmp/cpp_bomberman
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Sat Jun 14 11:46:04 2014 Arthur Coudert
// Last update Sun Jun 15 13:32:41 2014 Arthur Coudert
//

#include "MapMenu.hpp"

MapMenu::MapMenu() : AMenu()
{
  _select = 0;
  _sameKey = false;
  _player = 1;
  _width = 10;
  _height = 10;
  _numbers.resize(10);
}

MapMenu::~MapMenu()
{}

bool MapMenu::initialize()
{
  std::vector<gdl::Texture>::iterator it;
  int	i;
  std::string tmp;

  i = 0;
  if (!_bgT.load("./assets/texture/map_settings.tga"))
    {
      throw MyError("Error the texture fleche.tga is not present");
      return (false);
    }
  if (!_selecterT.load("./assets/texture/selecter.tga"))
    {
      throw MyError("Error the texture fleche.tga is not present");
      return (false);
    }
  for (it = _numbers.begin(); it != _numbers.end(); it++)
    {
      tmp = "./assets/texture/";
      tmp += (i + '0');
      tmp += ".tga";
      if (!(*it).load(tmp))
	{
	  throw MyError("Error the texture fleche.tga is not present");
	  return (false);
	}
      i++;
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

  _check.pushVertex(glm::vec3(372.f, 372.0f, 0.0f));
  _check.pushVertex(glm::vec3(412.0f, 372.0f, 0.0f));
  _check.pushVertex(glm::vec3(412.0f, 412.0f, 0.0f));
  _check.pushVertex(glm::vec3(372.0f, 412.0f, 0.0f));
  _check.pushUv(glm::vec2(0.0f, 1.0f));
  _check.pushUv(glm::vec2(1.0f, 1.0f));
  _check.pushUv(glm::vec2(1.0f, 0.0f));
  _check.pushUv(glm::vec2(0.0f, 0.0f));
  _check.build();

  _num.pushVertex(glm::vec3(0.0f, 0.0f, 0.0f));
  _num.pushVertex(glm::vec3(40.0f, 0.0f, 0.0f));
  _num.pushVertex(glm::vec3(40.0f, 40.0f, 0.0f));
  _num.pushVertex(glm::vec3(0.0f, 40.0f, 0.0f));
  _num.pushUv(glm::vec2(0.0f, 1.0f));
  _num.pushUv(glm::vec2(1.0f, 1.0f));
  _num.pushUv(glm::vec2(1.0f, 0.0f));
  _num.pushUv(glm::vec2(0.0f, 0.0f));
  _num.build();

  _posSelect.push_back(110);
  _posSelect.push_back(225);
  _posSelect.push_back(110);
  _posSelect.push_back(272);
  _posSelect.push_back(65);
  _posSelect.push_back(370);
  _posSelect.push_back(62);
  _posSelect.push_back(522);
  translate(glm::vec3(110, 225, 0));
  return (true);
}

int MapMenu::update(gdl::Clock clock, in::Input input)
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
  else if (input.getKey(SDL_SCANCODE_RIGHT))
    {
      if (_sameKey == false)
	{
	  _sameKey = true;
	  if ((_select / 2) == 1)
	    {
	      _height++;
	      if (_height < 0)
		_height = 10;
	    }
	  else if ((_select / 2) == 0)
	    {
	      _width++;
	      if (_width < 0)
		_width = 10;
	    }
	}
    }
  else if (input.getKey(SDL_SCANCODE_LEFT))
    {
      if (_sameKey == false)
	{
	  _sameKey = true;
	  if ((_select / 2) == 1)
	    {
	      _height--;
	      if (_height < 10)
		_height = 10;
	    }
	  else if ((_select / 2) == 0)
	    {
	      _width--;
	      if (_width < 10)
		_width = 10;
	    }
	}
    }
  else if (input.getKey(SDL_SCANCODE_RETURN))
    {
      if (_sameKey == false)
	{
	  _sameKey = true;
	  if ((_select / 2) == 3)
	    return (0);
	  else if ((_select / 2) == 2)
	    _player = (_player == 1 ? 2 : 1);
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
  else
    _sameKey = false;
  return (1);
}

void	MapMenu::drawNumber(int x, int y, gdl::AShader &shader, int nb)
{
  int	div;
  int	mod;
  glm::mat4 transform(1);

  div = nb / 10;
  mod = nb % 10;
  if (div == 0 && mod == 0)
    return;
  drawNumber(x - 40, y, shader, div);
  _numbers[mod].bind();
  transform = glm::translate(transform, glm::vec3(x, y, 0));
  transform = glm::rotate(transform, 0.0f, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, 0.0f, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, 0.0f, glm::vec3(1, 0, 1));
  transform = glm::scale(transform, glm::vec3(1,1,1));
  _num.draw(shader, transform, GL_QUADS);
}

void MapMenu::draw(gdl::AShader &shader, gdl::Clock const & clock)
{
  _bgT.bind();
  _bg.draw(shader, glm::mat4(1), GL_QUADS);
  _selecterT.bind();
  _selecter.draw(shader, getTransformation(), GL_QUADS);
  drawNumber(480, 225, shader, _width);
  drawNumber(480, 272, shader, _height);
  if (_player == 2)
    {
      _selecterT.bind();
      _check.draw(shader, glm::mat4(1), GL_QUADS);
    }
}

int	MapMenu::getNbPlayer() const
{
  return (_player);
}

int	MapMenu::getWidh() const
{
  return (_width);
}

int	MapMenu::getHeight() const
{
  return (_height);
}
