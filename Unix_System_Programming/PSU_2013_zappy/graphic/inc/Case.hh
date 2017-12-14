//
// Case.hh for zappy in /home/couder_a/Depot/PSU/git/zappy
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Wed Jun 25 10:45:20 2014 Arthur Coudert
// Last update Sun Jul  6 17:28:45 2014 Arthur Coudert
//

#ifndef CASE_HH
# define CASE_HH

# include <SFML/System.hpp>
# include <vector>
# include "Item.hh"

enum CaseType{
  GRASS,
  DIRT,
  STONE,
  SAND
};

class Case
{
public:
  Case();
  Case(const Case &);
  ~Case();
  Case	&operator=(const Case&);

public:
  void				parseCommand(const std::vector<std::string> &);
  void				Init(const std::vector<std::string> &, sf::Vector2u);

public:
  sf::Vector2u			getPos() const;
  std::vector<Item*>		getRes() const;
  int				getType() const;
  void				pushNewItem(sf::Vector2i posRela, int type, int action);
  void				update();
private:
  sf::Vector2u			_pos;
  std::vector<Item*>		_res;
  int				_type;
};

#endif /* !CASE_HH */
