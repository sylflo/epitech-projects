//
// Collision.hpp for  in /home/chatea_s/cpp_bomberman
//
// Made by
// Login   <chatea_s@epitech.net>
//
// Started on  Sat May 17 18:33:41 2014
// Last update Fri Jun 13 13:41:38 2014 
//

#ifndef COLLISION_H_
# define COLLISION_H_

# include <vector>
# include "AObject.hpp"

class Collision
{
public:
  Collision(const int &, const int &, std::vector<AObject *> *);
  ~Collision();

private:
  const int			_width;
  const int			_height;
  int				_pos_playerX;
  int				_pos_playerZ;
  std::vector<AObject *>	*_map;
  bool				_move;

public:
  bool	check_right(const float &, const float &, const int &, const int &);
  bool	check_left(const float &, const float &, const int &, const int &);
  bool	check_up(const float &, const float &, const int &, const int &);
  bool	check_down(const float &, const float &, const int &, const int &);
  int	find_case(const float &, const float &);
  void	setWorldMap(std::vector<AObject *>*);
};

#endif /* !COLLISION_H_*/
