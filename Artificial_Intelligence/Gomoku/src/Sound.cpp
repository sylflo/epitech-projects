//
// Sound.cpp for Sound in /home/storm/IA/Gomoku/src
//
// Made by caille_j
// Login   <caille_j@epitech.net>
//
// Started on  Mon Nov  3 11:24:28 2014
// Last update Wed Nov 12 14:40:04 2014 caille_j
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
    {
      throw Exception("Error : Couldn't load music in path : " + std::string(filename));
      return (false);
    }
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
