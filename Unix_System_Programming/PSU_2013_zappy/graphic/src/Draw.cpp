//
// Draw.cpp for Draw in /home/storm/zappy/zappy/src
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Sun Jun 29 18:39:29 2014 Julian Caille
// Last update Sun Jul 13 23:50:03 2014 Julian Caille
//

#include "Game.hpp"
#include <boost/lexical_cast.hpp>

void	Game::drawItems(std::vector<Item*>  const &caseItem, int const &size,
			float const &posX, float const &posY)
{
  int	case_slot;

  case_slot = 0;
  while (case_slot < size)
    {
      drawCase(caseItem.at(case_slot),
	       caseItem.at(case_slot)->getType(),
	       posX, posY);
      case_slot++;
    }
  case_slot = 0;
}

void	Game::drawSelected(char const *label, float const &posX, float const &posY)
{
  _textures.spriteLabel(label)->setPosition(sf::Vector2f(posX,
							 posY));
  _window->draw(*_textures.spriteLabel(label));
}

void	Game::scaleSprites(int const &type, int const &nbElements, int const &mode)
{
  std::vector<std::string> temp;
  unsigned int i;

  i = -1;
  temp.push_back("meat");
  temp.push_back("linemate");
  temp.push_back("deraumere");
  temp.push_back("sibur");
  temp.push_back("mendiane");
  temp.push_back("phiras");
  temp.push_back("thystame");
  temp.push_back("egg");
  if (mode == 1)
    {
      if (nbElements > 1 && nbElements < 4)
	_textures.spriteLabel(temp[type].c_str())->setScale(1, 1);
      else if (nbElements >= 4)
	_textures.spriteLabel(temp[type].c_str())->setScale(1.20, 1.20);
      else
	_textures.spriteLabel(temp[type].c_str())->setScale(0.80, 0.80);
    }
  else
      while (++i < temp.size())
	_textures.spriteLabel(temp[i].c_str())->setScale(1, 1);
}

void	Game::drawCase(Item* const &item, int const &type, float const &posX, float const &posY)
{
  if (item->getNbRes() > 0)
    {
      scaleSprites(type, item->getNbRes(), 1);
      if (type == MEAT)
	drawSelected("meat", posX + item->getPosRela().x, posY + item->getPosRela().y);
      else if (type == LINEMATE)
	drawSelected("linemate", posX + item->getPosRela().x, posY + item->getPosRela().y);
      else if (type == DERAUMERE)
	drawSelected("deraumere", posX + item->getPosRela().x, posY + item->getPosRela().y);
      else if (type == SIBUR)
	drawSelected("sibur", posX + item->getPosRela().x, posY + item->getPosRela().y);
      else if (type == MENDIANE)
	drawSelected("mendiane", posX + item->getPosRela().x, posY + item->getPosRela().y);
      else if (type == PHIRAS)
	drawSelected("phiras", posX + item->getPosRela().x, posY + item->getPosRela().y);
      else if (type == THYSTAME)
	drawSelected("thystame", posX + item->getPosRela().x, posY + item->getPosRela().y);
      if (type == LINEMATE)
	drawSelected("linemate", posX + item->getPosRela().x, posY + item->getPosRela().y);
      scaleSprites(type, item->getNbRes(), 0);
    }
}

void	Game::drawLoader(unsigned int nbgen, unsigned int target){
  unsigned int	percent;
  static int	pts = 0;
  int		decalx;
  unsigned int	nb = 0;
  std::string	tmp;

  percent = 0;
  if (target != 0)
    {
      percent = ((nbgen * 100) / target);
      if (pts >= 0 && pts < 10)
	{
	  _window->draw(*_textures.spriteLabel("load1"));
	  tmp = "Loading     ";
	  pts++;
	}
      else if (pts >= 10 && pts < 20)
	{
	  _window->draw(*_textures.spriteLabel("load2"));
	  tmp = "Loading .   ";
	  pts++;
	}
      else if (pts >= 20 && pts < 30)
	{
	  _window->draw(*_textures.spriteLabel("load3"));
	  tmp = "Loading ..  ";
	  pts++;
	}
      else if (pts >= 30 && pts < 40)
	{
	  _window->draw(*_textures.spriteLabel("load4"));
	  tmp = "Loading ... ";
	  pts++;
	}
      if (pts >= 40)
	pts = 0;
    }
  tmp += boost::lexical_cast<std::string>(percent) + "%";
  _textures.spriteLabel("panel")->setPosition(sf::Vector2f(100, 600));
  _window->draw(*_textures.spriteLabel("panel"));
  _text.setPosition(380, 620);
  _text.setString(tmp);
  _window->draw(_text);
  _textures.spriteLabel("bot_orange")->setPosition(sf::Vector2f(220, 670));
  _window->draw(*_textures.spriteLabel("bot_orange"));
  decalx = 229;
  while (nb != 100)
    {
      if (nb < percent)
	{
	  _textures.spriteLabel("mid_orange")->setPosition(sf::Vector2f((decalx + nb * 6), 670));
	  _window->draw(*_textures.spriteLabel("mid_orange"));
	}
      else
	{
	  _textures.spriteLabel("mid_blank")->setPosition(sf::Vector2f((decalx + nb * 6), 670));
	  _window->draw(*_textures.spriteLabel("mid_blank"));
	}
      nb++;
    }
  _textures.spriteLabel("top_blank")->setPosition(sf::Vector2f((decalx + 100 * 6), 670));
  _window->draw(*_textures.spriteLabel("top_blank"));
  _textures.spriteLabel("top_orange")->setPosition(sf::Vector2f((decalx + percent * 6), 670));
  _window->draw(*_textures.spriteLabel("top_orange"));
}

void	Game::drawBackground()
{
  unsigned int slot;
  unsigned int i;
  unsigned int i2;
  float	posX;
  float	posY;
  sf::Vector2i _localPosition;

  i = -1;
  i2 = -1;
  slot = 0;
  posX = 0;
  posY = 0;
  if (_world.getGen() == false)
    drawLoader(_world.getNbGen(), _world.getMapSize().x * _world.getMapSize().y);
  if (_world.getMapSize().x > 0 && _world.getMapSize().y > 0 && _world.getMap().size() == (_world.getMapSize().x * _world.getMapSize().y) && _world.getGen() == true)
    {
      _map = _world.getMap();
      while (++i2 < _world.getMapSize().y)
	{
	  while (++i < _world.getMapSize().x)
	    {
	      if (posX + 128 >= _view->getCenter().x - 512
		  && posX - 128 <= _view->getCenter().x  - 512 + 1024
		  && posY +  128 >= _view->getCenter().y - 384
		  && posY - 128 <= _view->getCenter().y - 384 + 768)

		{
		  _localPosition = sf::Mouse::getPosition(*_window);
		  if (_localPosition.x + _view->getCenter().x - 512 >= posX &&
		      _localPosition.y + _view->getCenter().y - 384 >= posY &&
		      _localPosition.x + _view->getCenter().x - 512 <= posX + 128 &&
		      _localPosition.y + _view->getCenter().y - 384 <= posY + 128 &&
		      sf::Mouse::isButtonPressed(sf::Mouse::Left)
		      && notInUI(_localPosition))
		    {
		      _showInfoCase = true;
		      _caseSelected = slot;
		    }
		  if (_map.at(slot)->getType() == GRASS)
		    {
		      _textures.spriteLabel("grass")->setPosition(sf::Vector2f(posX,
									       posY));
		      _window->draw(*_textures.spriteLabel("grass"));
		    }
		  else if (_map.at(slot)->getType() == DIRT)
		    {
		      _textures.spriteLabel("dirt")->setPosition(sf::Vector2f(posX,
									      posY));
		      _window->draw(*_textures.spriteLabel("dirt"));
		    }
		  else if (_map.at(slot)->getType() == STONE)
		    {
		      _textures.spriteLabel("stone")->setPosition(sf::Vector2f(posX,
									       posY));
		      _window->draw(*_textures.spriteLabel("stone"));
		    }
		  else if (_map.at(slot)->getType() == SAND)
		    {
		      _textures.spriteLabel("sand")->setPosition(sf::Vector2f(posX,
									      posY));
		      _window->draw(*_textures.spriteLabel("sand"));
		    }
		  drawItems(_map.at(slot)->getRes(),
		  	    _map.at(slot)->getRes().size(), posX, posY);
		  _world.updateCase(slot);
		}
	      slot++;
	      posX += 128;
	    }
	  if (i2 + 1 < (_view->getCenter().y + 384) / 128)
	    i = -1;
	  posX = 0;
	  posY += 128;
	}
    }
}

void	Game::drawInventory()
{
  if (_entities.size() > 0)
    {
      if (_currentPikmin >= 0 && _currentPikmin < static_cast<int>(_entities.size()))
	if (_entities[_currentPikmin]->getType() == AI)
	  {
	    std::string temp;
	    LivingEntity *temp_entity = _entities[_currentPikmin];

	    temp = "pin " + boost::lexical_cast<std::string>(temp_entity->getId()) + "\n";
	    _mutex.lock();
	    if (_socket.send_socket((void *)temp.c_str(), sizeof(temp.c_str())) == Socket::ERROR)
	      {
		throw MyError("Couldn't find socket!");
		return;
	      }
	    _mutex.unlock();
	    _window->draw(*_textures.spriteLabel("inventory"));
	    _text.setColor(sf::Color::White);
	    _text.setPosition(_cameraX + 620, _cameraY + 360);
	    _text.setString("ID : " + boost::lexical_cast<std::string>(temp_entity->getId()));
	    _window->draw(_text);
	    _text.setPosition(_cameraX + 620, _cameraY + 390);
	    _text.setString("Team : " + temp_entity->getTeam());
	    _window->draw(_text);
	    _text.setPosition(_cameraX + 620, _cameraY + 420);
	    _text.setString("Level : "
			    + boost::lexical_cast<std::string>(temp_entity->getLvl()));
	    _window->draw(_text);
	    _text.setColor(sf::Color::Black);
	    _text.setPosition(_cameraX + 730, _cameraY + 450);
	    _text.setString("Inventory");
	    _window->draw(_text);
	    _textures.spriteLabel("meat")->setPosition(sf::Vector2f(_cameraX + 620,
								    _cameraY + 490));
	    _textures.spriteLabel("linemate")->setPosition(sf::Vector2f(_cameraX + 670,
									_cameraY + 490));
	    _textures.spriteLabel("deraumere")->setPosition(sf::Vector2f(_cameraX + 720,
									 _cameraY + 490));
	    _textures.spriteLabel("sibur")->setPosition(sf::Vector2f(_cameraX + 770,
								     _cameraY + 490));
	    _textures.spriteLabel("mendiane")->setPosition(sf::Vector2f(_cameraX + 820,
									_cameraY + 490));
	    _textures.spriteLabel("phiras")->setPosition(sf::Vector2f(_cameraX + 870,
								      _cameraY + 490));
	    _textures.spriteLabel("thystame")->setPosition(sf::Vector2f(_cameraX + 920,
									_cameraY + 490));
	    _window->draw(*_textures.spriteLabel("meat"));
	    _window->draw(*_textures.spriteLabel("linemate"));
	    _window->draw(*_textures.spriteLabel("deraumere"));
	    _window->draw(*_textures.spriteLabel("sibur"));
	    _window->draw(*_textures.spriteLabel("mendiane"));
	    _window->draw(*_textures.spriteLabel("phiras"));
	    _window->draw(*_textures.spriteLabel("thystame"));
	    _text.setColor(sf::Color::White);
	    CountInventory(temp_entity->getInventory());
	  }
    }
}

void	Game::calculatePikminPosTeam(Team *team)
{
  int	i;

  if (team->getNb() == 0)
    {
      _currentTeamPikmin[_currentTeam] = -2;
      return ;
    }
  if (_currentTeamPikmin[_currentTeam] < 0 ||
      _currentTeamPikmin[_currentTeam] >= static_cast<int>(_entities.size())
      || _entities[_currentTeamPikmin[_currentTeam]]->getTeam() != team->getName())
    {
      if (_currentTeamPikmin[_currentTeam] < 0)
	_currentTeamPikmin[_currentTeam] = 0;
      i = _currentTeamPikmin[_currentTeam];
      if (_currentTeamPikmin[_currentTeam] >= static_cast<int>(_entities.size()) ||
	  _currentTeamPikmin[_currentTeam] < 0)
	_currentTeamPikmin[_currentTeam] = -1;
      while (++_currentTeamPikmin[_currentTeam] != i)
	{
	  if (_currentTeamPikmin[_currentTeam] >= static_cast<int>(_entities.size()))
	    {
	      if (_currentTeamPikmin[_currentTeam] == i)
		break ;
	      _currentTeamPikmin[_currentTeam] = 0;
	    }
	  if (_entities[_currentTeamPikmin[_currentTeam]]->getTeam() ==
	      team->getName())
	    return ;
	}
    }
}

void	Game::infoOnPikminTeam(int const &pos)
{
  std::string temp;

  _text.setColor(sf::Color::Blue);
  if (pos != -2 && pos < static_cast<int>(_entities.size()))
    {
      temp = "Player ID : "
	+ boost::lexical_cast<std::string>(_entities[pos]->getId());
      _text.setPosition(_cameraX + 240, _cameraY + 368);
      _text.setString(temp);
      _window->draw(_text);
      temp = "Player Position : ("
	+ boost::lexical_cast<std::string>(_entities[pos]->getPos().x)
	+ " , "
	+ boost::lexical_cast<std::string>(_entities[pos]->getPos().y)
	+ ")";
      _text.setPosition(_cameraX + 240, _cameraY + 418);
      _text.setString(temp);
      _window->draw(_text);
      temp = "Player Level : "
	+ boost::lexical_cast<std::string>(_entities[pos]->getLvl());
      _text.setPosition(_cameraX + 240, _cameraY + 468);
      _text.setString(temp);
      _window->draw(_text);
    }
  if (pos == -2)
    {
      temp = "There is no player in this team";
      _text.setPosition(_cameraX + 180, _cameraY + 368);
      _text.setString(temp);
      _window->draw(_text);
      return ;
    }
  if (_entities.size() == 0)
    {
      _text.setPosition(_cameraX + 170, _cameraY + 468);
      _text.setString("No player is currently in-game");
      _window->draw(_text);
    }
  _text.setColor(sf::Color::White);
}

void	Game::infoOnTeams()
{
  std::vector<Team *>	temp;
  std::string		temp_string;
  static int initialize = 0;

  temp = _world.getTeam();
  if (temp.size() == 0)
    {
      _text.setColor(sf::Color::Black);
      _text.setPosition(_cameraX + 120, _cameraY + 368);
      _text.setString("No team is currently in-game");
      _window->draw(_text);
    }
  else
    {
      if (initialize == 0)
	{
	  unsigned int i;

	  for (i = 0; i != temp.size(); i++)
	    _currentTeamPikmin.push_back(-2);
	  initialize++;
	}
      if (_currentTeam >= static_cast<int>(temp.size()))
	_currentTeam = 0;
      else if (_currentTeam < 0)
	_currentTeam = temp.size() - 1;
      _text.setColor(sf::Color::Black);
      _text.setCharacterSize(50);
      _text.setPosition(_cameraX + 300, _cameraY + 80);
      temp_string = temp[_currentTeam]->getName();
      if (temp_string.length() > 15)
	{
	  temp_string.resize(15);
	  _text.setString(temp_string + "...");
	}
      else
	_text.setString(temp_string);
      _window->draw(_text);
      _text.setColor(sf::Color::White);
      _text.setCharacterSize(30);
      _text.setPosition(_cameraX + 300, _cameraY + 180);
      temp_string = "Player in the team : "
	+ boost::lexical_cast<std::string>(temp[_currentTeam]->getNb());
      _text.setString(temp_string);
      _window->draw(_text);
      calculatePikminPosTeam(temp[_currentTeam]);
      infoOnPikminTeam(_currentTeamPikmin[_currentTeam]);
    }
}

void	Game::drawUI()
{
  if (_world.getGen() == false)
    return ;
  _textures.spriteLabel("info_panel")->setPosition(sf::Vector2f(_cameraX + 950,
								_cameraY + 10));
  _textures.spriteLabel("sound_on")->setPosition(sf::Vector2f(_cameraX + 950,
							      _cameraY + 60));
  _textures.spriteLabel("sound_off")->setPosition(sf::Vector2f(_cameraX + 950,
							       _cameraY + 60));
  _textures.spriteLabel("question")->setPosition(sf::Vector2f(_cameraX + 950,
							      _cameraY + 110));
  _textures.spriteLabel("free_camera")->setPosition(sf::Vector2f(_cameraX + 950,
							      _cameraY + 160));
  _textures.spriteLabel("camera_pikmin")->setPosition(sf::Vector2f(_cameraX + 950,
							      _cameraY + 160));
  _textures.spriteLabel("time_ui")->setPosition(sf::Vector2f(_cameraX + 950,
							      _cameraY + 210));
  _textures.spriteLabel("team_info")->setPosition(sf::Vector2f(_cameraX + 950,
							      _cameraY + 260));
  _textures.spriteLabel("double_speed")->setPosition(sf::Vector2f(_cameraX + 900,
							      _cameraY + 210));
  _textures.spriteLabel("pause")->setPosition(sf::Vector2f(_cameraX + 850,
							   _cameraY + 210));
  _textures.spriteLabel("play")->setPosition(sf::Vector2f(_cameraX + 800,
							   _cameraY + 210));
  _textures.spriteLabel("arrow_right")->setPosition(sf::Vector2f(_cameraX + 1000,
								_cameraY + 10));
  _textures.spriteLabel("arrow_left")->setPosition(sf::Vector2f(_cameraX + 1000,
								_cameraY + 10));
  _textures.spriteLabel("arrowblue_right")->setPosition(sf::Vector2f(_cameraX + 770,
								_cameraY + 100));
  _textures.spriteLabel("arrowblue_left")->setPosition(sf::Vector2f(_cameraX + 200,
								_cameraY + 100));
  _textures.spriteLabel("arrowbrown_right")->setPosition(sf::Vector2f(_cameraX + 770,
								_cameraY + 400));
  _textures.spriteLabel("arrowbrown_left")->setPosition(sf::Vector2f(_cameraX + 200,
								_cameraY + 400));
  _textures.spriteLabel("question_panel")->setPosition(sf::Vector2f(_cameraX + 150,
								    _cameraY + 30));
  _textures.spriteLabel("pikmin_info")->setPosition(sf::Vector2f(_cameraX + 950,
								 _cameraY + 600));
  _textures.spriteLabel("next_pikmin")->setPosition(sf::Vector2f(_cameraX + 950,
								 _cameraY + 650));
  _textures.spriteLabel("previous_pikmin")->setPosition(sf::Vector2f(_cameraX + 950,
								 _cameraY + 700));
  _textures.spriteLabel("inventory")->setPosition(sf::Vector2f(_cameraX + 600,
								 _cameraY + 360));
  if (_showInfoCase && !_modeCamera)
    {
      _textures.spriteLabel("panel")->setPosition(sf::Vector2f(_cameraX + 100,
							       _cameraY + 600));
      _window->draw(*_textures.spriteLabel("panel"));
      _text.setColor(sf::Color::White);
      _text.setPosition(_cameraX + 120, _cameraY + 620);
      _text.setString("Case :");
      _window->draw(_text);

      _textures.spriteLabel("meat")->setPosition(sf::Vector2f(_cameraX + 150,
							       _cameraY + 660));
      _textures.spriteLabel("linemate")->setPosition(sf::Vector2f(_cameraX + 200,
							       _cameraY + 660));
      _textures.spriteLabel("deraumere")->setPosition(sf::Vector2f(_cameraX + 250,
							       _cameraY + 660));
      _textures.spriteLabel("sibur")->setPosition(sf::Vector2f(_cameraX + 300,
							       _cameraY + 660));
      _textures.spriteLabel("mendiane")->setPosition(sf::Vector2f(_cameraX + 350,
							       _cameraY + 660));
      _textures.spriteLabel("phiras")->setPosition(sf::Vector2f(_cameraX + 400,
							       _cameraY + 660));
      _textures.spriteLabel("thystame")->setPosition(sf::Vector2f(_cameraX + 450,
							       _cameraY + 660));
      _textures.spriteLabel("egg")->setPosition(sf::Vector2f(_cameraX + 500,
							       _cameraY + 650));
      _window->draw(*_textures.spriteLabel("meat"));
      _window->draw(*_textures.spriteLabel("linemate"));
      _window->draw(*_textures.spriteLabel("deraumere"));
      _window->draw(*_textures.spriteLabel("sibur"));
      _window->draw(*_textures.spriteLabel("mendiane"));
      _window->draw(*_textures.spriteLabel("phiras"));
      _window->draw(*_textures.spriteLabel("thystame"));
      if (_caseSelected == -1)
	{
	  _text.setPosition(_cameraX + 215, _cameraY + 620);
	  _text.setString("No case selected");
	  _window->draw(_text);
	}
      else
  	{
  	  sf::Vector2u temp = _map.at(_caseSelected)->getPos();
  	  std::string temp2 = boost::lexical_cast<std::string>(temp.x) +
  	    " ; "  + boost::lexical_cast<std::string>(temp.y);
  	  _text.setPosition(_cameraX + 215, _cameraY + 620);
  	  _text.setString(temp2);
  	  _window->draw(_text);
  	  CountItems(_map.at(_caseSelected)->getRes());
  	}
    }
  if (_showInventory && _modeCamera)
    drawInventory();
  if (_displayQuestion && !_modeCamera)
    {
      _window->draw(*_textures.spriteLabel("question_panel"));
      _text.setPosition(_cameraX + 420, _cameraY + 90);
      _text.setString("Help Menu");
      _window->draw(_text);

      _text.setPosition(_cameraX + 200, _cameraY + 130);
      _text.setString("Shortcuts :");
      _window->draw(_text);

      _text.setPosition(_cameraX + 220, _cameraY + 160);
      _text.setString("i : show/hide case informations");
      _window->draw(_text);

      _text.setPosition(_cameraX + 220, _cameraY + 190);
      _text.setString("h : show/hide help menu");
      _window->draw(_text);

      _text.setPosition(_cameraX + 220, _cameraY + 220);
      _text.setString("s : enable/disable sound");
      _window->draw(_text);

      _text.setPosition(_cameraX + 220, _cameraY + 250);
      _text.setString("g : show/hide gui");
      _window->draw(_text);

      _text.setPosition(_cameraX + 220, _cameraY + 280);
      _text.setString("b : show/hide broadcast lines");
      _window->draw(_text);

      _text.setPosition(_cameraX + 220, _cameraY + 310);
      _text.setString("t : show/hide time gui");
      _window->draw(_text);

      _text.setPosition(_cameraX + 220, _cameraY + 340);
      _text.setString("r : show/hide team gui");
      _window->draw(_text);

      _text.setPosition(_cameraX + 220, _cameraY + 370);
      _text.setString("c : change camera mode free/pikmin");
      _window->draw(_text);

      _text.setPosition(_cameraX + 200, _cameraY + 410);
      _text.setString("On pikmin camera :");
      _window->draw(_text);

      _text.setPosition(_cameraX + 220, _cameraY + 440);
      _text.setString("Tab : show/hide pikmin's inventory");
      _window->draw(_text);

      _text.setPosition(_cameraX + 220, _cameraY + 470);
      _text.setString("n : change to the next pikmin");
      _window->draw(_text);

      _text.setPosition(_cameraX + 220, _cameraY + 500);
      _text.setString("p : change to the previous pikmin");
      _window->draw(_text);

      _text.setPosition(_cameraX + 200, _cameraY + 540);
      _text.setString("On team gui :");
      _window->draw(_text);

      _text.setPosition(_cameraX + 220, _cameraY + 570);
      _text.setString("n : change to the next team");
      _window->draw(_text);

      _text.setPosition(_cameraX + 220, _cameraY + 600);
      _text.setString("p : change to the previous team");
      _window->draw(_text);
    }
  if (_displayUI && !_modeCamera)
    {
      _window->draw(*_textures.spriteLabel("info_panel"));
      _window->draw(*_textures.spriteLabel("question"));
      _window->draw(*_textures.spriteLabel("arrow_right"));
      if (_soundOn)
	_window->draw(*_textures.spriteLabel("sound_on"));
      else
	_window->draw(*_textures.spriteLabel("sound_off"));
      if (_modeCamera)
	_window->draw(*_textures.spriteLabel("free_camera"));
      else
	_window->draw(*_textures.spriteLabel("camera_pikmin"));
      _window->draw(*_textures.spriteLabel("time_ui"));
      _window->draw(*_textures.spriteLabel("team_info"));
    }
  else
    if (!_modeCamera)
      _window->draw(*_textures.spriteLabel("arrow_left"));
  if (_modeCamera)
    {
      _window->draw(*_textures.spriteLabel("pikmin_info"));
      _window->draw(*_textures.spriteLabel("next_pikmin"));
      _window->draw(*_textures.spriteLabel("previous_pikmin"));
    }
  if (_timeUI && _displayUI && !_modeCamera)
    {
      _window->draw(*_textures.spriteLabel("play"));
      _window->draw(*_textures.spriteLabel("pause"));
      _window->draw(*_textures.spriteLabel("double_speed"));
    }
  if (_infoTeam && !_modeCamera)
    {
      _window->draw(*_textures.spriteLabel("question_panel"));
      _window->draw(*_textures.spriteLabel("arrowblue_right"));
      _window->draw(*_textures.spriteLabel("arrowblue_left"));
      _window->draw(*_textures.spriteLabel("arrowbrown_right"));
      _window->draw(*_textures.spriteLabel("arrowbrown_left"));
      infoOnTeams();
    }
}

void	Game::drawBc(){
  std::list<BroadCast*>			bc;
  std::list<BroadCast*>::iterator	it;
  std::vector<Line*>			lines;
  std::vector<sf::VertexArray>		line;
  unsigned int				i;
  unsigned int				i2;

  bc = _world.getBc();
  if (bc.size() != 0)
    {
      for (it = bc.begin(); it != bc.end(); it++)
  	{
	  _textures.spriteLabel("talk")->setPosition(sf::Vector2f((*it)->getPos().x + 10,
								  (*it)->getPos().y - 32));
	  _window->draw(*_textures.spriteLabel("talk"));
	  if (_mask == false)
	    {
	      i = 0;
	      lines = (*it)->getLines();
	      for (; i != lines.size(); i++)
		{
		  line = lines[i]->getLines();
		  i2 = 0;
		  for (; i2 != line.size(); i2++)
		    _window->draw(line[i2]);
		}
	    }
  	}
    }
}
