//
// Sfml.hpp for  in /home/chatea_s/cpp_nibbler
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Tue Apr  1 16:43:14 2014 Sylvain Chateau
// Last update Sat Apr  5 12:43:01 2014 Sylvain Chateau
//

#ifndef SFML_H
# define SFML_H

# include <stdlib.h>
# include <sstream>
# include <SFML/Graphics.hpp>
# include "../core/ILib.hpp"

# define CASE	        20
# define NUMBER_TEXTURE	7
# define SIZE_BG        256
# define BORDER_MAP	20

class			Sfml : public ILib
{
private:
  sf::Font		font;
  sf::Text		*text;
  sf::Texture		texture[NUMBER_TEXTURE];
  sf::Sprite		sprite[NUMBER_TEXTURE];
  sf::Texture	        textureHeadSnake;
  sf::Texture	        textureBodySnake;
  sf::Texture	        textureApple;
  sf::RenderWindow	*win;
  sf::Sprite		spriteHeadSnake;
  sf::Sprite		spriteBodySnake;
  sf::Sprite		spriteApple;
  bool			loadTexture();
  void			displayBackground();
  void			displayBorder();
  void			displayText(const int) const;
public:
  virtual bool		initWindow(const ILib::t_size size_win);
  virtual void		display(const std::vector<struct s_element> &list,
				const std::vector<struct s_element> &food, const int);
  virtual void		closeWindow() const;
  virtual ILib::key	getEvent() const;
};

#endif // SFML
