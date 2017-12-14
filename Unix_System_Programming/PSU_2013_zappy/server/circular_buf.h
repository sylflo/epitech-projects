/*
** circular_buf.h for  in /home/chatea_s/PSU_2013_zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Tue Jul  8 21:55:58 2014
** Last update Sun Jul 13 02:27:35 2014 
*/

#ifndef CIRCULAR_BUF_H_
# define CIRCULAR_BUF_H_

#include "server.h"

typedef union u_server	t_server;

typedef struct			s_elem_ring_buff
{
  char				data[1000];
  double			future_time;
  double			time_action;
  struct s_elem_ring_buff	*next;
}				t_elem_ring_buff;

typedef struct		s_ring_buff
{
    t_elem_ring_buff	*begin;
    t_elem_ring_buff	 *end;
    int			size;
}			t_ring_buff;

void	init_list(t_ring_buff *list);
int	ins_list_circ_empty(t_ring_buff *list, char *donnee, t_server *server);
int	ins_list_circ(t_ring_buff *list, t_elem_ring_buff *courant,
		      char *donnee, t_server *server);
int	del_list_circ(t_ring_buff *list);
int	del_list_circ_unique (t_ring_buff *list);
void	print(t_ring_buff *list);
void	destroy(t_ring_buff *list);
char	*get_cmd(t_ring_buff *list, int pos);
double	find_time(char *buffer, t_server *server);
double	convert_to_micro(struct timeval *t);

#endif /* !CIRCULAR_BUF_H_*/
