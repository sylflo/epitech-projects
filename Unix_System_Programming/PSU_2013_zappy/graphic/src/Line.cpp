//
// Line.cpp for zappy in /home/couder_a/Depot/PSU/git/zappy
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Mon Jul  7 16:08:16 2014 Arthur Coudert
// Last update Sun Jul 13 23:48:47 2014 Julian Caille
//

#include "Line.hh"
#include <iostream>

Line::Line(sf::Vector2i posFrom, sf::Vector2i posTo, sf::Vector2u mapSize){
  mapSize.x *= 128;
  mapSize.y *= 128;
  createLine(posFrom, posTo, mapSize);
}

Line::~Line(){
  while (_lines.size() != 0)
    _lines.pop_back();
}

void	Line::one_line(sf::Vector2i posFrom, sf::Vector2i posTo){
  sf::VertexArray line(sf::Lines, 2);

  line[0].position = sf::Vector2f(posFrom.x, posFrom.y);
  line[0].color = sf::Color::Red;
  line[1].position = sf::Vector2f(posTo.x, posTo.y);
  line[1].color = sf::Color::Red;
  _lines.push_back(line);
}

void	Line::two_line(sf::Vector2i posFrom, sf::Vector2i posTo, sf::Vector2u mapSize, int dx, int dy){
  sf::Vector2i p2;
  sf::Vector2f tmp;

  if (static_cast<unsigned int>(ABS(dx)) > mapSize.x /2)
    {
      p2.y = posTo.y;
      if (dx >= 0)
	{
	  p2.x = -(mapSize.x - posTo.x);
	  tmp.x = 0;
	  tmp.y = -((posFrom.y - p2.y)*((posFrom.x - tmp.x)/(posFrom.x - p2.x))) + posFrom.y;
	}
      else
	{
	  p2.x = mapSize.x + posTo.x;
	  tmp.x = mapSize.x;
	  tmp.y = -((posFrom.y - p2.y)*((posFrom.x - tmp.x)/(posFrom.x - p2.x))) + posFrom.y;
	}
    }
  else if (static_cast<unsigned int>(ABS(dy)) > mapSize.x /2)
    {
      p2.x = posTo.x;
      if (dy >= 0)
	{
	  p2.y = -(mapSize.y - posTo.y);
	  tmp.y = 0;
	  tmp.x = -((posFrom.x - p2.x)*((posFrom.y - tmp.y)/(posFrom.y - p2.y))) + posFrom.x;
	}
      else
	{
	  p2.y = mapSize.y + posTo.y;
	  tmp.y = mapSize.y;
	  tmp.x = -((posFrom.x - p2.x)*((posFrom.y - tmp.y)/(posFrom.y - p2.y))) + posFrom.x;
	}
    }
  else
    {
      if (dx >= 0)
	tmp.x = 0;
      else
	tmp.x = mapSize.x;
      if (dy >= 0)
	tmp.y = 0;
      else
	tmp.y = mapSize.y;
    }
  sf::VertexArray line(sf::Lines, 2);

  line[0].position = sf::Vector2f(posFrom.x, posFrom.y);
  line[0].color = sf::Color::Red;
  line[1].position = sf::Vector2f(tmp.x, tmp.y);
  line[1].color = sf::Color::Red;
  _lines.push_back(line);

  if (tmp.x == 0 || tmp.x == mapSize.x)
    tmp.x = (tmp.x == 0 ? mapSize.x : 0);
  if (tmp.y == 0 || tmp.y == mapSize.y)
    tmp.y = (tmp.y == 0 ? mapSize.y : 0);
  sf::VertexArray line2(sf::Lines, 2);
  line2[0].position = sf::Vector2f(tmp.x, tmp.y);
  line2[0].color = sf::Color::Red;
  line2[1].position = sf::Vector2f(posTo.x, posTo.y);
  line2[1].color = sf::Color::Red;
  _lines.push_back(line2);
}

static sf::Vector2f clacLine(sf::Vector2i posFrom, sf::Vector2i posTo, sf::Vector2u mapSize, int dx, int dy)
{
  sf::Vector2i p2;
  sf::Vector2f tmp;
  sf::Vector2f tmp2;
  sf::Vector2f abs;

  abs.x = ABS(dx);
  abs.y = ABS(dy);
  if (dx >= 0)
    {
      p2.x = -(mapSize.x - posTo.x);
      dx = p2.x - posFrom.x;
      abs.x = ABS(dx);
      if (dy >= 0)
	{
	  p2.y = -(mapSize.y - posTo.y);
	  dy = p2.y - posFrom.y;
	  abs.y = ABS(dy);
	  if ((abs.x / abs.y) > 1)
	    {
	      tmp.x = mapSize.x;
	      tmp.y = -((posFrom.y - p2.y)*((posFrom.x - tmp.x)/(posFrom.x - p2.x))) + posFrom.y;
	    }
	  else
	    {
	      tmp.y = mapSize.y;
	      tmp.x = -((posFrom.x - p2.x)*((posFrom.y - tmp.y)/(posFrom.y - p2.y))) + posFrom.x;
	    }
	}
      else
	{
	  p2.y = mapSize.y + posTo.y;
	  dy = p2.y - posFrom.y;
	  abs.y = ABS(dy);
	  if ((abs.x / abs.y) > 1)
	    {
	      tmp.x = 0;
	      tmp.y = -((posFrom.y - p2.y)*((posFrom.x - tmp.x)/(posFrom.x - p2.x))) + posFrom.y;
	    }
	  else
	    {
	      tmp.y = mapSize.y;
	      tmp.x = -((posFrom.x - p2.x)*((posFrom.y - tmp.y)/(posFrom.y - p2.y))) + posFrom.x;
	    }
	}
    }
  else
    {
      p2.x = mapSize.x + posTo.x;
      dx = p2.x - posFrom.x;
      abs.x = ABS(dx);
      if (dy >= 0)
	{
	  p2.y = -(mapSize.y - posTo.y);
	  dy = p2.y - posFrom.y;
	  abs.y = ABS(dy);
	  if ((abs.x / abs.y) > 1)
	    {
	      tmp.y = 0;
	      tmp.x = -((posFrom.x - p2.x)*((posFrom.y - tmp.y)/(posFrom.y - p2.y))) + posFrom.x;
	    }
	  else
	    {
	      tmp.x = mapSize.x;
	      tmp.y = -((posFrom.y - p2.y)*((posFrom.x - tmp.x)/(posFrom.x - p2.x))) + posFrom.y;
	    }
	}
      else
	{
	  p2.y = mapSize.y + posTo.y;
	  dy = p2.y - posFrom.y;
	  abs.y = ABS(dy);
	  if ((abs.x / abs.y) > 1)
	    {
	      tmp.y = 0;
	      tmp.x = -((posFrom.x - p2.x)*((posFrom.y - tmp.y)/(posFrom.y - p2.y))) + posFrom.x;
	    }
	  else
	    {
	      tmp.x = 0;
	      tmp.y = -((posFrom.y - p2.y)*((posFrom.x - tmp.x)/(posFrom.x - p2.x))) + posFrom.y;
	    }
	}
    }
  return (tmp);
}

void	Line::three_line(sf::Vector2i posFrom, sf::Vector2i posTo, sf::Vector2u mapSize, int dx, int dy){
  sf::Vector2f tmp;
  sf::Vector2f tmp2;

  tmp = clacLine(posFrom, posTo, mapSize, dx, dy);
  sf::VertexArray line(sf::Lines, 2);

  line[0].position = sf::Vector2f(posFrom.x, posFrom.y);
  line[0].color = sf::Color::Red;
  line[1].position = sf::Vector2f(tmp.x, tmp.y);
  line[1].color = sf::Color::Red;
  _lines.push_back(line);

  sf::Vector2i tmp3(tmp.x, tmp.y);
  if (tmp3.x == 0 || static_cast<unsigned int>(tmp3.x) == mapSize.x)
    tmp3.x = (tmp3.x == 0 ? mapSize.x : 0);
  if (tmp3.y == 0 || static_cast<unsigned int>(tmp3.y) == mapSize.y)
    tmp3.y = (tmp3.y == 0 ? mapSize.y : 0);
  dx = posTo.x - tmp3.x;
  dy = posTo.y - tmp3.y;
  two_line(tmp3, posTo, mapSize, dx, dy);
}

void	Line::createLine(sf::Vector2i posFrom, sf::Vector2i posTo, sf::Vector2u mapSize){
  int	dx;
  int	dy;
  float	adx;
  float	ady;

  dx = posTo.x - posFrom.x;
  dy = posTo.y - posFrom.y;
  adx = ABS(dx);
  ady = ABS(dy);
  if (adx <= (mapSize.x / 2) && ady <= (mapSize.y / 2))
    one_line(posFrom, posTo);
  else if (adx > (mapSize.x / 2) && ady > (mapSize.y / 2) && (ady/adx) != (mapSize.y/adx))
    three_line(posFrom, posTo, mapSize, dx, dy);
  else
    two_line(posFrom, posTo, mapSize, dx, dy);
}

const std::vector<sf::VertexArray>	&Line::getLines() const{
  return (_lines);
}
