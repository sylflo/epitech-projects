//
// CheckSound.cpp for zappy in /home/storm/zappy/zappy/src
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Sat Jul 12 19:07:39 2014 Julian Caille
// Last update Sun Jul 13 19:45:49 2014 Julian Caille
//

#include "Game.hpp"


void	Game::checkClosedSound()
{
  if (_sound.soundLabel("ingame1")->getStatus() == sf::Sound::Playing)
    _sound.pauseChannel("ingame1");
}
