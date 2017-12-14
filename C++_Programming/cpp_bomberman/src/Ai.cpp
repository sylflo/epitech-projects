//
// Player.cpp for  in /home/chatea_s/project/c++/bomberman/LibBomberman_linux_x64
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Mon May  5 20:32:39 2014 Sylvain Chateau
// Last update Sun Jun 15 22:31:30 2014 maxime duboy
//

#include "Player.hpp"

Player::Player(const float &posX, const float &posZ, const int &type,
	       const std::string &marvin, std::vector<AObject *> *map,
	       const SDL_Scancode &left, const SDL_Scancode &right,
	       const SDL_Scancode &up, const SDL_Scancode &down,
	       const SDL_Scancode &key_bomb, const int &mapWidth)
  :_dir(Up), _stop(true), _marvin(marvin), _map(map),
   _left(left), _right(right),  _up(up), _down(down), _key_bomb(key_bomb)
{
  _posX = posX;
  _posZ = posZ;
  _type = type;
  _mapWidth = mapWidth;
  _nbBombs = 1;
  _Range = 3;
  _alive = true;
}

Player::~Player()
{
}

bool Player::initialize()
{
  _speed = 5.0f;
  if (!_model.load(_marvin))
    {
      std::cout << "error when loading marvin" << std::endl;
      return (false);
    }
  scale(glm::vec3(0.003, 0.003, 0.003));
  translate(glm::vec3(_posX, 0, _posZ));
  _model.createSubAnim(0, "NoMove", 0, 0);
  _model.createSubAnim(0, "Run", 40, 54);
  _model.setCurrentSubAnim("NoMove", true);
  return (true);
}

int	Player::getDir() const
{
  return (_dir);
}

int	Player::update(gdl::Clock const &clock, in::Input &input, int pos_bomb)
{
  float	posPlayer;

  posPlayer = _mapWidth * static_cast<int>(_posZ + 0.5) +
    static_cast<int>(_posX + 0.5);

  if (_bombs.size())
    {
      if (_bombs.front()->did_it_explode(1))
	{
	  int	tempXpos = static_cast<int>(_bombs.front()->getPosX());
	  int	tempZpos = static_cast<int>(_bombs.front()->getPosZ());
	  int	tempPos = _bombs.front()->getPosPlayer();
	  fireAlgorythm(tempXpos, tempZpos, tempPos, _Range);
	  _bombs.pop_front();
	}
    }

  if (_map->at(posPlayer))
    {
      if (_map->at(posPlayer)->getType() == AObject::BONUS_BEMBS)
	{
	  _nbBombs++;
	  _map->at(posPlayer) = NULL;
	}
      else if (_map->at(posPlayer)->getType() == AObject::BONUS_RANGE)
	{
	  _Range++;
	  _map->at(posPlayer) = NULL;
	}
      else if (_map->at(posPlayer)->getType() == AObject::BONUS_SPEED)
	{
	  if (_speed < 8.0)
	    _speed += 1.5;
	  _map->at(posPlayer) = NULL;
	}
    }


  if (input.getKey(_up) && input.getKey(_right) ||
      input.getKey(_up) && input.getKey(_left) ||
      input.getKey(_down) && input.getKey(_left) ||
      input.getKey(_down) && input.getKey(_right) ||
      input.getKey(_down) && input.getKey(_up) ||
      input.getKey(_right) && input.getKey(_left))
    {
      _stop = true;
      _model.setCurrentSubAnim("NoMove", true);
      return (5);
    }
  if (input.getKey(_up))
    {
      if (_dir == Down)
	rotate(glm::vec3(0,1,0), 180);
      else if (_dir == Right || _dir == Left)
	(_dir == Right ? rotate(glm::vec3(0,1,0), 90) : rotate(glm::vec3(0,1,0), -90));
      _dir = Up;
      if (_stop)
	{
	  _stop = false;
	  _model.setCurrentSubAnim("Run", true);
	}
      return (1);
    }
  if (input.getKey(_down))
    {
      if (_dir == Up)
	rotate(glm::vec3(0,1,0), 180);
      else if (_dir == Right || _dir == Left)
	(_dir == Right ? rotate(glm::vec3(0,1,0), -90) : rotate(glm::vec3(0,1,0), 90));
      _dir = Down;
      if (_stop)
	{
	  _stop = false;
	  _model.setCurrentSubAnim("Run", true);
	}
      return (2);
    }
  if (input.getKey(_left))
    {
      if (_dir == Right)
	rotate(glm::vec3(0,1,0), 180);
      else if (_dir == Up || _dir == Down)
	(_dir == Up ? rotate(glm::vec3(0,1,0), 90) : rotate(glm::vec3(0,1,0), -90));
      _dir = Left;
      if (_stop)
	{
	  _stop = false;
	  _model.setCurrentSubAnim("Run", true);
	}
      return (3);
    }
  if (input.getKey(_right))
    {
      if (_dir == Left)
	rotate(glm::vec3(0,1,0), 180);
      else if (_dir == Up || _dir == Down)
	(_dir == Up ? rotate(glm::vec3(0,1,0), -90) : rotate(glm::vec3(0,1,0), 90));
      _dir = Right;
      if (_stop)
	{
	  _stop = false;
	  _model.setCurrentSubAnim("Run", true);
	}
      return (4);
    }

  if (input.getKeyUp(_key_bomb))
    {
      posPlayer = _mapWidth * static_cast<int>(_posZ + 0.5) +
	static_cast<int>(_posX + 0.5);
      pos_bomb = posPlayer;

      if (_bombs.size() < _nbBombs)
	{
	  if (_map->at(posPlayer) == NULL)
	    {
	      _bombs.push_back(new Bomb(AObject::BOMB, _mapWidth, posPlayer,
				      _posX + 0.5, _posZ + 0.5));
	      _bombs.back()->initialize();
	      _bombs.back()->setTranslate(static_cast<int>(_posX + 0.5),
					   static_cast<int>(_posZ + 0.5));
	      _bombs.back()->setPosCase(posPlayer);
	      _map->at(posPlayer) = _bombs.back();
	      _bombs.back()->did_it_explode(0);
	  }
	}
    }
  if (!input.getKey(_up) && !input.getKey(_down) && !input.getKey(_left) && !input.getKey(_right))
    {
      _stop = true;
      _model.setCurrentSubAnim("NoMove", true);
    }
  return (0);
}

void	Player::fireAlgorythm(int const &PosX, int const &PosZ, int const &PosM
			      , int const &Range)
{
  int		current;
  bool		right = false;
  bool		left = false;
  bool		down = false;
  bool		up = false;
  int		crate;

  current = 1;
  crate = 0;
  _map->at(PosM) = new Cube(PosX, PosZ, AObject::FIRE);
  _map->at(PosM)->translate(glm::vec3(PosX, 0, PosZ));
  while (current < Range)
    {
      if (!up)
	{
	  if (_map->at(PosM + (_mapWidth * current)) == NULL ||
	      _map->at(PosM + (_mapWidth * current))->getType() == AObject::BOMB ||
	      _map->at(PosM + (_mapWidth * current))->getType() == AObject::BLOCK ||
	      _map->at(PosM + (_mapWidth * current))->getType() == AObject::BONUS_SPEED ||
	      _map->at(PosM + (_mapWidth * current))->getType() == AObject::BONUS_RANGE ||
	      _map->at(PosM + (_mapWidth * current))->getType() == AObject::BONUS_BEMBS ||
	      _map->at(PosM + (_mapWidth * current))->getType() == AObject::FIRE )
	    {
	      if (_map->at(PosM + (_mapWidth * current)))
		{
		  if (_map->at(PosM + (_mapWidth * current))->getType() == AObject::BOMB)
		    _map->at(PosM + (_mapWidth * current))->setTimeWait(-99.00);
		  if (_map->at(PosM + (_mapWidth * (current)))->getType() == AObject::BLOCK)
		    crate++;
		  if (_map->at(PosM + (_mapWidth * (current)))->getType() == AObject::BLOCK)
		    //&& _map->at(PosM + (_mapWidth * (current + 1))) != NULL)
		    up = true;
		}
	      _map->at(PosM + (_mapWidth * current)) = new Cube(PosX, PosZ + (current), AObject::FIRE);
	      if (crate)
		_map->at(PosM + (_mapWidth * current))->wasItCrate(0);
	      crate = 0;
	      _map->at(PosM + (_mapWidth * current))->translate(glm::vec3(PosX, 0, PosZ + (current)));
	    }
	  else
	    up = true;
	}
      if (!down)
	{
	  if (_map->at(PosM - (_mapWidth * current)) == NULL ||
	      _map->at(PosM - (_mapWidth * current))->getType() == AObject::BOMB ||
	      _map->at(PosM - (_mapWidth * current))->getType() == AObject::BONUS_BEMBS ||
	      _map->at(PosM - (_mapWidth * current))->getType() == AObject::BONUS_RANGE ||
	      _map->at(PosM - (_mapWidth * current))->getType() == AObject::BONUS_SPEED ||
	      _map->at(PosM - (_mapWidth * current))->getType() == AObject::BLOCK ||
	      _map->at(PosM - (_mapWidth * current))->getType() == AObject::FIRE)
	    {
	      if (_map->at(PosM - (_mapWidth * current)))
		{
		  if (_map->at(PosM - (_mapWidth * current))->getType() == AObject::BOMB)
		    _map->at(PosM - (_mapWidth * current))->setTimeWait(-99.00);
		  if (_map->at(PosM - (_mapWidth * (current)))->getType() == AObject::BLOCK)
		    crate++;
		  if (_map->at(PosM - (_mapWidth * (current)))->getType() == AObject::BLOCK)
		      //&& _map->at(PosM - (_mapWidth * (current + 1))) != NULL)
		    down = true;
		}
	      _map->at(PosM - (_mapWidth * current)) = new Cube(PosX, PosZ - (current), AObject::FIRE);
	      if (crate)
		_map->at(PosM - (_mapWidth * current))->wasItCrate(0);
	      crate = 0;
	      _map->at(PosM - (_mapWidth * current))->translate(glm::vec3(PosX, 0, PosZ - (current)));
	    }
	  else
	    down = true;
	}
      if (!left)
	{
	  if (_map->at(PosM + current) == NULL ||
	      _map->at(PosM + current)->getType() == AObject::BOMB ||
	      _map->at(PosM + current)->getType() == AObject::BONUS_BEMBS ||
	      _map->at(PosM + current)->getType() == AObject::BONUS_RANGE ||
	      _map->at(PosM + current)->getType() == AObject::BONUS_SPEED ||
	      _map->at(PosM + current)->getType() == AObject::BLOCK ||
	      _map->at(PosM + current)->getType() == AObject::FIRE)
	    {
	      if (_map->at(PosM + current))
		{
		  if (_map->at(PosM + current)->getType() == AObject::BOMB)
		    _map->at(PosM + current)->setTimeWait(-99.00);
		  if (_map->at(PosM + (current))->getType() == AObject::BLOCK)
		    crate++;
		  if (_map->at(PosM + (current))->getType() == AObject::BLOCK)
		    //&& _map->at(PosM + (current + 1)) != NULL)
		    left = true;
		}
	      _map->at(PosM + current) = new Cube(PosX + (current), PosZ, AObject::FIRE);
	      if (crate)
		_map->at(PosM + current)->wasItCrate(0);
	      crate = 0;
	      _map->at(PosM + current)->translate(glm::vec3(PosX + current, 0, PosZ));
	    }
	  else
	    left = true;
	}
      if (!right)
	{
	  if (_map->at(PosM - (current)) == NULL ||
	      _map->at(PosM - (current))->getType() == AObject::BOMB ||
	      _map->at(PosM - (current))->getType() == AObject::BLOCK ||
	      _map->at(PosM - (current))->getType() == AObject::BONUS_SPEED ||
	      _map->at(PosM - (current))->getType() == AObject::BONUS_BEMBS ||
	      _map->at(PosM - (current))->getType() == AObject::BONUS_RANGE ||
	      _map->at(PosM - (current))->getType() == AObject::FIRE)
	    {
	      if (_map->at(PosM - (current)))
		{
		  if (_map->at(PosM - current)->getType() == AObject::BOMB)
		    _map->at(PosM - current)->setTimeWait(-99.00);
		  if (_map->at(PosM - (current))->getType() == AObject::BLOCK)
		    crate++;
		  if (_map->at(PosM - (current))->getType() == AObject::BLOCK)
		    right = true;
		}
	      _map->at(PosM - (current)) = new Cube(PosX - current, PosZ, AObject::FIRE);
	      if (crate)
		_map->at(PosM - current)->wasItCrate(0);
	      crate = 0;
	      _map->at(PosM - (current))->translate(glm::vec3(PosX - current, 0, PosZ));
	    }
	  else
	    right = true;
	}
      current++;
    }
}

void	Player::draw(gdl::AShader &shader, gdl::Clock const &clock, gdl::Texture *texture)
{
  _model.draw(shader, getTransformation(), clock.getElapsed());
}

int   Player::getPosCase() const
{
  return (_pos_case);
}

void  Player::setPosCase(const int &pos_case)
{
  _pos_case = pos_case;
}
