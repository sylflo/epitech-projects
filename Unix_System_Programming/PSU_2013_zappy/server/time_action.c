/*
** time_action.c for  in /home/chatea_s/PSU_2013_zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Fri Jul 11 17:22:15 2014
** Last update Sun Jul 13 20:33:47 2014 
*/

#include "server.h"

int	return_time(int i, double time[12])
{
  if (i < 12)
    return (time[i]);
  return (-1);
}

double		find_time(char *buffer, t_server *server)
{
  int		i;
  double	time[12];
  char		*command[12] = {"prend", "pose", "inventaire", "avance",
				"droite", "gauche", "incantation",
				"voir", "expulse", "fork", "broadcast",
				"connect_nbr"};

  i = 0;
  time[0] = (7 / server->ln.delay) * 1000000;
  time[1] = (7 / server->ln.delay) * 1000000;
  time[2] = (1 / server->ln.delay) * 1000000;
  time[3] = (7 / server->ln.delay) * 1000000;
  time[4] = (7 / server->ln.delay) * 1000000;
  time[5] = (7 / server->ln.delay) * 1000000;
  time[6] = (300 / server->ln.delay) * 1000000;
  time[7] = (7 / server->ln.delay) * 1000000;
  time[8] = (7 / server->ln.delay) * 1000000;
  time[9] = (42 / server->ln.delay) * 1000000;
  time[10] = (7 / server->ln.delay) * 1000000;
  time[11] = 0;
  while (i < 12 && strncmp(buffer, command[i], strlen(command[i])))
    i++;
  return (return_time(i, time));
}
