//
// Sound.cpp for zappy in /home/storm/zappy/zappy/src
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Thu Jun 19 16:51:16 2014 Julian Caille
// Last update Sun Jul 13 22:54:33 2014 Arthur Coudert
//

#include "Sound.hpp"

Sound::Sound()
{
}

Sound::~Sound()
{
}

bool			Sound::newChannel(char const *filename, char const *label)
{
  sf::SoundBuffer	channel;
  sf::Sound		newSound;

  _buffers.push_back(new sf::SoundBuffer);
  _sound.push_back(new sf::Sound);
  if (!_buffers.back()->loadFromFile(filename))
    return (false);
  _sound.back()->setBuffer(*_buffers.back());
  _sound.back()->play();
  _labels.push_back(label);
  return (true);
}

void			Sound::pauseChannel(char const *label)
{
  unsigned int		i;

  i = -1;
  while (++i != _labels.size())
    if (label == _labels[i])
      _sound[i]->pause();
}

void			Sound::resumeChannel(char const *label)
{
  unsigned int		i;

  i = -1;
  while (++i != _labels.size())
    if (label == _labels[i])
      _sound[i]->play();
}

sf::Sound		*Sound::soundLabel(std::string const &label)
{
  unsigned int		i;

  i = -1;
  while (++i != _labels.size())
    if (label == _labels[i])
      return (_sound[i]);
  return (_sound[0]);
}

void			Sound::removeAll()
{
  unsigned int		i;

  i = -1;
  while (++i != _labels.size())
    _sound[i]->pause();
  _buffers.clear();
  _labels.clear();
  _sound.clear();
}

bool			Sound::addToChannel(char const *label)
{
  (void)label;
  return (true);
}
