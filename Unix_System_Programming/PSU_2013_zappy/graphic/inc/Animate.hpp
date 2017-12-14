//
// Animate.hpp for zappy in /home/storm/zappy/zappy/inc
//
// Made by Julian Caille
// Login <caille_j@epitech.net>
//
// Started on  Fri Jun 20 19:37:08 2014 Julian Caille
// Last update Sun Jul  6 21:04:09 2014 Julian Caille
//

#ifndef _ANIMATE_HPP_
# define _ANIMATE_HPP_

# include "Texture.hpp"

class Frame
{
public:
  Frame(std::vector<sf::IntRect > *,
	std::string const &);
  ~Frame();
  std::string getLabel() const;
  unsigned int	getCurrent() const;
  std::vector<sf::IntRect > *getPositions() const;
  void		setCurrent(unsigned int const current);
private:
  std::vector<sf::IntRect > *_positions;
  std::string _label;
  unsigned int	_current;
};

class Animated
{
public:
  Animated();
  ~Animated();
  void	setSprite(sf::Sprite sprite, std::string const &name, int const &timer);
  sf::Sprite *getSprite();
  std::string getAnimationName() const;

  void	addNewAnimation(std::string const &label,
			std::vector<sf::IntRect> *frames);
  int	playAnimation(std::string const &label, sf::Vector2f const &pos,
		      sf::Time const &currentTime);
  void	setTimer(int const &timer);
  void	initializeAnimation(sf::Sprite sprite, int const &team, int const &timer);
  void	initializeRed(sf::Sprite sprite,  int const &timer);
  void	initializeYellow(sf::Sprite sprite, int const &timer);
  void	initializeBlue(sf::Sprite sprite,  int const &timer);
  void	initializeDarkBlue(sf::Sprite sprite,  int const &timer);
  void	initializeGrey(sf::Sprite sprite,  int const &timer);
  void	initializeLightBlue(sf::Sprite sprite,  int const &timer);
  void	initializeBrown(sf::Sprite sprite,  int const &timer);
  void	initializeOrange(sf::Sprite sprite,  int const &timer);
  void	initializePink(sf::Sprite sprite,  int const &timer);
  void	initializeGreen(sf::Sprite sprite,  int const &timer);
  void	initializeBlack(sf::Sprite sprite,  int const &timer);
  void	initializePurple(sf::Sprite sprite,  int const &timer);
  void	initializeWhite(sf::Sprite sprite,  int const &timer);
  void	initializeShit(sf::Sprite sprite,  int const &timer);
  void	initializeEggMature(sf::Sprite sprite,  int const &timer);
  void	initializeEggImature(sf::Sprite sprite,  int const &timer);
  void	initializeLevel(sf::Sprite sprite,  int const &timer);
  void	initializeIncant(sf::Sprite sprite,  int const &timer);

private:
  sf::Sprite	*_sprite;
  std::vector<Frame *>  *_frames;
  sf::Time	_timer;
  std::string	_name;
  int	_elTimer;
};

#endif /* !_ANIMATE_HPP_ */
