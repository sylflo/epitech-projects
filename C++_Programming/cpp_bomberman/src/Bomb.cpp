//
// Bomb.cpp for Bomb in /home/storm/bomberman/cpp_bomberman/src
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Thu Jun  5 20:31:00 2014 Julian Caille
// Last update Sun Jun 15 22:32:07 2014 maxime duboy
//


#include "Bomb.hpp"

Bomb::Bomb(const int &type, const int Pos, const int PosX,
	   const int PosZ)
{
  _type = type;
  _posX = PosX;
  _posZ = PosZ;
  _pos = Pos;
  _scaleBomb = 1.001;
}

Bomb::~Bomb()
{
}

bool	Bomb::initialize()
{
  if (!_model.load("./assets/bomb.fbx"))
    {
      return (false);
    }
  scale(glm::vec3(0.003, 0.003, 0.003));
  return (true);
}

void	Bomb::draw(gdl::AShader &shader, gdl::Clock const &clock, gdl::Texture *texture, gdl::Geometry *unused)
{
  scale(glm::vec3(1.001, 1.001, 1.001));
  _model.draw(shader, getTransformation(), clock.getElapsed());
}

int	Bomb::getPosPlayer() const
{
  return (_pos);
}

void	Bomb::fireAlgorythm(int const &PosX, int const &PosZ, int const &PosM
			    , int const &Range)
{
  int		current;
  bool		right = false;
  bool		left = false;
  bool		down = false;
  bool		up = false;
  int		crate;
  WorldMap*	worldMap = WorldMap::get();
  std::vector<AObject *>* map = worldMap->getWorldMap();
  int		mapWidth = worldMap->getWidth();

  current = 1;
  crate = 0;
  map->at(PosM) = new Cube(PosX, PosZ, AObject::FIRE);
  map->at(PosM)->translate(glm::vec3(PosX, 0, PosZ));
  while (current < Range)
    {
      if (!up)
	{
	  if (map->at(PosM + (mapWidth * current)) == NULL ||
	      map->at(PosM + (mapWidth * current))->getType() == AObject::BOMB ||
	      map->at(PosM + (mapWidth * current))->getType() == AObject::BLOCK ||
	      map->at(PosM + (mapWidth * current))->getType() == AObject::BONUS_SPEED ||
	      map->at(PosM + (mapWidth * current))->getType() == AObject::BONUS_RANGE ||
	      map->at(PosM + (mapWidth * current))->getType() == AObject::BONUS_BEMBS ||
	      map->at(PosM + (mapWidth * current))->getType() == AObject::FIRE )
	    {
	      if (map->at(PosM + (mapWidth * current)))
		{
		  if (map->at(PosM + (mapWidth * current))->getType() == AObject::BOMB)
		    map->at(PosM + (mapWidth * current))->setTimeWait(-99.00);
		  if (map->at(PosM + (mapWidth * (current)))->getType() == AObject::BLOCK)
		    crate++;
		  if (map->at(PosM + (mapWidth * (current)))->getType() == AObject::BLOCK)
		    up = true;
		}
	      map->at(PosM + (mapWidth * current)) = new Cube(PosX, PosZ + (current), AObject::FIRE);
	      if (crate)
		map->at(PosM + (mapWidth * current))->wasItCrate(0);
	      crate = 0;
	      map->at(PosM + (mapWidth * current))->translate(glm::vec3(PosX, 0, PosZ + (current)));
	    }
	  else
	    up = true;
	}
      if (!down)
	{
	  if (map->at(PosM - (mapWidth * current)) == NULL ||
	      map->at(PosM - (mapWidth * current))->getType() == AObject::BOMB ||
	      map->at(PosM - (mapWidth * current))->getType() == AObject::BONUS_BEMBS ||
	      map->at(PosM - (mapWidth * current))->getType() == AObject::BONUS_RANGE ||
	      map->at(PosM - (mapWidth * current))->getType() == AObject::BONUS_SPEED ||
	      map->at(PosM - (mapWidth * current))->getType() == AObject::BLOCK ||
	      map->at(PosM - (mapWidth * current))->getType() == AObject::FIRE)
	    {
	      if (map->at(PosM - (mapWidth * current)))
		{
		  if (map->at(PosM - (mapWidth * current))->getType() == AObject::BOMB)
		    map->at(PosM - (mapWidth * current))->setTimeWait(-99.00);
		  if (map->at(PosM - (mapWidth * (current)))->getType() == AObject::BLOCK)
		    crate++;
		  if (map->at(PosM - (mapWidth * (current)))->getType() == AObject::BLOCK)
		      //&& map->at(PosM - (mapWidth * (current + 1))) != NULL)
		    down = true;
		}
	      map->at(PosM - (mapWidth * current)) = new Cube(PosX, PosZ - (current), AObject::FIRE);
	      if (crate)
		map->at(PosM - (mapWidth * current))->wasItCrate(0);
	      crate = 0;
	      map->at(PosM - (mapWidth * current))->translate(glm::vec3(PosX, 0, PosZ - (current)));
	    }
	  else
	    down = true;
	}
      if (!left)
	{
	  if (map->at(PosM + current) == NULL ||
	      map->at(PosM + current)->getType() == AObject::BOMB ||
	      map->at(PosM + current)->getType() == AObject::BONUS_BEMBS ||
	      map->at(PosM + current)->getType() == AObject::BONUS_RANGE ||
	      map->at(PosM + current)->getType() == AObject::BONUS_SPEED ||
	      map->at(PosM + current)->getType() == AObject::BLOCK ||
	      map->at(PosM + current)->getType() == AObject::FIRE)
	    {
	      if (map->at(PosM + current))
		{
		  if (map->at(PosM + current)->getType() == AObject::BOMB)
		    map->at(PosM + current)->setTimeWait(-99.00);
		  if (map->at(PosM + (current))->getType() == AObject::BLOCK)
		    crate++;
		  if (map->at(PosM + (current))->getType() == AObject::BLOCK)
		    //&& map->at(PosM + (current + 1)) != NULL)
		    left = true;
		}
	      map->at(PosM + current) = new Cube(PosX + (current), PosZ, AObject::FIRE);
	      if (crate)
		map->at(PosM + current)->wasItCrate(0);
	      crate = 0;
	      map->at(PosM + current)->translate(glm::vec3(PosX + current, 0, PosZ));
	    }
	  else
	    left = true;
	}
      if (!right)
	{
	  if (map->at(PosM - (current)) == NULL ||
	      map->at(PosM - (current))->getType() == AObject::BOMB ||
	      map->at(PosM - (current))->getType() == AObject::BLOCK ||
	      map->at(PosM - (current))->getType() == AObject::BONUS_SPEED ||
	      map->at(PosM - (current))->getType() == AObject::BONUS_BEMBS ||
	      map->at(PosM - (current))->getType() == AObject::BONUS_RANGE ||
	      map->at(PosM - (current))->getType() == AObject::FIRE)
	    {
	      if (map->at(PosM - (current)))
		{
		  if (map->at(PosM - current)->getType() == AObject::BOMB)
		    map->at(PosM - current)->setTimeWait(-99.00);
		  if (map->at(PosM - (current))->getType() == AObject::BLOCK)
		    crate++;
		  if (map->at(PosM - (current))->getType() == AObject::BLOCK)
		    right = true;
		}
	      map->at(PosM - (current)) = new Cube(PosX - current, PosZ, AObject::FIRE);
	      if (crate)
		map->at(PosM - current)->wasItCrate(0);
	      crate = 0;
	      map->at(PosM - (current))->translate(glm::vec3(PosX - current, 0, PosZ));
	    }
	  else
	    right = true;
	}
      current++;
    }
}
