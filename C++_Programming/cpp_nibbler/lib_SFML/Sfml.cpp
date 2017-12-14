//
// Sfml.cpp for  in /home/chatea_s/cpp_nibbler
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Tue Apr  1 16:43:44 2014 Sylvain Chateau
// Last update Sat Apr  5 13:29:41 2014 Sylvain Chateau
//

#include "Sfml.hpp"

bool			Sfml::loadTexture()
{
  int			index_texture;
  const char		*tab_texture[NUMBER_TEXTURE] =
    {(char *)"lib_SFML/sfml_ressource/head.png",
     (char *)"lib_SFML/sfml_ressource/tail.png",
     (char *)"lib_SFML/sfml_ressource/apple.png",
     (char *)"lib_SFML/sfml_ressource/bg.png",
     (char *)"lib_SFML/sfml_ressource/box.png",
     (char *)"lib_SFML/sfml_ressource/grass.png",
     (char *)"lib_SFML/sfml_ressource/rock.png"};

  index_texture = 0;
  while (index_texture < NUMBER_TEXTURE)
    {
      if (!this->texture[index_texture].loadFromFile(tab_texture[index_texture]))
	return (false);
      this->texture[index_texture].setSmooth(true);
      this->sprite[index_texture].setTexture(this->texture[index_texture]);
      index_texture++;
    }
  return (true);
}

void			Sfml::displayBorder()
{
  int			index_x;
  int			index_y;

  index_x = 0;
  while (index_x < (int)this->win->getSize().x)
    {
      this->sprite[4].setPosition(sf::Vector2f(index_x, 0));
      this->win->draw(this->sprite[4]);
      index_x += CASE;
    }
  index_y = CASE;
  while (index_y < (int)this->win->getSize().y)
    {
      this->sprite[4].setPosition(sf::Vector2f(0, index_y));
      this->win->draw(this->sprite[4]);
      this->sprite[4].setPosition(sf::Vector2f((int)this->win->getSize().x - CASE, index_y));
      this->win->draw(this->sprite[4]);
      index_y += CASE;
    }
  index_x = 0;
  while (index_x < (int)this->win->getSize().x)
    {
      this->sprite[4].setPosition(sf::Vector2f(index_x, (int)this->win->getSize().y - CASE));
      this->win->draw(this->sprite[4]);
      index_x += CASE;
    }
}

void			Sfml::displayText(const int counter) const
{
  std::stringstream	str;

  str << counter;
  this->text->setString(str.str());
  this->win->draw(*this->text);
}

void			Sfml::displayBackground()
{
  int			index_y;
  int			index_x;
  int			number_grass = rand() % 2 + 2;

  this->win->clear();
  index_y = 0;
  while (index_y < (int)this->win->getSize().y)
    {
      index_x = 0;
      while (index_x < (int)this->win->getSize().x)
	{
      	  this->sprite[3].setPosition(sf::Vector2f(index_x,
	  					   index_y));
      	  this->win->draw(this->sprite[3]);
	  index_x += SIZE_BG;
	}
      index_y += SIZE_BG;
    }
  this->displayBorder();
  return ;
  while (number_grass-- >= 0)
    {
      this->sprite[5].setPosition(sf::Vector2f(rand() % (int)this->win->getSize().x,
					       rand() % (int)this->win->getSize().y));
      this->win->draw(this->sprite[5]);
    }
}

bool			Sfml::initWindow(const ILib::t_size size_win)
{
  if ((this->win = new sf::RenderWindow(sf::VideoMode(size_win.width * CASE + (CASE * 4),
						      size_win.heigth * CASE + (CASE * 4), 32),
					"Nibbler")) == NULL ||
      this->loadTexture() == false ||
      this->font.loadFromFile("lib_SFML/sfml_ressource/SpaceOutOpen.ttf") == false)
    return (false);
  if ((this->text = new sf::Text("69", this->font)) == NULL)
    return (false);
  this->text->setPosition((int)this->win->getSize().x - CASE * 4, CASE);
  return (true);
}

void			Sfml::display(const std::vector<struct s_element> &disp,
				      const std::vector<struct s_element> &disp_food,
				      const int counter)
{
  int			index;
  sf::RectangleShape	rect;

  index = 0;
  this->displayBackground();
  this->displayText(counter);
  while (index < (int)disp.size())
    {
      if (disp[index].type == ILib::SNAKE_HEAD)
      	{
      	  this->sprite[0].setPosition(sf::Vector2f(disp[index].position.x * CASE + (CASE),
	  					   disp[index].position.y * CASE + (CASE)));
      	  this->win->draw(this->sprite[0]);
      	}
      else
      	{
      	  this->sprite[1].setPosition(sf::Vector2f(disp[index].position.x * CASE + (CASE),
						   disp[index].position.y * CASE + (CASE)));
      	  this->win->draw(this->sprite[1]);
      	}
      index++;
    }
  index = 0;
  while (index < (int)disp_food.size())
    {
      if (disp_food[index].type == ILib::FOOD)
	{
	  this->sprite[2].setPosition(sf::Vector2f(disp_food[index].position.x * CASE + (CASE),
						   disp_food[index].position.y * CASE + (CASE)));
	  this->win->draw(this->sprite[2]);
	}
      else
	{
	  this->sprite[6].setPosition(sf::Vector2f(disp_food[index].position.x * CASE + (CASE),
						   disp_food[index].position.y * CASE + (CASE)));
	  this->win->draw(this->sprite[6]);
	}
      index++;
    }
  this->win->display();
}

void			Sfml::closeWindow() const
{
  this->win->close();
}

ILib::key		Sfml::getEvent() const
{
  sf::Event		event;

  while (this->win->pollEvent(event))
    {
      if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	return (QUIT);
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	return (PAUSE);
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
    }
  return (NONE);
}

extern "C"
{
  ILib	*create_lib()
  {
    return (new Sfml());
  }
}
