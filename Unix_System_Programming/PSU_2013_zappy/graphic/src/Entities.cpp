//
// Entities.cpp for zappy in /home/storm/zappy/zappy/src
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Wed Jul  2 17:50:46 2014 Julian Caille
// Last update Sun Jul 13 23:43:32 2014 Julian Caille
//

#include "Game.hpp"

void	Game::playSound(LivingEntity *entity, std::string const &label, int const &type,
			int const &i)
{
  if (i == 1)
    entity->getSound().resumeChannel(label.c_str());
  if (type != entity->getTypeCase())
    {
      entity->getSound().pauseChannel(entity->getLabelSound(entity->getTypeCase()).c_str());
      entity->getSound().resumeChannel(label.c_str());
      entity->setTypeCase(type);
    }
}

void	Game::verifyDestination(LivingEntity *entity, sf::Vector2f const &position,
				int const &status)
{
  int i;
  int	tempType;
  std::string	currentType;

  tempType = _map[entity->getPos().y * _world.getMapSize().x +
					   entity->getPos().x]->getType();
  currentType = entity->getLabelSound(tempType);
  i = entity->getCurrentFrame() + 1;
  entity->getSound().soundLabel("incant")->setPosition(position.x, 0, position.y);
  if (entity->getIncant())
    {
      if (entity->getSound().soundLabel("incant")->getStatus() != sf::Sound::Playing)
	entity->getSound().resumeChannel("incant");
    }
  else
    {
      if (entity->getSound().soundLabel("incant")->getStatus() == sf::Sound::Playing)
	entity->getSound().pauseChannel("incant");
    }
  if (status)
    {
      if (entity->length())
	{
	  entity->setCurrentFrame(i);
	  entity->getSound().soundLabel(currentType)->setPosition(position.x,
								  0, position.y);
	      playSound(entity,
			currentType,
			tempType, i);
	  if (i == 1)
	    {
	      if (entity->getPosDest().x == entity->getPos().x &&
		  entity->getPosDest().y == entity->getPos().y)
		{
		  entity->setCurrentFrame(0);
		  entity->arrived();
		  entity->getSound().pauseChannel(currentType.c_str());
		  return ;
		}
	    }
	  if (entity->getPosDest().z == N)
	    *entity -= sf::Vector2u(0, 4);
	  else if (entity->getPosDest().z == S)
	    *entity += sf::Vector2u(0, 4);
	  else if (entity->getPosDest().z == E)
	    *entity += sf::Vector2u(4, 0);
	  else if (entity->getPosDest().z == O)
	    *entity -= sf::Vector2u(4, 0);
	  if (i == 32)
	    {
	      entity->arrived();
	      entity->getSound().pauseChannel(currentType.c_str());
	      entity->setCurrentFrame(0);
	    }
	  entity->setDir(entity->getPosDest().z);
	  return ;
	}
      entity->setDir(0);
    }
}

void	Game::drawEntities()
{
  sf::Vector2f temp;
  unsigned int i;
  int		ret;

  i = -1;
  if (_entities.size() != 0)
    {
      while (++i != _entities.size())
	{
	  Animated *temp2 = _entities[i]->getAnim();
	  Animated *temp3 = _entities[i]->getAnimLevel();
	  Animated *temp4 = _entities[i]->getAnimIncant();

	  temp.x = (_entities[i]->getPos().x * 128) + _entities[i]->getPosRela().x;
	  temp.y = (_entities[i]->getPos().y * 128) + _entities[i]->getPosRela().y;
	  if (_entities[i]->getType() == SHIT)
	    {
	      temp2->playAnimation("shit", temp, _clock.getElapsedTime());
	      _window->draw(*temp2->getSprite());
	    }
	  else if (_entities[i]->getType() == EGG)
	    {
	      if (_entities[i]->getColor() == EGG_MATURE)
		temp2->playAnimation("egg", temp, _clock.getElapsedTime());
	      else
		temp2->playAnimation("egg_close", temp, _clock.getElapsedTime());
	      _window->draw(*temp2->getSprite());
	    }
	  else if (_entities[i]->getType() == AI)
	    {
	      if (_entities[i]->getDir() == 0 || _entities[i]->getDir() == 42)
		ret = temp2->playAnimation("static", temp, _clock.getElapsedTime());
	      else if (_entities[i]->getDir() == N)
		ret = temp2->playAnimation("backward", temp, _clock.getElapsedTime());
	      else if (_entities[i]->getDir() == S)
		ret = temp2->playAnimation("forward", temp, _clock.getElapsedTime());
	      else if (_entities[i]->getDir() == E)
		ret = temp2->playAnimation("right", temp, _clock.getElapsedTime());
	      else if (_entities[i]->getDir() == O)
		ret = temp2->playAnimation("left", temp, _clock.getElapsedTime());
	      verifyDestination(_entities[i], temp, ret);
	      if (_modeCamera)
		{
		  verifyCameraPikmin();
		  _window->setView(*_view);
		}
	      if (_entities[i]->getLvl() >= 2 && !_entities[i]->getIncant())
		{

		  temp3->playAnimation(_entities[i]->getNameLvl(_entities[i]->getLvl() - 2),
				       temp, _clock.getElapsedTime());
		  _window->draw(*temp3->getSprite());
		}
	      _window->draw(*temp2->getSprite());
	      if (_entities[i]->getIncant())
		{
		  temp4->playAnimation("incant",
				       sf::Vector2f(temp.x + 5, temp.y - 10), _clock.getElapsedTime());
		  _window->draw(*temp4->getSprite());
		}
	    }
	}
    }
}
