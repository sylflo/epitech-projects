//
// Game.cpp for zappy in /home/storm/zappy/zappy/src
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Sun Jun 22 02:16:01 2014 Julian Caille
// Last update Sun Jul 13 20:27:16 2014 Arthur Coudert
//

#include "Game.hpp"

Game::Game(sf::RenderWindow *window, Sound &sound, sf::Event &event,
	   sf::View *view, const std::string &ip, const int &port) : Network(ip, port)
{
  _sound = sound;
  _window = window;
  _event = event;
  _view = view;
  _cameraX = 0;
  _cameraY = 0;
  _zoom = 2;
  _showInfoCase = false;
  _mask = false;
  _caseSelected = -1;
  _displayUI = true;
  _displayQuestion = false;
  _soundOn = false;
  _showInventory = false;
  _Dir = 0;
  _modeCamera = 0;
  _currentPikmin = 0;
  _currentTeam = 0;
  _timeUI = false;
  _infoTeam = false;
}

Game::~Game()
{
}

bool	Game::initialize()
{
  if (!_sound.newChannel("./sound/ingame1.ogg", "ingame1"))
   return (false);
  if (!initializeNetwork())
    {
      throw MyError("Error : couldn't reach the host !");
      return (false);
    }
  if (!_font.loadFromFile("./Fonts/mojito.ttf"))
    return (false);
  _sound.soundLabel("ingame1")->setVolume(25);
  _text.setFont(_font);
  _window->setFramerateLimit(60);
  if (!_textures.newTexture("Texture/Ressources/grass_top.png", "grass",
			    sf::IntRect(0, 0, 128, 128))
      || !_textures.newTexture("Texture/UI/loader1.png", "load1",
			       sf::IntRect(0, 0, 1024, 768))
      || !_textures.newTexture("Texture/UI/loader2.png", "load2",
			       sf::IntRect(0, 0, 1024, 768))
      || !_textures.newTexture("Texture/UI/loader3.png", "load3",
			       sf::IntRect(0, 0, 1024, 768))
      || !_textures.newTexture("Texture/UI/loader4.png", "load4",
			       sf::IntRect(0, 0, 1024, 768))
      || !_textures.newTexture("Texture/Ressources/sand.png", "sand",
			       sf::IntRect(0, 0, 128, 128))
      || !_textures.newTexture("Texture/Ressources/stone.png", "stone",
			       sf::IntRect(0, 0, 128, 128))
      || !_textures.newTexture("Texture/Ressources/dirt.png", "dirt",
			       sf::IntRect(0, 0, 128, 128))
      || !_textures.newTexture("Texture/Ressources/talk.png", "talk",
			       sf::IntRect(0, 0, 17, 17))
       || !_textures.newTexture("Texture/Ressources/Meat-Red.png", "meat",
				sf::IntRect(0, 0, 36, 24))
       || !_textures.newTexture("Texture/Ressources/Ore-Green.png", "linemate",
				sf::IntRect(0, 0, 25, 25))
       || !_textures.newTexture("Texture/Ressources/Ore-Blue.png", "deraumere",
				sf::IntRect(0, 0, 25, 25))
       || !_textures.newTexture("Texture/Ressources/Ore-Orange.png", "sibur",
				sf::IntRect(0, 0, 25, 25))
       || !_textures.newTexture("Texture/Ressources/Ore-Yellow.png", "mendiane",
				sf::IntRect(0, 0, 25, 25))
       || !_textures.newTexture("Texture/Ressources/Ore-Red.png", "phiras",
				sf::IntRect(0, 0, 25, 25))
       || !_textures.newTexture("Texture/Ressources/Ore-Purple.png", "thystame",
			       sf::IntRect(0, 0, 25, 25))
      || !_textures.newTexture("Texture/Ressources/Egg-Gold.png", "egg",
			       sf::IntRect(0, 0, 96, 36))
      || !_textures.newTexture("Texture/UI/PNG/buttonLong_brown_pressed.png", "panel",
			       sf::IntRect(0, 0, 190, 45))
      || !_textures.newTexture("Texture/UI/PNG/info_panel_brown.png", "info_panel",
			       sf::IntRect(0, 0, 100, 100))
      || !_textures.newTexture("Texture/UI/PNG/panel_question.png", "question",
			       sf::IntRect(0, 0, 100, 100))
      || !_textures.newTexture("Texture/UI/PNG/panel_sound_on.png", "sound_on",
			       sf::IntRect(0, 0, 100, 100))
      || !_textures.newTexture("Texture/UI/PNG/panel_sound_off.png", "sound_off",
			       sf::IntRect(0, 0, 100, 100))
      || !_textures.newTexture("Texture/UI/PNG/arrowBeige_right.png", "arrow_right",
			       sf::IntRect(0, 0, 22, 21))
      || !_textures.newTexture("Texture/UI/PNG/arrowBeige_left.png", "arrow_left",
			       sf::IntRect(0, 0, 22, 21))
      || !_textures.newTexture("Texture/UI/PNG/arrowBlue_right.png", "arrowblue_right",
			       sf::IntRect(0, 0, 22, 21))
      || !_textures.newTexture("Texture/UI/PNG/arrowBlue_left.png", "arrowblue_left",
			       sf::IntRect(0, 0, 22, 21))
      || !_textures.newTexture("Texture/UI/PNG/arrowBrown_right.png", "arrowbrown_right",
			       sf::IntRect(0, 0, 22, 21))
      || !_textures.newTexture("Texture/UI/PNG/arrowBrown_left.png", "arrowbrown_left",
			       sf::IntRect(0, 0, 22, 21))
      || !_textures.newTexture("Texture/UI/PNG/panel_beige.png", "question_panel",
			       sf::IntRect(0, 0, 100, 100))
      || !_textures.newTexture("Texture/UI/camera.png", "free_camera",
			       sf::IntRect(0, 0, 100, 100))
      || !_textures.newTexture("Texture/UI/camera_pikmin.png", "camera_pikmin",
			       sf::IntRect(0, 0, 100, 100))
      || !_textures.newTexture("Texture/UI/pikmin_info.png", "pikmin_info",
			       sf::IntRect(0, 0, 100, 100))
      || !_textures.newTexture("Texture/UI/next.png", "next_pikmin",
			       sf::IntRect(0, 0, 100, 100))
      || !_textures.newTexture("Texture/UI/previous.png", "previous_pikmin",
			       sf::IntRect(0, 0, 100, 100))
      || !_textures.newTexture("Texture/UI/time.png", "time_ui",
			       sf::IntRect(0, 0, 100, 100))
      || !_textures.newTexture("Texture/UI/play.png", "play",
			       sf::IntRect(0, 0, 100, 100))
      || !_textures.newTexture("Texture/UI/pause.png", "pause",
			       sf::IntRect(0, 0, 100, 100))
      || !_textures.newTexture("Texture/UI/double_speed.png", "double_speed",
			       sf::IntRect(0, 0, 100, 100))
      || !_textures.newTexture("Texture/UI/PNG/panel_blue.png", "inventory",
			       sf::IntRect(0, 0, 100, 100))
      || !_textures.newTexture("Texture/UI/PNG/panel_blue.png", "finish",
			       sf::IntRect(0, 0, 100, 100))
      || !_textures.newTexture("Texture/Ressources/Shit.png", "shit",
			       sf::IntRect(0, 0, 145, 43))
      || !_textures.newTexture("Texture/UI/info_team.png", "team_info",
			       sf::IntRect(0, 0, 100, 100))
      || !_textures.newTexture("Texture/Ressources/pikmin.png", "pikmin",
			       sf::IntRect(0, 0, 1156, 317))
      || !_textures.newTexture("Texture/UI/bot_orange.png", "bot_orange",
			       sf::IntRect(0, 0, 9, 18))
      || !_textures.newTexture("Texture/UI/mid_orange.png", "mid_orange",
			       sf::IntRect(0, 0, 18, 18))
      || !_textures.newTexture("Texture/UI/top_orange.png", "top_orange",
			       sf::IntRect(0, 0, 9, 18))
      || !_textures.newTexture("Texture/UI/mid_blank.png", "mid_blank",
			       sf::IntRect(0, 0, 18, 18))
      || !_textures.newTexture("Texture/UI/top_blank.png", "top_blank",
			       sf::IntRect(0, 0, 9, 18)))
    {
      throw MyError("Couldn't load a texture");
      return (NULL);
    }
  _textures.spriteLabel("panel")->scale(sf::Vector2f(4.5f, 3.0f));
  _textures.spriteLabel("info_panel")->scale(sf::Vector2f(0.5f, 0.5f));
  _textures.spriteLabel("question")->scale(sf::Vector2f(0.5f, 0.5f));
  _textures.spriteLabel("team_info")->scale(sf::Vector2f(0.5f, 0.5f));
  _textures.spriteLabel("sound_on")->scale(sf::Vector2f(0.5f, 0.5f));
  _textures.spriteLabel("sound_off")->scale(sf::Vector2f(0.5f, 0.5f));
  _textures.spriteLabel("free_camera")->scale(sf::Vector2f(0.5f, 0.5f));
  _textures.spriteLabel("camera_pikmin")->scale(sf::Vector2f(0.5f, 0.5f));
  _textures.spriteLabel("play")->scale(sf::Vector2f(0.5f, 0.5f));
  _textures.spriteLabel("pause")->scale(sf::Vector2f(0.5f, 0.5f));
  _textures.spriteLabel("double_speed")->scale(sf::Vector2f(0.5f, 0.5f));
  _textures.spriteLabel("pikmin_info")->scale(sf::Vector2f(0.5f, 0.5f));
  _textures.spriteLabel("next_pikmin")->scale(sf::Vector2f(0.5f, 0.5f));
  _textures.spriteLabel("previous_pikmin")->scale(sf::Vector2f(0.5f, 0.5f));
  _textures.spriteLabel("question_panel")->scale(sf::Vector2f(7.0f, 7.0f));
  _textures.spriteLabel("finish")->scale(sf::Vector2f(7.0f, 7.0f));
  _textures.spriteLabel("inventory")->scale(sf::Vector2f(4.0f, 2.0f));
  _textures.spriteLabel("egg")->scale(sf::Vector2f(0.25f, 0.25f));
  _textures.spriteLabel("time_ui")->scale(sf::Vector2f(0.5f, 0.5f));
  _world.setTexture(&_textures);
  if (_socket.send_socket((void *)"GRAPHIC\n", sizeof("GRAPHIC\n")) != sf::Socket::Done)
    {
      _socket.disconnect();
      return (false);
    }
  _sound.pauseChannel("ingame1");
  return (true);
}

void	Game::debugAnim()
{
  static int i = 0;
  if (i == 0)
    {
      _debug.initializeAnimation(*_textures.spriteLabel("pikmin"), WHITE, 50);
      i++;
    }
  _debug.playAnimation("right", sf::Vector2f(20, 40), _clock.getElapsedTime());
  _window->draw(*_debug.getSprite());
}

void	Game::handleWorldCommands()
{
  std::string temp;

  _mutex.lock();
  temp = _world.getLastDeque();
  if (_socket.send_socket((void *)temp.c_str(), sizeof(temp.c_str())) != Socket::SUCCESS)
    {
      _socket.disconnect();
      throw MyError("Couldn't send to server !");
      return;
    }
  _world.DepopDeque();
  _mutex.unlock();
}

void	Game::show()
{
  if (_world.getSizeDeque())
    handleWorldCommands();
  sf::Listener::setPosition(_view->getCenter().x, 0.f, _view->getCenter().y);
  _window->setView(*_view);
  _window->clear();
  drawBackground();
  drawUI();
  verifyCameraPikmin();
  drawEntities();
  drawBc();
  _world.update(_clock.getElapsedTime());
  _window->display();
}
