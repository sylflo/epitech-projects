//
// Painter.cpp for  in /home/chatea_s/cpp_nibbler
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Wed Apr  2 19:52:13 2014 Sylvain Chateau
// Last update Sat Apr  5 02:15:32 2014 Sylvain Chateau
//

#include <iostream>
#include <GL/glu.h>
#include "Painter.hpp"

void	Painter::bar(const int &x1, const int &y1, const int &x2, const int &y2,
		     const GLuint &id)
{
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, id);
  glBegin(GL_QUADS);
  glTexCoord2d(1,0);  glVertex2f(x1, y1);
  glTexCoord2d(0,0);  glVertex2f(x2, y1);
  glTexCoord2d(0,1);  glVertex2f(x2, y2);
  glTexCoord2d(1,1);  glVertex2f(x1, y2);
  glEnd();
  glDisable(GL_TEXTURE_2D);
}
