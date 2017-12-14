//
// BroadCast.hh for zappy in /home/couder_a/Depot/PSU/git/zappy
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Mon Jul  7 15:04:18 2014 Arthur Coudert
// Last update Thu Jul 10 16:47:14 2014 Arthur Coudert
//

#ifndef BROADCAST_HH
# define BROADCAST_HH

#include <vector>
#include <SFML/System.hpp>
#include "LivingEntity.hh"
#include "Line.hh"

class BroadCast{
public:
  BroadCast(int, int, int);
  ~BroadCast();

public:
  const std::vector<Line*>		&getLines() const;
  sf::Vector2i				getPos() const;
  int					getId() const;
  void					initDest(std::vector<LivingEntity*>, sf::Vector2u);
  bool					getFinish() const;
  void					UpdateLine(sf::Time);
private:
  std::vector<Line*>			_lines;
  sf::Vector2i				_pos;
  int					_id;
  sf::Time				_time;
  bool					_finish;
};

#endif /* !BROADCAST_HH */
