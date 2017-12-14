//
// Sound.hpp for zappy in /home/storm/zappy/zappy
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Thu Jun 19 16:48:30 2014 Julian Caille
// Last update Sun Jul 13 18:25:37 2014 Arthur Coudert
//

#ifndef _SOUND_HPP_
# define _SOUND_HPP_

# include <SFML/Audio.hpp>
# include <vector>
# include <string>
# include <iostream>
# include "MyError.hpp"

class	Sound
{
public:
  Sound();
  ~Sound();
  bool	newChannel(char const *filename, char const *label);
  bool	addToChannel(char const *label);
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
