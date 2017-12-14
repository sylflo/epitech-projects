//
// Item.hh for zappy in /home/couder_a/Depot/PSU/git/zappy
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Wed Jun 25 11:05:37 2014 Arthur Coudert
// Last update Sat Jul  5 20:52:05 2014 Arthur Coudert
//

#ifndef ITEM_HH
# define ITEM_HH

# include <SFML/System.hpp>
# include <vector>

enum	ItemType{
  MEAT,
  LINEMATE,
  DERAUMERE,
  SIBUR,
  MENDIANE,
  PHIRAS,
  THYSTAME
};

class Item{
public:
  Item(int, int);
  Item(const Item &);
  ~Item();

public:
  sf::Vector2i		getPosRela() const;
  int			getNbRes() const;
  void			setNbRes(int);
  int			getType() const;
  void			setPosRela(int nb);
  void			setPosRela(sf::Vector2i posRela);
  void			setPosRelaDest(sf::Vector2i posRela);
  bool			move();

private:
  sf::Vector2i			_posRela;
  sf::Vector2i			_posRelaDest;
  int				_nbRes;
  int				_type;
};

#endif /* !ITEM_HH */
