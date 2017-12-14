/*
** ai.h for  in /home/chatea_s/PSU_2013_zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Tue Jul  8 21:54:05 2014
** Last update Sun Jul 13 19:15:07 2014 
*/

#ifndef AI_H_
# define AI_H_

#include "circular_buf.h"
#include "server.h"

enum
  {
    NORD = 1,
    EST = 2,
    SUD = 3,
    OUEST = 4
  };

typedef struct		s_trantorian
{
  int			socket;
  int			posX;
  int			posY;
  int			stones[6];
  int			food;
  int			life_cycle;
  int			team;
  int			level;
  int			dir;
  double		time_death;
  char			is_incantation;
  char			is_dead;
  char			is_graphic;
  char			is_first;
  int			hatch_flag;
  int			fork_flag;
  struct timeval	hatch;
  t_ring_buff		*list;
  t_elem_ring_buff	*buf;
  struct s_trantorian	*next;
}			t_trantorian;

int		add_ia(int fd, t_server *server);
int		del_ia(int fd, t_server *server);
void		aff_list(t_server *server);
void		init_AI(t_trantorian *AI, t_server *server);
t_trantorian    *get_AI(int fd, t_server *server);

#endif /* !AI_H_*/
