//
// main.cpp for test in /home/storm/bomberman/test_sound
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Sat Jun 14 20:36:15 2014 Julian Caille
// Last update Mon Jun 16 01:09:28 2014 Julian Caille
//

#include "Sound.hpp"
#include <cstdlib>
#include <stdio.h>
#include <unistd.h>

Sound_mgr::Sound_mgr()
{
  FMOD_System_Create(&_sys);
  FMOD_System_Init(_sys, 4, FMOD_INIT_NORMAL, NULL);
}

Sound_mgr::~Sound_mgr()
{
  FMOD_System_Release(_sys);
}

void		Sound_mgr::CreateSound(std::string const &_label,
				       char const *file_name, bool const &_loop)
{
  FMOD_SOUND	*new_sound;
  FMOD_CHANNEL	*channel;

  if (_loop)
    FMOD_System_CreateStream(_sys, file_name,
			     FMOD_HARDWARE | FMOD_LOOP_NORMAL | FMOD_2D, 0, &new_sound);
  else
    FMOD_System_CreateStream(_sys, file_name,
			     FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &new_sound);
  _sounds.push_back(new_sound);
  _labels.push_back(_label);
}

void		Sound_mgr::PlaySound(std::string const &_label)
{
  int		i;

  i = 0;
  while (_labels[i] != _label)
    i++;
  FMOD_System_PlaySound(_sys, FMOD_CHANNEL_FREE, _sounds[i], 0, &_channel);
}

void		Sound_mgr::StopSound()
{
  FMOD_System_Close(_sys);
  FMOD_System_Release(_sys);
  _labels.clear();
  _sounds.clear();
}

void		Sound_mgr::ResumeSound()
{
  FMOD_System_Create(&_sys);
  FMOD_System_Init(_sys, 4, FMOD_INIT_NORMAL, NULL);
}
