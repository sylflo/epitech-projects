/*
** death_time.c for zappy in /home/duboy_m/PSU_2013_zappy
**
** Made by maxime duboy
** Login   <duboy_m@epitech.net>
**
** Started on  Sat Jul 12 20:06:55 2014 maxime duboy
** Last update Sun Jul 13 20:19:10 2014 
*/

#include <float.h>
#include "server.h"
#include "cmd_graphic.h"

int		find_min_death(t_server *server)
{
  t_trantorian *ai;
  double	min;
  int		fd;

  fd = -1;
  min = DBL_MAX;
  ai = server->ln.AI;
  while (ai)
    {
      if (ai->time_death < min && ai->time_death != -1)
	{
	  min = ai->time_death;
	  fd = ai->socket;
	}
      ai = ai->next;
    }
  if (fd != -1 && get_AI(fd, server) && get_AI(fd, server)->time_death != -1)
    {
      change_exec_death(server, min);
      return (fd);
    }
  return (-1);
}

double		find_time_death(t_trantorian *AI, t_server *server)
{
  double	action_death;
  double	ret;

  action_death =  ((double)126 / (double)server->ln.delay) * AI->food;
  action_death *= 1000000;
  ret = action_death + convert_to_micro(&server->ln.current_time);
  return (ret);
}
