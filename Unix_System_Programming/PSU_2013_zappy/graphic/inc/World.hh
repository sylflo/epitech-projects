//
// World.hh for zappy in /home/couder_a/Depot/PSU/git/zappy
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Tue Jun 24 17:39:21 2014 Arthur Coudert
// Last update Sun Jul 13 20:27:54 2014 Arthur Coudert
//

#ifndef WORLD_HH
# define WORLD_HH

# include <SFML/System.hpp>
# include <vector>
# include <list>
# include <deque>
# include "LivingEntity.hh"
# include "Team.hh"
# include "Case.hh"
# include "Texture.hpp"
# include "MyError.hpp"
# include "BroadCast.hh"

class World
{
public:
  World();
  ~World();

public:

public:
  std::string			getFinish() const;
  const std::vector<Case*>	&getMap() const;
  std::list<BroadCast*>		getBc() const;
  std::vector<Team*>		getTeam() const;
  std::vector<LivingEntity*>	getEntity() const;
  sf::Vector2u		getMapSize() const;
  int			getFreq() const;
  Texture		*getTexture() const;
  void			setMapSize(const sf::Vector2u size);
  void			setFinish(std::string const &finish);
  void			parseCommand(const std::vector<std::string> &command);
  void			setTexture(Texture *);
  bool			parseEgg(const std::vector<std::string> &command);
  bool			parseAi(const std::vector<std::string> &command);
  void			update(sf::Time time);
  void			updateCase(int);
  bool			getGen()const;
  unsigned int		getNbGen()const;
  const std::string &	getLastDeque() const;
  unsigned int		getSizeDeque() const;
  void			DepopDeque();
private:
  Sound			_sound;
  std::vector<Case*>	_map;
  std::vector<Team*>	_team;
  std::vector<LivingEntity*>	_entity;
  std::list<BroadCast*>	_bc;
  std::deque<std::string>		_request;
  Texture		*_text;
  sf::Vector2u		_mapSize;
  std::string		_finish;
  int			_freq;
  int			_currentTeam;
  unsigned int		_nbgen;
  bool			_gen;
};

#endif /* !WORLD_HH */
