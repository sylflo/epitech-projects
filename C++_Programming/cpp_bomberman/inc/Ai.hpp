
#ifndef AI_H_
# define AI_H_

# include <iostream>
# include <Geometry.hh>
# include "AObject.hpp"

class Ia : public ABomber
{
private:
  gdl::Texture _texture;
  gdl::Geometry _geometry;

public:
  Ia(const float &, const float &, const int &);
  virtual ~Ia();
  virtual void	load() {}

public:
  void	setPosX(const float &);
  void	setPosZ(const float &);
  float	getPosX() const;
  float	getPosZ() const;
  int	getType() const;
  int	getDir() const {};

public:
  virtual bool	initialize();
  virtual int	update(gdl::Clock const &clock, gdl::Input &input, int = 0);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock, gdl::Texture *);
};

#endif /* !AI_H_*/
