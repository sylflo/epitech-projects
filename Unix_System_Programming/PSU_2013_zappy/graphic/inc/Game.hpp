//
// Game.hpp for zappy in /home/storm/zappy/zappy/inc
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Sun Jun 22 02:12:26 2014 Julian Caille
// Last update Sat Jul 12 19:07:16 2014 Julian Caille
//

#ifndef _GAME_HPP_
# define _GAME_HPP_

# include "Display.hpp"
# include "Network.hpp"
# include "Animate.hpp"

class	Game : public Display, public Network
{
public:
  enum
    {
      LEFT,
      RIGHT,
      UP,
      DOWN
    };
  enum
    {
      ZOOM_ON,
      ZOOM_OUT
    };
public:
  Game(sf::RenderWindow *window, Sound &sound, sf::Event &event,
       sf::View *view, const std::string &ip, const int &port);
  ~Game();
  virtual bool	initialize();
  virtual std::string	events();
  virtual void	show();
  void	drawBackground();
  void	drawBc();
  void	drawLoader(unsigned int, unsigned int);
  void	drawSelected(char const *label, float const &posX, float const &posY);
  void	drawCase(Item* const &item, int const &type, float const &posX, float const &posY);
  void	drawItems(std::vector<Item*> const &_case, int const &size, float const &posX, float const &posY);
  void	verifyDestination(LivingEntity *entity, sf::Vector2f const &position, int const &status);
  void	drawEntities();
  void	moveCamera(int direction);
  void	zoomCamera(int status);
  void	drawUI();
  void	readMouse();
  void	shortcutsUI();
  void	keyCamera();
  void	verifyCameraPikmin();
  bool	notInUI(sf::Vector2i _localPosition);
  void	CountItems(std::vector<Item*> const &_case);
  void	CountInventory(std::vector<Item*> const &_case);
  void	scaleSprites(int const &type, int const &nbElements, int const &mode);
  void	drawInventory();
  void	changeTime(int const &new_time);
  void	debugAnim();
  void	playSound(LivingEntity *entity, std::string const &label, int const &type,
		  int const &i);
  void	infoOnTeams();
  void	infoOnPikminTeam(int const &pos);
  void	calculatePikminPosTeam(Team *team);
  void	handleWorldCommands();
  void	finishDisplay();
  void	checkClosedSound();
private:
  Texture _textures;
  Animated _debug;
  std::vector<Animated > _pikmin;
  sf::Thread	*_thread2;
  sf::VertexArray _items;
  sf::Font	  _font;
  sf::Clock	 _clock;
  sf::Text	  _text;
  unsigned int	_cameraX;
  unsigned int	_cameraY;
  unsigned int	_zoom;
  int		_caseSelected;
  bool		_showInfoCase;
  bool		_mask;
  bool		_displayUI;
  bool		_displayQuestion;
  bool		_soundOn;
  bool		_showInventory;
  bool		_timeUI;
  bool		_infoTeam;
  int		_modeCamera;
  int		_Dir;
  int		_currentPikmin;
  int		_currentTeam;
  std::vector<int>		_currentTeamPikmin;
};

#endif /* !_GAME_HPP_ */
