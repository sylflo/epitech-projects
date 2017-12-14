//
// Bomb.hpp for bombermna in /home/storm/bomberman/cpp_bomberman/inc
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Thu Jun  5 19:35:22 2014 Julian Caille
// Last update Sun Jun 15 21:53:22 2014 maxime duboy
//

#ifndef _BOMB_HPP_
# define _BOMB_HPP_

# include <iostream>
# include <Model.hh>
# include "AObject.hpp"
# include "Collision.hpp"
# include "WorldMap.hpp"
# include "Cube.hpp"

class	Bomb : public AObject
{
public:
  Bomb(const int &type = AObject::BOMB, const int = 0, const int = 0,
       const int = 0);
  ~Bomb();

  void		translateBomb(int const &_posX, int const &_posZ);
  int		getPosPlayer() const;
  virtual bool	initialize();
  virtual int	update(gdl::Clock const &clock, in::Input &input, int &) {}; //ERROR there is no update
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock,
		    gdl::Texture * = NULL, gdl::Geometry * = NULL);

  void	fireAlgorythm(int const &, int const &, int const &, int const &);




private:
  gdl::Model			_model;
   int				_pos;
  bool				_exploded;
  float				_scaleBomb;
  std::vector<AObject *>	*_map;
};

#endif /* !_BOMB_HPP_ */
