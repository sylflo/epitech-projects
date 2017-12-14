//
// Team.hh for zappy in /home/couder_a/Depot/PSU/git/zappy
//
// Made by Arthur Coudert
// Login   <couder_a@epitech.net>
//
// Started on  Thu Jun 26 10:26:37 2014 Arthur Coudert
// Last update Mon Jul  7 20:21:12 2014 Arthur Coudert
//

#ifndef TEAM_HH
# define TEAM_HH

# include <vector>
# include <string>
# include <cstdlib>

class Team
{
public:
  Team(const std::string);
  ~Team();

public:
  const std::string	getName() const;
  int			getColor() const;
  int			getNb() const;
  void			incNb();
  void			decNb();

private:
  const std::string	_name;
  int			_color;
  int			_nb;
};

#endif /* !TEAM_HH */
