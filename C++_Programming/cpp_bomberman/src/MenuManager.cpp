//
// MenuManager.cpp for bomberman in /home/couder_a/Depot/cpp/git/cpp_bomberman
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Thu Jun 12 11:21:28 2014 Arthur Coudert
// Last update Mon Jun 16 01:07:57 2014 Julian Caille
//

#include "MenuManager.hpp"

MenuManager::MenuManager()
{
  _menu = 0;
  _sameKey = false;
}

MenuManager::~MenuManager()
{
}

bool	MenuManager::initialize()
{
  std::list<AMenu*>::iterator	it;

  if (!_context.start(800, 600, "My bomberman!"))
    {
      throw MyError("Cannot load context");
      return (false);
    }
  if (!_shader.load("./shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    {
      throw MyError("Error a file or two for the shader is missing");
      return (false);
    }
  glAlphaFunc(GL_GREATER, 0.1f);
  glEnable(GL_ALPHA_TEST);
  _projection = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f);
  _shader.bind();
  _shader.setUniform("view", glm::mat4(1));
  _shader.setUniform("projection", _projection);
  _menuList.push_back(new MainMenu());
  _menuList.push_back(new MapMenu());
  _menuList.push_back(new LoadMenu());
  _menuList.push_back(new HelpMenu());
  for (it = _menuList.begin(); it != _menuList.end(); it++)
    (*it)->initialize();
  _sound.CreateSound("menu", "./sound/mp3/menu.mp3", true);
  _sound.PlaySound("menu");
  return (true);
}

static bool	handleMainMenu(int chose, int &menu)
{
  menu = chose;
  if (chose == 4)
    return (false);
  return (true);
}

static bool	handleMapConfig(int chose, int &menu, AMenu * menuthis, MenuManager *intance)
{
  MapMenu	*mapMenu;
  GameEngine	*engine;


  if ((mapMenu = dynamic_cast<MapMenu *>(menuthis)))
    {
      engine = new GameEngine(mapMenu->getWidh(), mapMenu->getHeight(), mapMenu->getNbPlayer());
      engine->setContext(intance->getContext());
      engine->setInput(intance->getInput());
      if (!engine->initialize())
	return (EXIT_FAILURE);
      while (engine->update())
	engine->draw();
    }
  intance->getInput()->updateEvents();
  menu = 0;
  return (true);
}

static bool	handleLoad(int chose, int &menu, AMenu *menuthis, MenuManager *intance)
{
  LoadMenu	*loadMenu;
  GameEngine	*engine;

  menu = 0;
  return (true);
}

bool	MenuManager::update()
{
  std::list<AMenu*>::iterator	it;
  int	i;
  int	event;

  i = 0;
  for (it = _menuList.begin(); it != _menuList.end(); it++)
    {
      _input.updateEvents();
      if (i == _menu)
	{
	  event = (*it)->update(_clock, _input);
	  if (event == 0 && _sameKey == false)
	    {
	      _sameKey = true;
	      if (_menu == 0)
		return handleMainMenu((*it)->getChose(), _menu);
	      else if (_menu == 1)
		return handleMapConfig((*it)->getChose(), _menu, *it, this);
	      else
		return handleLoad((*it)->getChose(), _menu, *it, this);
	    }
	  else
	    {
	      _sameKey = false;
	      if (event == -1)
		_menu = 0;
	    }
	  break;
	}
      i++;
    }
  if (_input.quit() || _input.getKey(SDL_SCANCODE_ESCAPE))
    return false;
 return (true);
}

void	MenuManager::draw()
{
  std::list<AMenu*>::iterator	it;
  int	i;

  i = 0;
  if (_menu >= 0 || _menu <= 2)
    {
      for (it = _menuList.begin(); it != _menuList.end(); it++)
	{
	  if (i == _menu)
	    {
	      (*it)->draw(_shader, _clock);
	      break;
	    }
	  i++;
	}
    }
  _context.flush();
}

in::Input	*MenuManager::getInput()
{
  return (&_input);
}

const gdl::BasicShader	MenuManager::getShader() const
{
  return (_shader);
}
const gdl::Clock	MenuManager::getClock() const
{
  return (_clock);
}

gdl::SdlContext	*MenuManager::getContext()
{
  return (&_context);
}
