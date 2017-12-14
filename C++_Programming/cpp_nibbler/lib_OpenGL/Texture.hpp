//
// Texture.hpp for  in /home/chatea_s/cpp_nibbler
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Thu Apr  3 13:58:30 2014 Sylvain Chateau
// Last update Thu Apr  3 14:23:18 2014 Sylvain Chateau
//

#ifndef TEXTURE_H_
# define TEXTURE_H_

#include <iostream>
#include <GL/glu.h>

class Texture
{
public:
  Texture(const std::string &);
  bool		load();
  GLuint	getId() const;
  void		setImage(const std::string &);

private:
  GLuint	m_id;
  std::string	m_image;
};

#endif /* !TEXTURE_H_*/
