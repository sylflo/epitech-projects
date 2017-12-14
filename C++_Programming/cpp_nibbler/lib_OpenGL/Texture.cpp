//
// Texture.cpp for  in /home/chatea_s/cpp_nibbler
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Thu Apr  3 13:58:16 2014 Sylvain Chateau
// Last update Thu Apr  3 15:45:39 2014 Sylvain Chateau
//

#include "Texture.hpp"
#include <SFML/Graphics.hpp>

Texture::Texture(const std::string &image)
  :m_id(0), m_image(image)
{

}
GLuint	Texture::getId() const
{
  return (m_id);
}

bool		Texture::load()
{
  sf::Image	image;

  if (!image.loadFromFile(m_image.c_str()))
    {
      std::cerr << "Error when loading image" << std::endl;
      return (false);
    }
  glGenTextures(1, &m_id);
  glBindTexture(GL_TEXTURE_2D, m_id);
  gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, image.getSize().x,
		    image.getSize().y, GL_RGBA, GL_UNSIGNED_BYTE,
		    image.getPixelsPtr());
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		  GL_LINEAR_MIPMAP_LINEAR);
  return (true);
}

void	Texture::setImage(const std::string &image)
{
  m_image = image;
}
