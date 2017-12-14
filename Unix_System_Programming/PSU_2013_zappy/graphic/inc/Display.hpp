//
// Display.hpp for zappy in /home/storm/zappy/zappy
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Thu Jun 19 17:46:29 2014 Julian Caille
// Last update Tue Jun 24 03:20:36 2014 Julian Caille
//

#ifndef _DISPLAY_HPP_
# define _DISPLAY_HPP_

# include <SFML/Graphics.hpp>
# include "Sound.hpp"
# include "Texture.hpp"

class	Display
{
public:
  Display() {};
virtual  ~Display() {};
  virtual bool initialize() = 0;
  virtual std::string	events() = 0;
  virtual void show() = 0;
protected:
  sf::RenderWindow *_window;
  Sound		   _sound;
  sf::Event	   _event;
  sf::View	   *_view;
};

#endif /* !_DISPLAY_HPP_ */
