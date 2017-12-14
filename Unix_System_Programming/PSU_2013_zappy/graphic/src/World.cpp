//
// World.cpp for zappy in /home/couder_a/Depot/PSU/git/zappy
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Tue Jun 24 18:21:10 2014 Arthur Coudert
// Last update Sun Jul 13 21:16:22 2014 Arthur Coudert
//

#include "World.hh"
#include <iostream>

World::World(){
  if (!_sound.newChannel("./sound/death.ogg", "death"))
    throw MyError("Couldn't load sound !");
  _sound.pauseChannel("death");
  if (!_sound.newChannel("./sound/grass.ogg", "grass"))
    throw MyError("Couldn't load sound !");
  _sound.pauseChannel("grass");
  if (!_sound.newChannel("./sound/incant.ogg", "incant"))
    throw MyError("Couldn't load sound !");
  _sound.pauseChannel("incant");
  if (!_sound.newChannel("./sound/sand.ogg", "sand"))
    throw MyError("Couldn't load sound !");
  _sound.pauseChannel("sand");
  if (!_sound.newChannel("./sound/rock.ogg", "rock"))
    throw MyError("Couldn't load sound !");
  _sound.pauseChannel("rock");
  if (!_sound.newChannel("./sound/dirt.ogg", "dirt"))
    throw MyError("Couldn't load sound !");
  _sound.pauseChannel("dirt");
  if (!_sound.newChannel("./sound/take.ogg", "take"))
    throw MyError("Couldn't load sound !");
  _sound.pauseChannel("take");
  if (!_sound.newChannel("./sound/place.ogg", "place"))
    throw MyError("Couldn't load sound !");
  _sound.pauseChannel("place");
  if (!_sound.newChannel("./sound/mimimi.ogg", "mimimi"))
    throw MyError("Couldn't load sound !");

  _sound.soundLabel("death")->setMinDistance(100.0f);
  _sound.soundLabel("death")->setAttenuation(1.0f);
  _sound.soundLabel("take")->setMinDistance(100.0f);
  _sound.soundLabel("take")->setAttenuation(1.0f);
  _sound.soundLabel("place")->setMinDistance(100.0f);
  _sound.soundLabel("place")->setAttenuation(1.0f);

  _sound.soundLabel("grass")->setLoop(true);
  _sound.soundLabel("grass")->setMinDistance(100.0f);
  _sound.soundLabel("grass")->setAttenuation(1.0f);
  _sound.soundLabel("sand")->setLoop(true);
  _sound.soundLabel("sand")->setMinDistance(100.0f);
  _sound.soundLabel("sand")->setAttenuation(1.0f);
  _sound.soundLabel("dirt")->setLoop(true);
  _sound.soundLabel("dirt")->setMinDistance(100.0f);
  _sound.soundLabel("dirt")->setAttenuation(1.0f);
  _sound.soundLabel("rock")->setLoop(true);
  _sound.soundLabel("rock")->setMinDistance(100.0f);
  _sound.soundLabel("rock")->setAttenuation(1.0f);
  _sound.soundLabel("incant")->setLoop(true);
  _sound.soundLabel("incant")->setMinDistance(100.0f);
  _sound.soundLabel("incant")->setAttenuation(1.0f);

  _sound.soundLabel("mimimi")->setMinDistance(100.0f);
  _sound.soundLabel("mimimi")->setAttenuation(1.0f);

  _freq = -1;
  _finish = "";
  _gen = false;
  _nbgen = 0;
}

World::~World(){
  while (_map.size() != 0)
    {
      delete _map.back();
      _map.pop_back();
    }
  while (_team.size() != 0)
    {
      delete _team.back();
      _team.pop_back();
    }
  while (_entity.size() != 0)
    {
      delete _entity.back();
      _entity.pop_back();
    }
}

bool			World::getGen() const{
  return (_gen);
}

unsigned int		World::getNbGen() const{
  return (_nbgen);
}

const std::vector<Case*>	&World::getMap() const{
  return (_map);
}

std::vector<Team*>	World::getTeam() const{
  return (_team);
}

std::vector<LivingEntity*>	World::getEntity() const{
  return (_entity);
}

sf::Vector2u		World::getMapSize() const{
  return (_mapSize);
}

int			World::getFreq() const{
  return (_freq);
}

std::string		World::getFinish() const
{
  return (_finish);
}

void			World::setMapSize(const sf::Vector2u size)
{
  _mapSize = size;
}

Texture*		World::getTexture() const{
  return (_text);
}

void			World::setFinish(std::string const &finish)
{
  _finish = finish;
}

void			World::setTexture(Texture *text){
  _text = text;
}

std::list<BroadCast*>		World::getBc() const{
  return (_bc);
}

bool		World::parseEgg(const std::vector<std::string> &command)
{
  unsigned int i;
  unsigned int i2;
  unsigned int i3;
  std::string	teamName;
  sf::Vector2u	posRela;

  if (command[0] == "enw" && command.size() == 5)
    {
      for (i = 0; i < _entity.size(); i++)
      	{
      	  if (_entity[i]->getType() == EGG && _entity[i]->getId() == atoi(command[1].c_str()))
      	    return false;
      	}
      for (i2 = 0; i2 < _entity.size(); i2++)
	{
	  if (_entity[i2]->getType() == AI && _entity[i2]->getId() == atoi(command[2].c_str()))
	    {
	      teamName = _entity[i2]->getTeam();
	      posRela = sf::Vector2u(_entity[i2]->getPosRela().x, _entity[i2]->getPosRela().y);
	      for (i3 = 0; i3 < _team.size(); i3++)
		{
		  if (_team[i3]->getName() == teamName)
		    {
		      _entity.insert(_entity.begin(), new LivingEntity(_mapSize, atoi(command[1].c_str()), atoi(command[3].c_str()),
							 atoi(command[4].c_str()), N, 0, teamName, EGG,
								       _text, _sound));
		      *(_entity[0]) += posRela;
		      return (true);
		    }
		}
	    }
	}
    }
  else if ((command[0] == "ebo" || command[0] == "edi" || command[0] == "eht") && command.size() == 2)
    {
      for (i = 0; i < _entity.size(); i++)
	{
	  if (_entity[i]->getType() == EGG && _entity[i]->getId() == atoi(command[1].c_str()))
	    {
	      if (command[0] == "ebo")
		{
		  delete _entity[i];
		  _entity.erase(_entity.begin() + i);
		}
	      else if (command[0] == "edi")
		_entity[i]->setShit(_text);
	      else if (command[0] == "eht")
		_entity[i]->setMature(_text);
	      return (true);
	    }
	}
    }
  return (false);
}

bool		World::parseAi(const std::vector<std::string> &command){
  unsigned int i;
  unsigned int i2;

  if (command[0] == "pnw")
    {
      for (i = 0; i < _entity.size(); i++)
	{
	  if (_entity[i]->getType() == AI && _entity[i]->getId() == atoi(command[1].c_str()))
	    return false;
	}
      for (i2 = 0; i2 < _team.size(); i2++)
	{
	  if (_team[i2]->getName() == command[6])
	    {
	      _team[i2]->incNb();
	      _entity.push_back(new LivingEntity(_mapSize, atoi(command[1].c_str()), atoi(command[2].c_str()),
						 atoi(command[3].c_str()), atoi(command[4].c_str()),
						 atoi(command[5].c_str()), command[6], AI, _text, _sound,
						 _team[i2]->getColor()));
	      return true;
	    }
	  i++;
	}
    }
  else if (command[0] == "ppo" || command[0] == "plv" || command[0] == "pin" || command[0] == "pdi")
    {
      for (i = 0; i < _entity.size(); i++)
	{
	  if (_entity[i]->getType() == AI && _entity[i]->getId() == atoi(command[1].c_str()))
	    {
	      if (command[0] == "ppo" && command.size() == 5)
		{
		  _entity[i]->setPosDest(Vector3u(atoi(command[2].c_str()), atoi(command[3].c_str()),
						  atoi(command[4].c_str())));
		  return (true);
		}
	      else if (command[0] == "plv" && command.size() == 3)
		{
		  _entity[i]->setLvl(atoi(command[2].c_str()));
		  return (true);
		}
	      else if (command[0] == "pin" && command.size() == 11)
		{
		  _entity[i]->setInventory(command);
		  return (true);
		}
	      else if (command[0] == "pdi" && command.size() == 2)
		{
		  for (i2 = 0; i2 < _team.size(); i2++)
		    {
		      if (_team[i2]->getName() == _entity[i]->getTeam())
			{
			  sf::Vector2f temp;
			  temp.x = (_entity[i]->getPos().x * 128) + _entity[i]->getPosRela().x;
			  temp.y = (_entity[i]->getPos().y * 128) + _entity[i]->getPosRela().y;
			  _entity[i]->getSound().soundLabel("death")->setPosition(temp.x, 0,temp.y);
			  _entity[i]->getSound().resumeChannel("death");
			  _entity[i]->setShit(_text);
			  _team[i2]->decNb();
			  _request.push_back(*(new std::string("mct\n")));
			  return (true);
			}
		    }
		}
	    }
	}
    }
  else if (command[0] == "pic" && command.size() >= 5)
    {
      for (i = 0; i < _entity.size(); i++)
	{
	  if (_entity[i]->getType() == AI && _entity[i]->getId() == atoi(command[4].c_str()))
	    {
	      _entity[i]->setIncant(true);
	      return (true);
	    }
	}
    }
  else if (command[0] == "pie" && command.size() == 4)
    {
      for (i = 0; i < _entity.size(); i++)
	{
	  if (_entity[i]->getType() == AI
	      && _entity[i]->getPos().x == static_cast<unsigned int>(atoi(command[1].c_str()))
	      && _entity[i]->getPos().y == static_cast<unsigned int>(atoi(command[2].c_str()))
	      && _entity[i]->getIncant() == true)
	    {
	      _entity[i]->setIncant(false);
	      return (true);
	    }
	}
    }
  return (false);
}

void			World::parseCommand(const std::vector<std::string> &command)
{
  unsigned int i;

  if (command[0] == "msz" && command.size() == 3)
    {
      setMapSize(sf::Vector2u(atoi(command[1].c_str()), atoi(command[2].c_str())));
      if (_map.size() == 0)
	{
	  while (_map.size() != _mapSize.x * _mapSize.y)
	    _map.push_back(new Case());
	}
    }
  else if (command[0] == "sgt" && command.size() == 2 && _freq == -1)
    _freq = atoi(command[1].c_str());
  else if (command[0] == "bct" && command.size() == 10
	   && ((_mapSize.x * atoi(command[2].c_str())) + atoi(command[1].c_str())) < _map.size())
    {
      _nbgen++;
      if ((_mapSize.x -1) ==  static_cast<unsigned int>(atoi(command[1].c_str())) && (_mapSize.y -1) ==  static_cast<unsigned int>(atoi(command[2].c_str())))
      	_gen = true;
      if (_map[((_mapSize.x * atoi(command[2].c_str())) + atoi(command[1].c_str()))]->getType() == -1)
      	_map[((_mapSize.x * atoi(command[2].c_str())) + atoi(command[1].c_str()))]->Init(command, _mapSize);
      else
	_map[((_mapSize.x * atoi(command[2].c_str())) + atoi(command[1].c_str()))]->parseCommand(command);
    }
  else if (command[0] == "tna" && command.size() == 2)
    _team.push_back(new Team(command[1]));
  else if ((command[0] == "pdr" || command[0] == "pgt") && command.size() == 3)
    {
      for (i = 0; i < _entity.size(); i++)
	{
	  if (_entity[i]->getId() == atoi(command[1].c_str()) && _entity[i]->getType() == AI)
	    {
	      if (command[0] == "pdr")
	      	{
		  _entity[i]->getSound().resumeChannel("place");
		  _map[_entity[i]->getPos().x + _entity[i]->getPos().y * _mapSize.x]->pushNewItem(_entity[i]->getPosRela(), atoi(command[2].c_str()), 1);
		}
	      else
		{
		  _entity[i]->getSound().resumeChannel("take");
		    _map[_entity[i]->getPos().x + _entity[i]->getPos().y * _mapSize.x]->pushNewItem(_entity[i]->getPosRela(), atoi(command[2].c_str()), 2);
		}
	      break;
	    }
	}
    }
  else if (command[0] == "pbc" && command.size() >= 3)
    {
      for (i = 0; i < _entity.size(); i++)
	{
	  if (_entity[i]->getType() == AI && atoi(command[1].c_str()) == _entity[i]->getId())
	    {
	      sf::Vector2f temp;
	      temp.x = (_entity[i]->getPos().x * 128) + _entity[i]->getPosRela().x;
	      temp.y = (_entity[i]->getPos().y * 128) + _entity[i]->getPosRela().y;
	      _entity[i]->getSound().soundLabel("mimimi")->setPosition(temp.x, 0,temp.y);
	      _entity[i]->getSound().resumeChannel("mimimi");
	      _bc.push_back(new BroadCast(_entity[i]->getPos().x * 128 + _entity[i]->getPosRela().x
					  ,_entity[i]->getPos().y * 128 + _entity[i]->getPosRela().y
					  ,_entity[i]->getId()));
	      _bc.back()->initDest(_entity, _mapSize);
	    }

	}
    }
  else if (command[0][0] == 'e' || command[0][0] == 'p')
    {
      if (command[0][0] == 'e')
	parseEgg(command);
      else
	parseAi(command);
    }
  else if (command[0] == "seg" && command.size() == 2)
    _finish = command[1];
}

void			World::updateCase(int i_case){
  if (_map[i_case]->getRes().size() > 7)
    _map[i_case]->update();
}

void			World::update(sf::Time time){
  std::list<BroadCast*>::iterator	it;
  if (_bc.size() != 0)
    {
      for (it = _bc.begin(); it != _bc.end(); it++)
	{
	  (*it)->UpdateLine(time);
	  if ((*it)->getFinish() == true)
	    {
	      delete (*it);
	      it = _bc.erase(it);
	      it--;
	    }
	}
    }
}

const std::string &	World::getLastDeque() const{
  return(_request.front());
}

void			World::DepopDeque()
{
  _request.pop_front();
}

unsigned int		World::getSizeDeque() const{
  return (_request.size());
}
