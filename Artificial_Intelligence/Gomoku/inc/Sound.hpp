//
// Sound.hpp for Sound in /home/storm/spaceshooter/inc
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Mon Jul 21 18:48:50 2014 Julian Caille
// Last update Mon Jul 21 18:49:52 2014 Julian Caille
//

#ifndef _SOUND_HPP_
# define _SOUND_HPP_

# include <SFML/Audio.hpp>
# include <vector>
# include <string>
# include <iostream>
# include "Exception.hpp"

class	Sound
{
public:
  Sound();
  ~Sound();
  bool	newChannel(char const *filename, char const *label);
  void	pauseChannel(char const *label);
  void	resumeChannel(char const *label);
  void	removeAll();
  sf::Sound *soundLabel(std::string const &label);
private:
  std::vector<sf::SoundBuffer *>_buffers;
  std::vector<std::string >	_labels;
  std::vector<sf::Sound	 *>	_sound;
};

#endif /* !_SOUND_HPP_ */
