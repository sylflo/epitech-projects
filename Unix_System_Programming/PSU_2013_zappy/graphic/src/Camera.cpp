//
// Camera.cpp for zappy in /home/storm/zappy/zappy/src
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Sun Jun 29 18:41:49 2014 Julian Caille
// Last update Sun Jul 13 23:50:32 2014 Julian Caille
//

#include "Game.hpp"

void		Game::moveCamera(int direction)
{
  if (direction == Game::RIGHT)
    {
      if (_cameraX < (128 * _world.getMapSize().x) - 1024)
	{
	  _cameraX += 32;
	  _view->move(32, 0);
	}
    }
  else if (direction == Game::LEFT)
    {
      if (_cameraX  > 0)
	{
	  _cameraX -= 32;
	  _view->move(-32, 0);
	}
    }
  else if (direction == Game::UP)
    {
      if (_cameraY  > 0)
	{
	  _cameraY -= 32;
	  _view->move(0, -32);
	}
    }
  else if (direction == Game::DOWN)
    {
      if (_cameraY  < (128 * _world.getMapSize().y) - 768)
	{
	  _cameraY += 32;
	  _view->move(0, 32);
	}
    }
}

void		Game::zoomCamera(int status)
{
  if (status == Game::ZOOM_OUT)
    {
      if (_zoom < 2)
	{
	  _zoom++;
	  _view->zoom(2.0f);
	}
    }
  else
    {
      if (_zoom > 0)
	{
	  _zoom--;
	  _view->zoom(0.5f);
	}
    }
}

void	Game::verifyCameraPikmin()
{
  _entities = _world.getEntity();
  if (_modeCamera)
    {
      if (_entities.size() != 0)
	{
	  if (_currentPikmin >= static_cast<int>(_entities.size()))
	    _currentPikmin = 0;
	  if (_currentPikmin < 0)
	    _currentPikmin = _entities.size() - 1;
	  if (_entities[_currentPikmin]->getType() != AI)
	    {
	      unsigned int i2 = -1;

	      while (++i2 != _entities.size())
		if (_entities[i2]->getType() == AI)
		  {
		    _currentPikmin = i2;
		    break;
		  }
	    }
	  if (_currentPikmin < static_cast<int>(_entities.size()))
	    {
	      if (_entities[_currentPikmin]->getType() == AI)
		{
		  sf::Vector2f temp;
		  temp.x = (_entities[_currentPikmin]->getPos().x * 128)
		    + _entities[_currentPikmin]->getPosRela().x;
		  temp.y = (_entities[_currentPikmin]->getPos().y * 128)
		    + _entities[_currentPikmin]->getPosRela().y;
		  _cameraX = (unsigned int)temp.x - 512;
		  _cameraY = (unsigned int)temp.y - 384;
		  _view->setCenter(sf::Vector2f(temp.x,temp.y));
		}
	    }
	}
    }
}
