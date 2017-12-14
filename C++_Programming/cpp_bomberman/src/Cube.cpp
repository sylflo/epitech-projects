//
// Cube.cpp for  in /home/chatea_s/project/c++/bomberman/LibBomberman_linux_x64
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Mon May  5 20:32:39 2014 Sylvain Chateau
// Last update Sun Jun 15 22:30:37 2014 maxime duboy
//

#include "Cube.hpp"

Cube::Cube(const float &posX, const float &posZ, int type)
{
  _posX = posX;
  _posZ = posZ;
  _sizeVertices = (108 * sizeof(float));
  _type = type;
   float vertices_tmp[] = {
    -0.5, -0.5, 0.5, 0.5, -0.5, 0.5, 0.5, -0.5, -0.5,
    -0.5, -0.5, 0.5, -0.5, -0.5, -0.5, 0.5, -0.5, -0.5,
    -0.5, -0.5, 0.5, 0.5, -0.5, 0.5, 0.5, 0.5, 0.5,
    -0.5, -0.5, 0.5, -0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
    -0.5, -0.5, -0.5, -0.5, -0.5, 0.5, -0.5, 0.5, 0.5,
    -0.5, -0.5, -0.5, -0.5, 0.5, -0.5, -0.5, 0.5, 0.5,
    -0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, -0.5,
    -0.5, 0.5, 0.5, -0.5, 0.5, -0.5, 0.5, 0.5, -0.5,
    -0.5, -0.5, -0.5, 0.5, -0.5, -0.5, 0.5, 0.5, -0.5,
    -0.5, -0.5, -0.5, -0.5, 0.5, -0.5, 0.5, 0.5, -0.5,
    0.5, -0.5, 0.5, 0.5, -0.5, -0.5, 0.5, 0.5, -0.5,
    0.5, -0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, -0.5
  };
  for (int i(0); i < 108; i++)
    _vertices[i] = vertices_tmp[i];
}

Cube::~Cube()
{
}

int	Cube::update(gdl::Clock const &clock, in::Input &input, int &unused)
{
  (void)clock;
  (void)input;
}

void	Cube::draw(gdl::AShader &shader, gdl::Clock const &clock,
		   gdl::Texture *texture, gdl::Geometry *geometry)
{
  (void)clock;
  texture->bind();
  geometry->draw(shader, getTransformation(), GL_TRIANGLES);
}
