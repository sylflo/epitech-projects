/*
** first_cmd_ia.c for  in /home/chatea_s/zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Mon Jul  7 21:22:32 2014
** Last update Sun Jul 13 19:50:46 2014 
*/

#include <float.h>
#include "server.h"

int	change_exec_action(t_server *server, double min)
{
  if (min != -1 && min < DBL_MAX)
    {
      server->ln.exec_action.tv_sec = ((time_t)min / 1000000) -
	server->ln.current_time.tv_sec;
      server->ln.exec_action.tv_usec = ((suseconds_t)min % 1000000) -
	server->ln.current_time.tv_usec;
      if (server->ln.exec_action.tv_usec < 0)
	{
	  server->ln.exec_action.tv_sec--;
	  server->ln.exec_action.tv_usec += 1000000;
	}
      if (server->ln.exec_action.tv_sec < 0 ||
      	  server->ln.exec_action.tv_usec < 0)
      	{
      	  server->ln.exec_action.tv_sec = 0;
      	  server->ln.exec_action.tv_usec = 0;
      	}
      return (TRUE);
    }
  server->ln.exec_action.tv_sec = 0;
  server->ln.exec_action.tv_usec = 0;
  return (FALSE);
}

int			find_min_time_first_command(t_server *server)
{
  t_trantorian		*ia;
  t_elem_ring_buff	*elem;
  double		min;
  double		time;

  min = DBL_MAX;
  ia = server->ln.AI;
  time = -1;
  while (ia)
    {
      elem = ia->list->begin;
      if (elem)
	time = elem->future_time;
      if (time != -1 && time < min)
	{
	  min = time;
	  server->ln.fd_time = ia->socket;
	}
      ia = ia->next;
    }
  return (change_exec_action(server, min));
}
