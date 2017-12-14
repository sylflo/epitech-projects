//
// GameEngine.cpp for  in /home/chatea_s/project/c++/bomberman/LibBomberman_linux_x64
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Mon May  5 20:48:56 2014 Sylvain Chateau
// Last update Sun Jun 15 22:35:50 2014 maxime duboy
//
# include <unistd.h>

#include "GameEngine.hpp"
#include "MyError.hpp"
#include "Player.hpp"

double g_current_time;

GameEngine::GameEngine(const int &width, const int &height,
 const int &nb_players)
  :_width(width), _height(height), _speed(5.0f)
{

  _players.resize(nb_players);

  _camera.resize(nb_players);
  _projection.resize(nb_players);

  _wall_texture = new gdl::Texture();
  _unbreak_texture = new gdl::Texture();
  _ia_texture = new gdl::Texture();
  _fire_texture = new gdl::Texture();
  _fire_up_texture = new gdl::Texture();
  _bomb_up_texture = new gdl::Texture();
  _speed_up_texture = new gdl::Texture();

  _geometry = new gdl::Geometry();
  _pos_bomb = -1;
  _bonusRotate = 0;
}

GameEngine::GameEngine(const int &choose)
  :_speed(5.0f), _wall_texture(NULL),
   _ia_texture(NULL), _obj_map(NULL), _collision(NULL), _pos_bomb(-1),
   _bonusRotate(0), _choose(choose), _width(0), _height(0)
{
  int nb_players = 2;
  _players.resize(nb_players);
  _camera.resize(nb_players);
  _projection.resize(nb_players);
  _wall_texture = new gdl::Texture();
  _unbreak_texture = new gdl::Texture();
  _ia_texture = new gdl::Texture();
  _fire_texture = new gdl::Texture();
  _fire_up_texture = new gdl::Texture();
  _bomb_up_texture = new gdl::Texture();
  _speed_up_texture = new gdl::Texture();
  _geometry = new gdl::Geometry();
}

bool	GameEngine::initialize()
{
  int	posPlayer;

  if (!_wall_texture->load("./assets/texture/block.tga"))
    {
      throw MyError("Error the texture block is not present");
      return (false);
    }

  if (!_fire_texture->load("./assets/texture/fire.tga"))
    {
      throw MyError("Error the texture fire is not present");
      return (false);
    }
  if (!_fire_up_texture->load("./assets/texture/fireUp.tga"))
    {
      throw MyError("Error the texture fire up is not present");
      return (false);
    }
  if (!_bomb_up_texture->load("./assets/texture/bomb_up.tga"))
    {
      throw MyError("Error the texture bomb up is not present");
      return (false);
    }
  if (!_speed_up_texture->load("./assets/texture/speed.tga"))
    {
      throw MyError("Error the texture speed up is not present");
      return (false);
    }
  if (!_unbreak_texture->load("./assets/texture/bedrock.tga"))
    {
      throw MyError("Error the texture bedrock is not present");
      return (false);
    }
  if (!_ia_texture->load("./assets/test.tga"))
    {
      throw MyError("Error the texture block is not present");
      return (false);
    }
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    {
      throw MyError("Error a file or two for the shader is missing");
      return (false);
    }
  WorldMap::init(_width, _height, 1, 1);
  _obj_map = WorldMap::get();
    if (!_obj_map->check_nbPlayers())
    return (false);
  if (!_obj_map->initialize(_geometry))
    return (false);
  _obj_map->createWorldMap(_geometry);
  _map = _obj_map->getWorldMap();
  _list_pos_cube = _obj_map->getListPosCube();
  _bomb = new Bomb();
  _bomb->initialize();

  _projection[0] = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
  _players[0] = new Player(1, 1, AObject::PLAYER_ONE,
			   "./assets/marvin.fbx", _map,
			   SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT,
			   SDL_SCANCODE_UP, SDL_SCANCODE_DOWN,
			   SDL_SCANCODE_L,_width);
  if (!_players[0]->initialize())
    return (false);
  _players[0]->setPosCase(_width);
  if (_players.size() == 1)
    {
      _camera[0] = new Camera(glm::vec3(_players[0]->getPosX(), 10,
					-1 +_players[0]->getPosZ()),
			      glm::vec3(_players[0]->getPosX(), 0,
					_players[0]->getPosZ()),
			      glm::vec3(0, 0, 1),
			      _width, _height,
			      SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT,
			      SDL_SCANCODE_UP, SDL_SCANCODE_DOWN);
      _camera[0]->lookAt(_transformation);
    }

  if (_players.size() > 1)
    {
      _camera[0] = new Camera(glm::vec3(_players[0]->getPosX() - 2, 10,
					-1 +_players[0]->getPosZ()),
			      glm::vec3(_players[0]->getPosX() - 2, 0,
					_players[0]->getPosZ()),
			      glm::vec3(0, 0, 1),
			      _width, _height,
			      SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT,
			      SDL_SCANCODE_UP, SDL_SCANCODE_DOWN);
      _camera[0]->lookAt(_transformation);



      _projection[1] = glm::perspective(60.0f, 400.0f / 600.0f, 0.1f, 100.0f);
      _projection[0] = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
      _players[1] = new Player(_width - 2, _height - 2, AObject::PLAYER_TWO,
			       "./assets/marvin.fbx", _map,
			       SDL_SCANCODE_A, SDL_SCANCODE_D,
			       SDL_SCANCODE_W, SDL_SCANCODE_S,
			       SDL_SCANCODE_SPACE ,_width);
      if (!_players[1]->initialize())
	return (false);
      _players[1]->setPosCase((_width * _height) - _width - 1);
      _camera[1] = new Camera(glm::vec3(_players[1]->getPosX(), 10,
					-1 + _players[1]->getPosZ()),
			      glm::vec3(_players[1]->getPosX(), 0,
					_players[1]->getPosZ()),
			      glm::vec3(0, 0, 1),
			      _width, _height,
			      SDL_SCANCODE_A, SDL_SCANCODE_D,
			  SDL_SCANCODE_W, SDL_SCANCODE_S);
      _camera[1]->lookAt(_transformation_2);
    }

  _collision = new Collision(_width, _height, _map);
  return (true);
}

void	GameEngine::collision_right(const float &new_time, AObject *player,
				    Camera *camera, glm::mat4 &transformation)
{
  float posPlayer = _width * static_cast<int>(player->getPosZ() + 0.5) +
    static_cast<int>(player->getPosX() + 0.5);

  if (player->update(_clock, *_input, _pos_bomb) == 1 &&
      !_collision->check_up((player->getPosX() + 0.5),
			    (player->getPosZ() + 1.0), _pos_bomb, posPlayer))
    {
      player->setPosZ(player->getPosZ() + new_time);
      player->translate(glm::vec3(0, 0, 1) * new_time);
      camera->move(*_input, _clock, new_time);
      camera->lookAt(transformation);
      _shader.setUniform("view", transformation);
    }
  if (player->update(_clock, *_input, _pos_bomb) == 2 &&
      !_collision->check_down((player->getPosX() + 0.5), (player->getPosZ())
			      , _pos_bomb, posPlayer))
    {
      player->setPosZ(player->getPosZ() - new_time);
      player->translate(glm::vec3(0, 0, -1) * new_time);
      camera->move(*_input, _clock, new_time);
      camera->lookAt(transformation);
      _shader.setUniform("view", transformation);
    }
}

void	GameEngine::collision_left(const float &new_time, AObject *player,
				   Camera *camera, glm::mat4 &transformation)
{
  float posPlayer = _width * static_cast<int>(player->getPosZ() + 0.5) +
    static_cast<int>(player->getPosX() + 0.5);

  if (player->update(_clock, *_input, _pos_bomb) == 3 &&
      !_collision->check_left((player->getPosX() + 1.0),
			      (player->getPosZ() + 0.5),
			      _pos_bomb, posPlayer))
    {
      player->setPosX(player->getPosX() + new_time);
      player->translate(glm::vec3(1, 0, 0) * new_time);
      camera->move(*_input, _clock, new_time);
      camera->lookAt(transformation);
      _shader.setUniform("view", transformation);
    }
  if (player->update(_clock, *_input, _pos_bomb) == 4 &&
      !_collision->check_right((player->getPosX()),
			       (player->getPosZ() + 0.5), _pos_bomb,
			       posPlayer))
    {
      player->setPosX(player->getPosX() - new_time);
      player->translate(glm::vec3(-1, 0, 0) * new_time);
      camera->move(*_input, _clock, new_time);
      camera->lookAt(transformation);
      _shader.setUniform("view", transformation);
    }
}

void	GameEngine::collision(ABomber *player,
			      Camera *camera, glm::mat4 &transformation)
{
  const float	new_time =  _clock.getElapsed() * player->getSpeed();

  if (player->update(_clock, *_input, _pos_bomb) != 5)
    {
      this->collision_right(new_time, player, camera, transformation);
        this->collision_left(new_time, player, camera, transformation);
    }
}

bool		GameEngine::update()
{
  bool		collision;
  int	i = 0;

  _input->updateEvents();
  if (_input->quit() || _input->getKey(SDL_SCANCODE_ESCAPE))
    return false;
  _context->updateClock(_clock);

  this->collision(_players[0], _camera[0], _transformation);
  if (_players.size() > 1)
    this->collision(_players[1], _camera[1], _transformation_2);
  g_current_time += _clock.getElapsed();
  if (_bonusRotate < 1)
    _bonusRotate += 0.5;
  else
    _bonusRotate = 0;
  for (size_t i = 0; i < (*_map).size(); ++i)
    {
      if ((*_map)[i] != NULL && (*_map)[i]->getType() != AObject::UNBREAK)
	(*_map)[i]->update(_clock, *_input, _pos_bomb);
    }
  return true;
}

void	GameEngine::draw()
{
  int	i = 0;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


  if (_players.size() > 1)
    glViewport((GLint)401, (GLint)0, (GLsizei)800, (GLsizei)600);

  _shader.bind();
  _shader.setUniform("view", _transformation);
  _shader.setUniform("projection", _projection[0]);

  for (int j = 0; j < _players.size(); j++)
    _players[j]->draw(_shader, _clock);
  _list_visual = _camera[0]->find_around(_players[0]->getPosX(), _players[0]->getPosZ(),
					 _players[0]->getPosCase());
  for (std::list<int>::iterator it = _list_visual.begin(); it != _list_visual.end(); it++)
    {
      AObject *drawBomb;
      i = *it;
      if ((*_map)[i] != NULL && i >= 0 && i < (_width * _height))
	{
	  if ((*_map)[i]->getType() == AObject::BOMB)
	    {
	      _collision->setWorldMap(_map);
	      (*_map)[i]->draw(_shader, _clock);
	    }
	  if ((*_map)[i]->getType() == AObject::FIRE)
	    {
	      if (_width * static_cast<int>(_players[0]->getPosZ() + 0.5) +
		  static_cast<int>(_players[0]->getPosX() + 0.5) == i)
		_players[0]->setDead();
	      if (_players[1])
		{
		  if (_width * static_cast<int>(_players[1]->getPosZ() + 0.5) +
		      static_cast<int>(_players[1]->getPosX() + 0.5) == i)
		    _players[1]->setDead();
		}
	      if (i == _pos_bomb)
		_pos_bomb = -1;
	      if (!(*_map)[i]->isFadeOut())
		(*_map)[i]->did_it_explode(0);
	      else
		{
		  if ((*_map)[i]->did_it_explode(2))
		    {
		      int   crate = 0;
		      int   tempPosX = (*_map)[i]->getPosX();
		      int   tempPosZ = (*_map)[i]->getPosZ();
		      if ((*_map)[i]->wasItCrate(1))
			crate = rand() % 4;
		      if (!crate)
			(*_map)[i] = NULL;
		      else if (crate == 1)
			(*_map)[i] = new Cube(tempPosX, tempPosZ, AObject::BONUS_RANGE);
		      else if (crate == 2)
			(*_map)[i] = new Cube(tempPosX, tempPosZ, AObject::BONUS_BEMBS);
		      else if (crate == 3)
			(*_map)[i] = new Cube(tempPosX, tempPosZ, AObject::BONUS_SPEED);
		      if ((*_map)[i])
			{
			  (*_map)[i]->scale(glm::vec3(0.5, 0.5, 0.5));
			  (*_map)[i]->translate(glm::vec3(tempPosX, 0, tempPosZ));
		      //(*_map).at(i) = NULL;
			}
		      _map = _obj_map->getWorldMap();
		      this->_collision->setWorldMap(_map);
		      //	      _obj(*_map)->dumpWorldMap();
		      //_obj(*_map)->dumpWorldMap();
		    }
		  else
		    (*_map)[i]->draw(_shader, _clock, _fire_texture, _geometry);
		}
	    }
	  else if ((*_map)[i]->getType() == AObject::BLOCK)
	    (*_map)[i]->draw(_shader, _clock, _wall_texture, _geometry);
	  else if ((*_map)[i]->getType() == AObject::BONUS_RANGE)
	    {
	       (*_map)[i]->rotate(glm::vec3(0, 1, 0), _bonusRotate);
	      (*_map)[i]->draw(_shader, _clock, _fire_up_texture, _geometry);
	    }
	  else if ((*_map)[i]->getType() == AObject::BONUS_BEMBS)
	    {
	      (*_map)[i]->rotate(glm::vec3(0, 1, 0), _bonusRotate);
	      (*_map)[i]->draw(_shader, _clock, _bomb_up_texture, _geometry);
	    }
	  else if ((*_map)[i]->getType() == AObject::BONUS_SPEED)
	    {
	      (*_map)[i]->rotate(glm::vec3(0, 1, 0), _bonusRotate);
	      (*_map)[i]->draw(_shader, _clock, _speed_up_texture, _geometry);
	    }
	  else if ((*_map)[i]->getType() == AObject::UNBREAK)
	    (*_map)[i]->draw(_shader, _clock, _unbreak_texture, _geometry);
	}
    }
  if (!_players[0]->getAlive())
    {
      sleep(1);
      exit(0);
    }
  if (_players.size() > 1)
    {
      glViewport((GLint)0, (GLint)0, (GLsizei)400, (GLsizei)600);
      _shader.bind();
      _shader.setUniform("view", _transformation_2);
      _shader.setUniform("projection", _projection[1]);
      for (int j = 0; j < _players.size(); j++)
	_players[j]->draw(_shader, _clock);
      _list_visual = _camera[1]->find_around(_players[1]->getPosX(),
					     _players[1]->getPosZ(), _players[1]->getPosCase());
      for (std::list<int>::iterator it = _list_visual.begin(); it != _list_visual.end(); it++)
	{
	  i = *it;
	  if ((*_map)[i] != NULL && i >= 0 && i < (_width * _height))
	    AObject *drawBomb;
	  i = *it;
	  if ((*_map)[i] != NULL && i >= 0 && i < (_width * _height))
	    {
	      if ((*_map)[i]->getType() == AObject::BOMB)
		{
		  _collision->setWorldMap(_map);
		  (*_map)[i]->draw(_shader, _clock);
		}
	      if ((*_map)[i]->getType() == AObject::FIRE)
		{
		  if (i == _pos_bomb)
		    _pos_bomb = -1;
		  if (!(*_map)[i]->isFadeOut())
		    (*_map)[i]->did_it_explode(0);
		  else
		    {
		      if ((*_map)[i]->did_it_explode(2))
			{
			  (*_map)[i] = NULL;
			  _map = _obj_map->getWorldMap();
			}
		      else
			(*_map)[i]->draw(_shader, _clock, _fire_texture, _geometry);
		    }
		}
	      else if ((*_map)[i]->getType() == AObject::BLOCK)
		(*_map)[i]->draw(_shader, _clock, _wall_texture, _geometry);
	      else if ((*_map)[i]->getType() == AObject::BONUS_RANGE)
		(*_map)[i]->draw(_shader, _clock, _fire_up_texture, _geometry);
	      else if ((*_map)[i]->getType() == AObject::BONUS_BEMBS)
		(*_map)[i]->draw(_shader, _clock, _bomb_up_texture, _geometry);
	      else if ((*_map)[i]->getType() == AObject::BONUS_SPEED)
		(*_map)[i]->draw(_shader, _clock, _speed_up_texture, _geometry);
	      else if ((*_map)[i]->getType() == AObject::UNBREAK)
		(*_map)[i]->draw(_shader, _clock, _unbreak_texture, _geometry);
	      if (!_players[1]->getAlive())
		exit(0);
	    }
	}
    }
  _context->flush();
}

GameEngine::~GameEngine()
{
  delete _obj_map;
  delete _collision;
  delete _wall_texture;
}

const gdl::BasicShader	GameEngine::getShader() const
{
  return (_shader);
}

const gdl::Clock	GameEngine::getClock() const
{
  return (_clock);
}

std::vector<AObject *>* GameEngine::getWorldMap()
{
  return (_map);
}

const WorldMap *GameEngine::getObjWorldMap() const
{
  return (_obj_map);
}

void	GameEngine::setInput(in::Input *input)
{
  _input = input;
}

void	GameEngine::setContext(gdl::SdlContext *context)
{
  _context = context;
}
