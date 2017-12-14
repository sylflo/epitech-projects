//
// Cube.hpp for  in /home/chatea_s/project/c++/bomberman/LibBomberman_linux_x64
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Mon May  5 20:33:01 2014 Sylvain Chateau
// Last update Sun Jun 15 21:54:42 2014 maxime duboy
//

#ifndef CUBE_H_
# define CUBE_H_

# include <iostream>
# include <Geometry.hh>
# include "AObject.hpp"

class Cube : public AObject
{
private:


public:
  Cube(const float &, const float &, int);
  virtual ~Cube();

public:
  virtual bool	initialize(){};
  virtual int	update(gdl::Clock const &clock, in::Input &, int &);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock,
		     gdl::Texture *, gdl::Geometry *);


public:
  void	setPosX(const float &);
  void	setPosZ(const float &);
  float	getPosX() const;
  float	getPosZ() const;
  int	getType() const;
  int	getDir() const {}
};

#endif /* !CUBE_H_*/
