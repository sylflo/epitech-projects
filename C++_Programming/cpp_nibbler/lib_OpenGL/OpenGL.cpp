//
// OpenGL.cpp for  in /home/chatea_s/cpp_nibbler
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Wed Apr  2 18:21:52 2014 Sylvain Chateau
// Last update Sat Apr  5 13:53:45 2014 Sylvain Chateau
//

#include <GL/glu.h>
#include "OpenGL.hpp"
#include "Painter.hpp"
#include "Texture.hpp"

#include <iostream>

bool		OpenGL::initWindow(const ILib::t_size size_win)
{
  if ((m_win = new sf::RenderWindow(sf::VideoMode(size_win.width * CASE + (CASE * 4),
						  size_win.heigth * CASE + (CASE * 4), 32),
				    "Nibbler OpenGL")) == NULL)
    return (false);
  m_height = size_win.heigth;
  m_width = size_win.width;
  glClearColor(0, 0, 0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-CASE, size_win.width * CASE + (CASE * 2), size_win.heigth * CASE + (CASE * 2), -CASE, -1.0, 1.0);
  Texture	texture_head("lib_OpenGL/OpenGL/head.jpg");
  Texture	texture_body("lib_OpenGL/OpenGL/snake.jpg");
  Texture	texture_food("lib_OpenGL/OpenGL/apple.jpg");
  Texture	texture_background("lib_OpenGL/OpenGL/background.jpg");
  Texture	texture_rock("lib_OpenGL/OpenGL/rock.jpe");
  Texture	texture_wall("lib_OpenGL/OpenGL/brick_texture.jpg");
  if (!texture_background.load() || !texture_head.load()
      || !texture_body.load() || !texture_food.load() || !texture_rock.load()
      || !texture_wall.load())
    return (false);
  m_background = texture_background.getId();
  m_body = texture_body.getId();
  m_food = texture_food.getId();
  m_head = texture_head.getId();
  m_rock = texture_head.getId();
  m_wall = texture_wall.getId();
  return (true);
}

void		OpenGL::display(const std::vector<struct s_element> &disp,
				const std::vector<struct s_element> &disp_food, const int)
{
  int		index;
  Painter	p;

  index = -1;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  p.bar(0, 0, m_width * CASE + (CASE * 1), m_height * CASE + CASE, m_background);
  p.bar((m_width + 1) * CASE, 0, -CASE, -CASE, m_wall);
  p.bar((m_width + 2) * CASE, (m_height + 2) * CASE, -CASE, (m_height + 1) * CASE, m_wall);
  p.bar((m_width + 2) * CASE, -CASE, (m_width + 1) * CASE, (m_height + 2) * CASE, m_wall);
  p.bar(0, (m_height + 2) * CASE, -CASE, -CASE, m_wall);

  while (++index < (int)disp.size())
    {
      if (disp[index].type == ILib::SNAKE_HEAD)
	p.bar(disp[index].position.x * CASE,
		  disp[index].position.y * CASE,
		  (disp[index].position.x + 1) * CASE,
	      (disp[index].position.y + 1) * CASE, m_head);
      else
	p.bar(disp[index].position.x * CASE,
		  disp[index].position.y * CASE,
		  (disp[index].position.x + 1) * CASE,
	      (disp[index].position.y + 1) * CASE , m_body);
    }
  index = -1;
  while (++index < (int)disp_food.size())
    {
      if (disp_food[index].type == ILib::FOOD)
	p.bar(disp_food[index].position.x * CASE,
	      disp_food[index].position.y * CASE,
	      (disp_food[index].position.x + 1) * CASE - 1,
	      (disp_food[index].position.y + 1) * CASE - 1, m_food);
      else
	p.bar(disp_food[index].position.x * CASE,
	      disp_food[index].position.y * CASE,
	      (disp_food[index].position.x + 1) * CASE - 1,
	      (disp_food[index].position.y + 1) * CASE - 1, m_rock);
    }
  glFlush();
  m_win->display();
}

void	OpenGL::closeWindow() const
{
  m_win->close();
}

ILib::key	OpenGL::getEvent() const
{
 sf::Event		event;

  while (m_win->pollEvent(event))
    {
      if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	return (QUIT);
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	return (DOWN);
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	return (UP);
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	return (LEFT);
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	return (RIGTH);
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
	return (LIB1);
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
	return (LIB2);
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
	return (LIB3);
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	return (PAUSE);
      else if (event.type == sf::Event::Resized)
	glViewport(0, 0, event.size.width, event.size.height);
    }
  return (NONE);
}

extern "C"
{
  ILib	*create_lib()
  {
    return (new OpenGL());
  }
}
