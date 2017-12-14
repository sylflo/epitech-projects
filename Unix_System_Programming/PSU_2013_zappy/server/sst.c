/*
** sst.c for  in /home/chatea_s/PSU_2013_zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Thu Jul 10 12:10:24 2014
** Last update Sun Jul 13 19:18:09 2014 
*/

#include "server.h"
#include "cmd_graphic.h"

void		change_dead_time_ia(t_server *server)
{
  t_trantorian	*ai;

  ai = server->ln.AI;
  while (ai)
    {
      if (ai->is_graphic == 2)
      	ai->time_death = find_time_death(ai , server);
      ai = ai->next;
    }
}

int	sst_func(char *buffer, t_server *server)
{
  int	i;
  char	*token;

  i = 0;
  token = strtok(buffer, " ");
  while (token)
    {
      if (i == 1)
	server->ln.delay = atoi(token);
      token = strtok(NULL, " ");
      i++;
    }
  if (server->ln.delay <= 0)
    server->ln.delay = 1;
  if (i != 2)
    return (-2);
  sgt_func("sgt", server);
  change_dead_time_ia(server);
  return (TRUE);
}
