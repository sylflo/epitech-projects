//
// Texture.cpp for zappy in /home/storm/zappy/zappy/src
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Thu Jun 19 18:18:39 2014 Julian Caille
// Last update Sun Jul 13 18:27:33 2014 Arthur Coudert
//

#include "Texture.hpp"

Texture::Texture()
{
}

Texture::~Texture()
{
}

bool	Texture::newTexture(char const *filename, char const *label,
			    sf::IntRect	const &rect)
{
  _textures.push_back(new sf::Texture);
  _sprites.push_back(new sf::Sprite);
  if (!_textures.back()->loadFromFile(filename, rect))
    {
      throw MyError("Couldn't load the texture !");
      return (false);
    }
  _sprites.back()->setTexture(*_textures.back());
  _labels.push_back(label);
  return (true);
}

sf::Sprite *Texture::spriteLabel(char const *label)
{
  unsigned int		i;

  i = -1;
  while (++i != _labels.size())
    {
      if (label == _labels[i])
	return (_sprites[i]);
    }
  throw MyError("Fatal Error : couldn't find label : " + std::string(label));
  return (_sprites[0]);
}
