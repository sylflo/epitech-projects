//
// Events.cpp for zappy in /home/storm/zappy/zappy/src
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Sun Jun 29 18:42:51 2014 Julian Caille
// Last update Sun Jul 13 23:49:41 2014 Julian Caille
//

#include "Game.hpp"

bool		Game::notInUI(sf::Vector2i _localPosition)
{
  if (_localPosition.x >= 1000 && _localPosition.x <= 1000 + 20 &&
      _localPosition.y >= 10 && _localPosition.y <= 10 + 20)
    return (false);
  if (_displayUI)
    if ((_localPosition.x >= 960 && _localPosition.x <= 960 + 45 &&
	 _localPosition.y >= 10 && _localPosition.y <= 10 + 50)
	||
	(_localPosition.x >= 960 && _localPosition.x <= 960 + 45 &&
	 _localPosition.y >= 50 && _localPosition.y <= 60 + 50)
	||
	(_localPosition.x >= 960 && _localPosition.x <= 960 + 45 &&
	 _localPosition.y >= 110 && _localPosition.y <= 110 + 50)
	||
	(_localPosition.x >= 960 && _localPosition.x <= 960 + 45 &&
	 _localPosition.y >= 160 && _localPosition.y <= 160 + 50)
	||
	(_localPosition.x >= 960 && _localPosition.x <= 960 + 45 &&
	 _localPosition.y >= 210 && _localPosition.y <= 210 + 50)
	||
	(_localPosition.x >= 960 && _localPosition.x <= 960 + 45 &&
	 _localPosition.y >= 260 && _localPosition.y <= 260 + 50)
	)
      return (false);
  if (_modeCamera)
    if(	(_localPosition.x >= 960 && _localPosition.x <= 960 + 45 &&
	 _localPosition.y >= 600 && _localPosition.y <= 600 + 50)
	||
	(_localPosition.x >= 960 && _localPosition.x <= 960 + 45 &&
	 _localPosition.y >= 650 && _localPosition.y <= 650 + 50)
	||
	(_localPosition.x >= 960 && _localPosition.x <= 960 + 45 &&
	 _localPosition.y >= 700 && _localPosition.y <= 700 + 50)
	)
      return (false);
  if (_timeUI)
    if ((_localPosition.x >= 900 && _localPosition.x <= 900 + 50 &&
	 _localPosition.y >= 210 && _localPosition.y <= 210 + 50)
	||
	(_localPosition.x >= 850 && _localPosition.x <= 850 + 50 &&
	 _localPosition.y >= 210 && _localPosition.y <= 210 + 50)
	||
	(_localPosition.x >= 800 && _localPosition.x <= 800 + 50 &&
	 _localPosition.y >= 210 && _localPosition.y <= 210 + 50)
	)
      return (false);
  if (_showInfoCase)
    if (_localPosition.x >= 100 && _localPosition.x <= 960 + 855 &&
	 _localPosition.y >= 600 && _localPosition.y <= 600 + 135)
      return (false);
  if  (_displayQuestion || _infoTeam)
    if (_localPosition.x >= 150 && _localPosition.x <= 960 + 700 &&
	_localPosition.y >= 30 && _localPosition.y <= 600 + 700)
      return (false);
  return (true);
}

void		Game::readMouse()
{
  sf::Vector2i _localPosition = sf::Mouse::getPosition(*_window);
  if (_localPosition.x >= 950 && _localPosition.x <= 950 + 45 &&
      _localPosition.y >= 10 && _localPosition.y <= 10 + 50 &&
      sf::Mouse::isButtonPressed(sf::Mouse::Left) && _displayUI)
    {
      usleep(100000);
      _showInfoCase = !_showInfoCase;
      return ;
    }
  if (_localPosition.x >= 950 && _localPosition.x <= 950 + 45 &&
      _localPosition.y >= 110 && _localPosition.y <= 110 + 50 &&
      sf::Mouse::isButtonPressed(sf::Mouse::Left) && _displayUI)
    {
      usleep(100000);
      _displayQuestion = !_displayQuestion;
      return ;
    }
  if (_localPosition.x >= 950 && _localPosition.x <= 950 + 45 &&
      _localPosition.y >= 160 && _localPosition.y <= 160 + 50 &&
      sf::Mouse::isButtonPressed(sf::Mouse::Left) && _displayUI)
    {
      usleep(100000);
      _modeCamera = !_modeCamera;
      if (!_modeCamera)
	{
	  _view->setCenter(sf::Vector2f(512, 384));
	  _cameraX = 0;
	  _cameraY = 0;
	}
      return ;
    }
  if (_localPosition.x >= 950 && _localPosition.x <= 950 + 45 &&
      _localPosition.y >= 210 && _localPosition.y <= 210 + 50 &&
      sf::Mouse::isButtonPressed(sf::Mouse::Left) && _displayUI)
    {
      usleep(100000);
      _timeUI = !_timeUI;
      return ;
    }
  if (_localPosition.x >= 950 && _localPosition.x <= 950 + 45 &&
      _localPosition.y >= 260 && _localPosition.y <= 260 + 50 &&
      sf::Mouse::isButtonPressed(sf::Mouse::Left) && _displayUI)
    {
      usleep(100000);
      _infoTeam = !_infoTeam;
      return ;
    }
  if (_localPosition.x >= 900 && _localPosition.x <= 900 + 45 &&
      _localPosition.y >= 210 && _localPosition.y <= 210 + 50 &&
      sf::Mouse::isButtonPressed(sf::Mouse::Left) && _timeUI)
    {
      usleep(100000);
      changeTime(_world.getFreq() * 2);
      return ;
    }
  if (_localPosition.x >= 850 && _localPosition.x <= 850 + 45 &&
      _localPosition.y >= 210 && _localPosition.y <= 210 + 50 &&
      sf::Mouse::isButtonPressed(sf::Mouse::Left) && _timeUI)
    {
      usleep(100000);
      changeTime(1);
      return ;
    }
  if (_localPosition.x >= 800 && _localPosition.x <= 800 + 45 &&
      _localPosition.y >= 210 && _localPosition.y <= 210 + 50 &&
      sf::Mouse::isButtonPressed(sf::Mouse::Left) && _timeUI)
    {
      usleep(100000);
      changeTime(_world.getFreq());
      return ;
    }
  if (_localPosition.x >= 950 && _localPosition.x <= 950 + 45 &&
      _localPosition.y >= 60 && _localPosition.y <= 60 + 50 &&
      sf::Mouse::isButtonPressed(sf::Mouse::Left) && _displayUI)
    {
      usleep(100000);
      if (_soundOn)
	_sound.pauseChannel("ingame1");
      else
	_sound.resumeChannel("ingame1");
      _soundOn = !_soundOn;
      return ;
    }
  if (_localPosition.x >= 950 && _localPosition.x <= 950 + 45 &&
      _localPosition.y >= 600 && _localPosition.y <= 600 + 50 &&
      sf::Mouse::isButtonPressed(sf::Mouse::Left) && _modeCamera)
    {
      usleep(100000);
      _showInventory = !_showInventory;
    }
  if (_localPosition.x >= 950 && _localPosition.x <= 950 + 45 &&
      _localPosition.y >= 650 && _localPosition.y <= 650 + 50 &&
      sf::Mouse::isButtonPressed(sf::Mouse::Left) && _modeCamera)
    {
      usleep(100000);
      _currentPikmin++;
    }
  if (_localPosition.x >= 770 && _localPosition.x <= 770 + 25 &&
      _localPosition.y >= 100 && _localPosition.y <= 100 + 25 &&
      sf::Mouse::isButtonPressed(sf::Mouse::Left) && _infoTeam)
    {
      usleep(100000);
      _currentTeam++;
    }
  if (_localPosition.x >= 200 && _localPosition.x <= 200 + 25 &&
      _localPosition.y >= 100 && _localPosition.y <= 100 + 25 &&
      sf::Mouse::isButtonPressed(sf::Mouse::Left) && _infoTeam)
    {
      usleep(100000);
      _currentTeam--;
    }
  if (_localPosition.x >= 770 && _localPosition.x <= 770 + 25 &&
      _localPosition.y >= 400 && _localPosition.y <= 400 + 25 &&
      sf::Mouse::isButtonPressed(sf::Mouse::Left) && _infoTeam)
    {
      usleep(100000);
      _currentTeamPikmin[_currentTeam]++;
    }
  if (_localPosition.x >= 200 && _localPosition.x <= 200 + 25 &&
      _localPosition.y >= 400 && _localPosition.y <= 400 + 25 &&
      sf::Mouse::isButtonPressed(sf::Mouse::Left) && _infoTeam)
    {
      usleep(100000);
      _currentTeamPikmin[_currentTeam]--;
    }
  if (_localPosition.x >= 950 && _localPosition.x <= 950 + 45 &&
      _localPosition.y >= 700 && _localPosition.y <= 700 + 50 &&
      sf::Mouse::isButtonPressed(sf::Mouse::Left) && _modeCamera)
    {
      usleep(100000);
      _currentPikmin--;
    }
  if (_localPosition.x >= 1000 && _localPosition.x <= 1000 + 20 &&
      _localPosition.y >= 10 && _localPosition.y <= 10 + 20 &&
      sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
      usleep(100000);
      _displayUI = !_displayUI;
      return ;
    }
}

void		Game::shortcutsUI()
{
  if (((_event.type == sf::Event::KeyPressed) &&
       (_event.key.code == sf::Keyboard::I)))
    _showInfoCase = !_showInfoCase;
  if (((_event.type == sf::Event::KeyPressed) &&
       (_event.key.code == sf::Keyboard::B)))
    _mask = !_mask;
  if (((_event.type == sf::Event::KeyPressed) &&
       (_event.key.code == sf::Keyboard::H)))
    _displayQuestion = !_displayQuestion;
  if (((_event.type == sf::Event::KeyPressed) &&
       (_event.key.code == sf::Keyboard::C)))
    {
      _modeCamera = !_modeCamera;
      if (!_modeCamera)
	{
	  _view->setCenter(sf::Vector2f(512, 384));
	  _cameraX = 0;
	  _cameraY = 0;
	}
    }
  if (((_event.type == sf::Event::KeyPressed) &&
       (_event.key.code == sf::Keyboard::T)))
    _timeUI = !_timeUI;
  if (((_event.type == sf::Event::KeyPressed) &&
       (_event.key.code == sf::Keyboard::R)))
    _infoTeam = !_infoTeam;
  if (((_event.type == sf::Event::KeyPressed) &&
       (_event.key.code == sf::Keyboard::F1)))
    changeTime(_world.getFreq());
  if (((_event.type == sf::Event::KeyPressed) &&
       (_event.key.code == sf::Keyboard::F2)))
    changeTime(1);
  if (((_event.type == sf::Event::KeyPressed) &&
       (_event.key.code == sf::Keyboard::F3)))
    changeTime(_world.getFreq() * 2);
  if (((_event.type == sf::Event::KeyPressed) &&
       (_event.key.code == sf::Keyboard::S)))
    {
      if (_soundOn)
	_sound.pauseChannel("ingame1");
      else
	_sound.resumeChannel("ingame1");
      _soundOn = !_soundOn;
    }
  if (((_event.type == sf::Event::KeyPressed) &&
       (_event.key.code == sf::Keyboard::G)))
    _displayUI = !_displayUI;
  if (((_event.type == sf::Event::KeyPressed) &&
       (_event.key.code == sf::Keyboard::Tab)) &&
      _modeCamera)
    _showInventory = !_showInventory;
  if (((_event.type == sf::Event::KeyPressed) &&
       (_event.key.code == sf::Keyboard::N)))
    {
      if (_modeCamera)
	_currentPikmin++;
      else if (!_modeCamera && _infoTeam)
	_currentTeam++;
    }
  if (((_event.type == sf::Event::KeyPressed) &&
       (_event.key.code == sf::Keyboard::P)))
    {
      if (_modeCamera)
	_currentPikmin--;
      else if (!_modeCamera && _infoTeam)
	_currentTeam--;
    }
}

void		Game::keyCamera()
{
  if (!_modeCamera)
    {
      if (((_event.type == sf::Event::KeyPressed) &&
	   (_event.key.code == sf::Keyboard::Right)))
	moveCamera(Game::RIGHT);
      if (((_event.type == sf::Event::KeyPressed) &&
	   (_event.key.code == sf::Keyboard::Left)))
	moveCamera(Game::LEFT);
      if (((_event.type == sf::Event::KeyPressed) &&
	   (_event.key.code == sf::Keyboard::Up)))
	moveCamera(Game::UP);
      if (((_event.type == sf::Event::KeyPressed) &&
	   (_event.key.code == sf::Keyboard::Down)))
	moveCamera(Game::DOWN);
    }
  if (((_event.type == sf::Event::KeyPressed) &&
       (_event.key.code == sf::Keyboard::Add)))
    zoomCamera(Game::ZOOM_ON);
  if (((_event.type == sf::Event::KeyPressed) &&
       (_event.key.code == sf::Keyboard::Subtract)))
    zoomCamera(Game::ZOOM_OUT);
}

void		Game::finishDisplay()
{
  std::string	temp;

  temp = _world.getFinish();
  _textures.spriteLabel("finish")->setPosition(sf::Vector2f(_cameraX + 150,
							    _cameraY + 30));
  _window->draw(*_textures.spriteLabel("finish"));
  _text.setColor(sf::Color::White);
  _text.setCharacterSize(35);
  _text.setPosition(_cameraX + 170, _cameraY + 320);
  if (temp.size() > 15)
    {
      temp.resize(15);
      temp += "...";
    }
  _text.setString("La team " + temp + " a gagne!");
  _window->draw(_text);
  _window->display();
  usleep(5000000);
}

std::string	Game::events()
{
  if (_window->isOpen())
    {
      if (_window->pollEvent(_event))
	{
	  if (_event.type == sf::Event::Closed ||
	      ((_event.type == sf::Event::KeyPressed) &&
	       (_event.key.code == sf::Keyboard::Escape)))
	    {
	      _window->close();
	      _socket.disconnect();
	      return ("quit");
	    }
	  if ((_event.type == sf::Event::KeyPressed) &&
	      (_event.key.code == sf::Keyboard::BackSpace))
	    {
	      checkClosedSound();
	      return ("new_menu");
	    }
	  shortcutsUI();
	  keyCamera();
	}
      if (_world.getFinish().size() != 0)
	{
	  checkClosedSound();
	  finishDisplay();
	  return ("new_game");
	}
      readMouse();
      return ("continue");
    }
  return ("quit");
}
