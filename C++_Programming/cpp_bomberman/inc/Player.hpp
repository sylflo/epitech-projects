//
// Player.hpp for  in /home/chatea_s/project/c++/bomberman/LibBomberman_linux_x64
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Mon May  5 20:33:01 2014 Sylvain Chateau
// Last update Sun Jun 15 21:52:51 2014 maxime duboy
//

#ifndef PLAYER_H_
# define PLAYER_H_

# include <iostream>
# include <queue>
# include <Model.hh>
# include "ABomber.hpp"
# include "Collision.hpp"
# include "Cube.hpp"
# include "Bomb.hpp"

enum	PlayerDirection
  {
    Up,
    Down,
    Left,
    Right
  };

class Player : public ABomber
{
private:
  gdl::Model			_model;
  gdl::Model			_bombModel;
  int				_dir;
  bool				_stop;
  std::string			_marvin;
  Collision			*_collision;
  std::vector<AObject *>	*_map;
  std::deque<Bomb *>		_bombs;
  int				_mapWidth;
  int				_nbBombs;
  int				_Range;

public:

  Player(const float &posX, const float &posZ, const int &type,
	 const std::string &marvin, std::vector<AObject *> *map,
	 const SDL_Scancode &left, const SDL_Scancode &right,
	 const SDL_Scancode &up, const SDL_Scancode &down,
	 const SDL_Scancode &key_bomb, const int &mapWidth);


virtual ~Player();

public:
  void	setPosX(const float &);
  void	setPosZ(const float &);
  void	setPosCase(const int &);
  float	getPosX() const;
  float	getPosZ() const;
  int	getType() const;
  int	getDir() const;
  int	getPosCase() const;


public:
  virtual bool	initialize();
  virtual int	update(gdl::Clock const &clock, in::Input &input,
		       int &bomb);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock,
		     gdl::Texture * = NULL , gdl::Geometry * = NULL);

private:
  const SDL_Scancode	_left;
  const SDL_Scancode	_right;
  const SDL_Scancode	_up;
  const SDL_Scancode	_down;
  const SDL_Scancode	_key_bomb;
};

#endif /* !PLAYER_H_*/
