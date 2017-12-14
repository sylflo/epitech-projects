//
// GameEngine.hpp for  in /home/chatea_s/project/c++/bomberman/LibBomberman_linux_x64
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Mon May  5 20:46:03 2014 Sylvain Chateau
// Last update Sun Jun 15 22:17:45 2014 maxime duboy
//

#ifndef GAMEENGINE_H_
# define GAMEENGINE_H_

# include <list>
# include <Game.hh>
# include <BasicShader.hh>
# include "AObject.hpp"
# include "ABomber.hpp"
# include "Cube.hpp"
# include "WorldMap.hpp"
# include "Camera.hpp"
# include "Collision.hpp"
# include "Bomb.hpp"

class GameEngine : public gdl::Game
{

private:

  gdl::SdlContext		*_context;
  gdl::Clock			_clock;

  gdl::BasicShader		_shader;
  const int			_width;
  const int			_height;
  int				_choose;

  gdl::Texture			*_wall_texture;
  gdl::Texture			*_unbreak_texture;
  gdl::Texture			*_ia_texture;
  gdl::Texture			*_fire_texture;
  gdl::Texture			*_fire_up_texture;
  gdl::Texture			*_bomb_up_texture;
  gdl::Texture			*_speed_up_texture;

  gdl::Geometry			*_geometry;
  std::vector<AObject*>		*_map;
  WorldMap	       		*_obj_map;

  in::Input			*_input;
  std::vector<Camera *>		_camera;
  glm::mat4			_transformation;
  glm::mat4			_transformation_2;
  std::vector<glm::mat4>	_projection;

  Collision			*_collision;

  std::list<int>		_list_visual;
  std::vector<ABomber *>	_players;
  std::list<int>		_list_pos_cube;


  AObject			*_bomb;
  gdl::Model			_bombModel;
  int				_pos_bomb;
  float				_bonusRotate;
  const float			_speed;

public:
  GameEngine(const int &, const int &, const int &);
  GameEngine(const int &);
  ~GameEngine();

public:
  bool			initialize();
  bool			update();
  void			draw();
  void			collision(ABomber *, Camera *,
				  glm::mat4 &);
  void			collision_right(const float &, AObject *, Camera *,
					glm::mat4 &);
  void			collision_left(const float &, AObject *, Camera *,
				       glm::mat4 &);

public:
  const gdl::BasicShader	getShader() const;
  const gdl::Clock		getClock() const;
  std::vector<AObject *>	*getWorldMap();
  const WorldMap		*getObjWorldMap() const;
  void				setContext(gdl::SdlContext *);
  void				setInput(in::Input *input);
};

#endif /* !GAMEENGINE_H_*/
