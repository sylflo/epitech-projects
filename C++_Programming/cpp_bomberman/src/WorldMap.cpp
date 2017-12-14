//
// WorldMap.cpp for  in /home/chatea_s/project/c++/bomberman
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Fri May  2 19:20:27 2014 Sylvain Chateau
// Last update Thu Jun 12 16:44:23 2014 
//

#include <cstring>
#include <cstdlib>
#include "WorldMap.hpp"
#include "Cube.hpp"
#include "Player.hpp"
#include "Ai.hpp"
#include "MyError.hpp"

#include <iostream>
#include <stdio.h>

WorldMap*	WorldMap::_singleton = NULL;

void	WorldMap::init(const int width, const int height, const int players, const int nbAI)
{
  _singleton = new WorldMap(width, height, players, nbAI);
}

WorldMap*	WorldMap::get()
{
  return (_singleton);
}

void	 WorldMap::destroy()
{
  delete _singleton;
  _singleton = NULL;
}

WorldMap::WorldMap(const int width, const int height, const int players, const int nbAI):
  _width(width), _height(height), _nbPlayers(players), _nbAI(nbAI),
  _nbWalls((_height * _width) / 4)

{
  _map.resize(_height * _width);
  _sizeVertices = (108 * sizeof(float));

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

bool	WorldMap::check_nbPlayers() const
{
  if (_nbPlayers + _nbAI > 10)
    {
      throw MyError("Error there are too many players, the maximum is 10");
      return (false);
    }
  if (_nbPlayers + _nbAI < 2)
    {
      throw MyError("Error You need to have at least 2 players");
      return (false);
    }
  return (true);
}

WorldMap::~WorldMap()
{
  if (_map.size() > 0)
    {
      for (unsigned int i = 0; i < _map.size(); i++)
	{
	  if (_map.at(i) != 0)
	    delete _map.at(i);
	}
    }
}

void	WorldMap::find_pos(const int pos, int *posX, int *posZ) const
{
  int	i, j, count_pos;

  count_pos = 0;
  i = -1;
  while (++i < _height)
    {
      j = -1;
      while (++j < _width)
	{
	  if (pos == count_pos)
	    {
	      *posX =  j;
	      *posZ =  i;
	      *posX = (_width - 1) - j;
	      *posZ = (_height - 1) - i;
	    }
	  count_pos++;
	}
    }

}

void	WorldMap::dumpWorldMap() const
{
  static int return_line = _width;
  for (unsigned int i = _map.size() - 1; i > 0; i--)
    {
      std::cout << i << ": ";
      if (_map[i] == 0)
	std::cout << "0" << "\t";
      else if (_map[i]->getType() == AObject::BLOCK)
	std::cout << "B" << "\t";
      else if (_map[i]->getType() == AObject::UNBREAK)
	std::cout << "U" << "\t";
      else if (_map[i]->getType() == AObject::BOMB)
	std::cout << "BOMBA" << "\t";
      else if (_map[i]->getType() == AObject::PLAYER_ONE)
	std::cout << "\E[31;1mP\E[m" << "\t";
      else if (_map[i]->getType() == AObject::PLAYER_TWO)
	std::cout << "\E[31;1mP\E[m" << "\t";
      else if (_map[i]->getType() == AObject::AI)
	std::cout << "\E[31;1mI\E[m" << "\t";
      if (i % _width == 0)
	std::cout << std::endl;
    }
}

static int			checkIllegalPos(int x, int y, int height, int width)
{
  if ((x == 1 && (y == 1 || y == 2)) || (x == 2 && y == 1))
    return (1);
  if ((x == 1 && (y == height - 2 || y == height - 3)) || (x == 2 && y == height - 2))
    return (1);
  if ((x == width - 2 && (y == 1 || y == 2)) || (x == width - 3 && y == 1))
    return (1);
  if ((x == width - 2 && (y == height - 2 || y == height - 3)) || (x == width - 3 && y == height - 2))
    return (1);
  return (0);
}

static bool			createWall(WorldMap *obj_map,
					   gdl::Geometry *geometry)
{
  int				x, y;
  int				modx, mody;
  int				width;
  int				height;
  int				pos, posX, posZ, type;
  std::vector<AObject *>	*map = obj_map->getWorldMap();
  std::list<int>		list_pos_cube;

  y = 0;
  mody = 0;
  width = obj_map->getWidth();
  height = obj_map->getHeight();

  while (y < height)
    {
      modx = 0;
      x = 0;
      while (x < width)
	{
	  if (x == 0 || y == 0 || x == width - 1 || y == height - 1)
	    {
	      AObject *cube = new Cube((float)x, (float)y, AObject::UNBREAK);
	      list_pos_cube.push_back(x);
	      list_pos_cube.push_back(y * width);
	      cube->translate(glm::vec3(cube->getPosX(), 0, cube->getPosZ()));
	      map->at((y * width) + x) = cube;
	    }
	  else if ((x % 2 == modx && y % 2 == mody))
	    {
	      AObject *cube = new Cube((float)x, (float)y, AObject::UNBREAK);
	      list_pos_cube.push_back(x);
	      list_pos_cube.push_back(y * width);
	      cube->translate(glm::vec3(cube->getPosX(), 0, cube->getPosZ()));
	      map->at((y * width) + x) = cube;
	    }
	  else if (checkIllegalPos(x, y, height, width) == 0)
	    {
	      if ((rand() % 100) < 75)
	      	{
		  AObject *cube = new Cube((float)x, (float)y, AObject::BLOCK);
		  list_pos_cube.push_back(x);
		  list_pos_cube.push_back(y * width);
		  cube->translate(glm::vec3(cube->getPosX(), 0, cube->getPosZ()));
		  map->at((y * width) + x) = cube;
		}
	    }
	  x++;
	  if (x > ((width - 1) / 2) && width % 2 == 0)
	    modx = 1;
	}
      y++;
      if (y > ((height - 1) / 2) && height % 2 == 0)
	mody = 1;
    }
  obj_map->setListPosCube(list_pos_cube);
  return (true);
}

bool	WorldMap::initialize(gdl::Geometry *geometry)
{
  int	tex;

  tex = 0;
  for (unsigned int i = 0; i < 100; i += 9)
    {
      geometry->pushVertex(glm::vec3(_vertices[i], _vertices[i + 1], _vertices[i + 2]));
      geometry->pushVertex(glm::vec3(_vertices[i + 3], _vertices[i + 4], _vertices[i + 5]));
      geometry->pushVertex(glm::vec3(_vertices[i + 6], _vertices[i + 7], _vertices[i + 8]));
      geometry->pushUv(glm::vec2(1.0f, 0.0f));
      if (tex == 0)
	geometry->pushUv(glm::vec2(1.0f, 1.0f));
      else
	geometry->pushUv(glm::vec2(0.0f, 0.0f));
      tex = (tex == 0 ? 1 : 0);
      geometry->pushUv(glm::vec2(0.0f, 1.0f));
    }
  if (!geometry->build())
    {
      throw MyError("Error when building the cub with build()");
      return (false);
    }
  return (true);
}

bool	WorldMap::createWorldMap(gdl::Geometry *geometry)
{
  if (!createWall(this, geometry))
    {
      throw MyError("Error when building the map");
      return (false);
    }
  return (true);
}

void	WorldMap::setPosFirstPlayer(const int pos)
{
  _posFirstPlayer = pos;
}

void	WorldMap::setPosSecondPlayer(const int pos)
{
  _posSecondPlayer = pos;
}

int	WorldMap::getPosFirstPlayer() const
{
  return (_posFirstPlayer);
}

int	WorldMap::getPosSecondPlayer() const
{
  return (_posFirstPlayer);
}

std::vector<AObject *>*	WorldMap::getWorldMap()
{
  return &_map;
}

int	WorldMap::getNbPlayer() const
{
  return (_nbPlayers);
}

int	WorldMap::getNbIA() const
{
  return (_nbAI);
}

int	WorldMap::getHeight() const
{
  return (_height);
}

int	WorldMap::getWidth() const
{
  return (_width);
}

int	WorldMap::getnbWalls() const
{
  return (_nbWalls);
}

std::list<int>	WorldMap::getListPosCube() const
{
  return (_list_pos_cube);
}

void	WorldMap::setListPosCube(const std::list<int> &new_pos_cube)
{
  _list_pos_cube = new_pos_cube;
}
