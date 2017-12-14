//
// Texture.hpp for Texture in /home/storm/IA/Gomoku/inc
//
// Made by caille_j
// Login   <caille_j@epitech.net>
//
// Started on  Mon Nov  3 11:19:09 2014
// Last update Mon Nov  3 11:19:10 2014 caille_j
//

#ifndef _TEXTURE_HPP_
# define _TEXTURE_HPP_

# include <SFML/Graphics.hpp>
# include <vector>
# include <iostream>
# include "Exception.hpp"

class	Texture
{
public:
  Texture();
  ~Texture();
  bool	newTexture(char const *, char const *, sf::IntRect const &);
  sf::Sprite *spriteLabel(char const *);
  sf::Texture *textureLabel(char const *);
private:
  std::vector<sf::Texture *>	_textures;
  std::vector<sf::Sprite *>	_sprites;
  std::vector<std::string>	_labels;
};

#endif /* !_TEXTURE_HPP_ */
