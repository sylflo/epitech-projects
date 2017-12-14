//
// Line.hh for zappy in /home/couder_a/Depot/PSU/git/zappy
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Mon Jul  7 16:08:11 2014 Arthur Coudert
// Last update Sun Jul 13 23:57:33 2014 Julian Caille
//

#ifndef LINE_HH
# define LINE_HH

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#define ABS(x) ((x) < 0 ? (-(x)) : (x))

class Line{
public:
  Line(sf::Vector2i, sf::Vector2i, sf::Vector2u);
  ~Line();

public:
  const std::vector<sf::VertexArray>	&getLines() const;
  void	one_line(sf::Vector2i, sf::Vector2i);
  void	two_line(sf::Vector2i, sf::Vector2i, sf::Vector2u, int, int);
  void	three_line(sf::Vector2i, sf::Vector2i, sf::Vector2u, int, int);
  void	createLine(sf::Vector2i, sf::Vector2i, sf::Vector2u);
private:
  std::vector<sf::VertexArray>	_lines;

};

#endif /* !LINE_HH */
