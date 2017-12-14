//
// Display.hpp for Display in /home/storm/IA/Gomoku/inc
//
// Made by caille_j
// Login   <caille_j@epitech.net>
//
// Started on  Mon Nov  3 11:39:59 2014
// Last update Sun Nov  9 17:30:28 2014 caille_j
//

#ifndef _DISPLAY_HPP_
# define _DISPLAY_HPP_

# include <string>
# include <SFML/Graphics.hpp>
# include "Texture.hpp"
# include "Sound.hpp"

class	Display
{
public:
  Display() {};
  virtual ~Display() {};
  virtual bool initialize() = 0;
protected:
  Texture		_textures;
  Sound			*_sound;
  sf::RenderWindow	*_window;
  sf::Event		*_event;
  sf::Font		_font;
  sf::Text		_text;
};

#endif /* !_DISPLAY_HPP_ */
