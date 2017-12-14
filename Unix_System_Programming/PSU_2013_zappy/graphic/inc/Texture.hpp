//
// Texture.hpp for zappy in /home/storm/zappy/zappy
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Thu Jun 19 18:20:21 2014 Julian Caille
// Last update Sun Jul 13 18:27:54 2014 Arthur Coudert
//

#ifndef _TEXTURE_HPP_
# define _TEXTURE_HPP_

# include <SFML/Graphics.hpp>
# include <vector>
# include <iostream>
# include "MyError.hpp"

class	Texture
{
public:
  Texture();
  ~Texture();
  bool	newTexture(char const *, char const *, sf::IntRect const &);
  sf::Sprite *spriteLabel(char const *);
private:
  std::vector<sf::Texture *>	_textures;
  std::vector<sf::Sprite *>	_sprites;
  std::vector<std::string>	_labels;
};

#endif /* !_TEXTURE_HPP_ */
