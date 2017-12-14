//
// Texture.cpp for Texture in /home/storm/IA/Gomoku/src
//
// Made by caille_j
// Login   <caille_j@epitech.net>
//
// Started on  Mon Nov  3 11:19:31 2014
// Last update Wed Nov 12 14:40:11 2014 caille_j
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
      throw Exception("Couldn't load the texture !");
      return (false);
    }
  _sprites.back()->setTexture(*_textures.back());
  _labels.push_back(label);
  return (true);
}

sf::Texture *Texture::textureLabel(char const *label)
{
  unsigned int		i;

  i = -1;
  while (++i != _labels.size())
    {
      if (label == _labels[i])
	return (_textures[i]);
    }
  throw Exception("Fatal Error : couldn't find label : " + std::string(label));
  return (_textures[0]);
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
  throw Exception("Fatal Error : couldn't find label : " + std::string(label));
  return (_sprites[0]);
}
