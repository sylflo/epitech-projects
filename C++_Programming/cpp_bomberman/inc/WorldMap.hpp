//
// WorldMap.hpp for  in /home/chatea_s/project/c++/bomberman
//
// Made by Sylvain Chateau
// Login   <chatea_s@epitech.net>
//
// Started on  Fri May  2 19:20:38 2014 Sylvain Chateau
// Last update Thu Jun 12 18:33:44 2014 maxime duboy
//

#ifndef MAP_H_
# define MAP_H_

# include <vector>
# include "AObject.hpp"

class WorldMap
{
public:
  ~WorldMap();

public:
  bool				initialize(gdl::Geometry *);

public:
  bool				createWorldMap(gdl::Geometry *);
  void				dumpWorldMap() const;
  void				find_pos(const int, int *, int *) const;
  bool				check_nbPlayers() const;

public:
  static WorldMap*		get();
  std::vector<AObject *>*	getWorldMap();
  int				getPosFirstPlayer() const;
  int				getPosSecondPlayer() const;
  int				getNbPlayer() const;
  int				getNbIA() const;
  int				getHeight() const;
  int				getWidth() const;
  int				getnbWalls() const;
  std::list<int>		getListPosCube() const;

public:
  static void			init(const int, const int, const int, const int);
  static void			destroy();
  void				setPosFirstPlayer(const int);
  void				setPosSecondPlayer(const int);
  void				setListPosCube(const std::list<int> &);


private:
  WorldMap(const int, const int, const int, const int); 
  
  static WorldMap*		_singleton;
  const int			_width;
  const int			_height;
  int				_nbPlayers;
  int				_nbAI;
  int				_nbWalls;
  std::vector<AObject *>	_map;
  int				_posFirstPlayer;
  int				_posSecondPlayer;
  std::list<int>		_list_pos_cube;
  int				_sizeVertices;
  float				_vertices[108];
};

#endif /* !MAP_H_*/
