//
// LivingEntity.hh for zappy in /home/couder_a/Depot/PSU/git/zappy
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Mon Jun 30 16:56:18 2014 Arthur Coudert
// Last update Sun Jul 13 23:57:17 2014 Julian Caille
//

#ifndef LIVINGENTITY_HH
# define LIVINGENTITY_HH

# include <vector>
# include <SFML/System.hpp>
# include <deque>
# include "Item.hh"
# include "Animate.hpp"
# include "Sound.hpp"

enum Orientation{
  N = 1,
  E,
  S,
  O
};

enum TypeLivingEntity{
  AI,
  EGG,
  SHIT
};

enum TypeTexture{
  LEVEL = -5,
  INCANT,
  SHITTY,
  EGG_MATURE,
  EGG_IMATURE,
  RED,
  YELLOW,
  BLUE,
  PURPLE,
  WHITE,
  DARK_BLUE,
  GREY,
  LIGHT_BLUE,
  BROWN,
  ORANGE,
  PINK,
  GREEN,
  BLACK,
};

typedef sf::Vector3<unsigned int> Vector3u;

class LivingEntity
{
public:
  LivingEntity(sf::Vector2u mapSize,int id, int x, int y, int o, int lvl, std::string ,int type, Texture * text, Sound new_sound, int color = -1);
  ~LivingEntity();

public:
  std::string		getLabelSound(int const &pos) const;
  int			getDir() const;
  int			getTypeCase() const;
  std::vector<Item*>	getInventory() const;
  Vector3u		getPos() const;
  sf::Vector2i		getPosRela() const;
  Vector3u		getPosDest() const;
  int			getLvl() const;
  int			getId() const;
  int			getType() const;
  int			getColor() const;
  std::string		getTeam() const;
  std::string		getNameLvl(int const &lvl) const;
  Animated		*getAnim();
  Animated		*getAnimLevel();
  Animated		*getAnimIncant();
  bool			getIncant() const;
  Sound			getSound() const;
  int			getCurrentFrame() const;
  void			setShit(Texture *text);
  void			setLvl(int);
  void			setPosDest(Vector3u);
  void			setInventory(const std::vector<std::string> &command);
  void			setMature(Texture *text);
  void			setPosRela(sf::Vector2i);
  void			setIncant(bool incant);
  void			setDir(int const &dir);
  void			setCurrentFrame(int const &iterator);
  void			setTypeCase(int const &set);
  unsigned int		arrived();
  unsigned int		length();

public:
  LivingEntity&		operator+=(sf::Vector2u const &);
  LivingEntity&		operator-=(sf::Vector2u const &);

private:
  Sound			_sound;
  std::vector<Item*>	_inventory;
  Vector3u		_pos;
  sf::Vector2u		_mapSize;
  sf::Vector2i		_posRela;
  std::deque<Vector3u>	_posDest;
  bool			_incant;
  int			_lvl;
  int			_id;
  int			_type;
  int			_color;
  Animated		_incantation;
  Animated		_anim;
  Animated		_level;
  std::string		_team;
  std::vector<std::string> _nameLvl;
  std::vector<std::string> _caseType;
  int			_Dir;
  int			_animation;
  int			_typeCase;
};

#endif /* !LIVINGENTITY_HH */
