//
// Sound.hpp for bomberman in /home/storm/bomberman/test_sound
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Sat Jun 14 20:41:59 2014 Julian Caille
// Last update Mon Jun 16 01:03:00 2014 Julian Caille
//

#ifndef _SOUND_HPP_
# define _SOUND_HPP_

# include <vector>
# include <string>
# include "fmod.hpp"

class	Sound_mgr
{
public:
  Sound_mgr();
  ~Sound_mgr();
  void	CreateSound(std::string const &_label, char const *file_name, bool const &_loop);
  void	PlaySound(std::string const &_label);
  void	StopSound();
  void	ResumeSound();
private:
  FMOD_SYSTEM	*_sys;
  std::vector<std::string> _labels;
  std::vector<FMOD_SOUND *> _sounds;
  FMOD_CHANNEL	*_channel;
};

#endif /* !_SOUND_HPP_ */
