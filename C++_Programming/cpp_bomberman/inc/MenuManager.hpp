//
// MenuManager.hpp for bomberman in /home/couder_a/Depot/cpp/git/cpp_bomberman
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Thu Jun 12 11:21:13 2014 Arthur Coudert
// Last update Mon Jun 16 01:04:17 2014 Julian Caille

#ifndef _MENUMANAGER_H_
# define _MENUMANAGER_H_

# include <Game.hh>
# include <list>
# include <BasicShader.hh>
# include "Camera.hpp"
# include "MyError.hpp"
# include "AMenu.hpp"
# include "MainMenu.hpp"
# include "LoadMenu.hpp"
# include "MapMenu.hpp"
# include "HelpMenu.hpp"
# include "GameEngine.hpp"
# include "Sound.hpp"

class MenuManager : public gdl::Game
{
public:
  MenuManager();
  ~MenuManager();

public:
  bool	initialize();
  bool	update();
  void	draw();

public:
  const gdl::BasicShader	getShader() const;
  const gdl::Clock		getClock() const;
  gdl::SdlContext*	getContext();
  in::Input	*getInput();

private:
  gdl::SdlContext		_context;
  gdl::Clock			_clock;
  in::Input			_input;
  gdl::BasicShader		_shader;
  glm::mat4			_transformation;
  glm::mat4			_projection;
  gdl::Texture			*_selecter;
  gdl::Geometry			*_geometry;
  std::list<AMenu*>		_menuList;
  int				_menu;
  bool				_sameKey;
  Sound_mgr			_sound;
};


#endif /* _MENUMANAGER_H_ */
