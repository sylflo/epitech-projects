/*
** death.c for  in /home/chatea_s/PSU_2013_zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Thu Jul 10 18:09:47 2014
** Last update Sun Jul 13 18:22:13 2014 
*/

#include <float.h>
#include "server.h"
#include "cmd_graphic.h"

void	change_exec_death(t_server *server, double min)
{
  server->ln.exec_death.tv_sec = ((time_t)min / 1000000) -
    server->ln.current_time.tv_sec;
  server->ln.exec_death.tv_usec = ((suseconds_t)min % 1000000) -
    server->ln.current_time.tv_usec;
  if (server->ln.exec_death.tv_usec < 0)
    {
      server->ln.exec_death.tv_sec--;
      server->ln.exec_death.tv_usec += 1000000;
    }
}

void	put_stones_in_map(int nb_stones, int stones, t_server *server)
{
  int   posCaseRand;
  int   posXrand;
  int   posYrand;
  int   i;

  i = -1;
  while (++i < nb_stones)
    {
      posXrand = rand() % server->ln.width;
      posYrand = rand() % server->ln.height;
      posCaseRand = posXrand + (server->ln.width * posYrand);
      server->ln.map[posCaseRand].stones[stones]++;
      object_in_case(posXrand, posYrand, server);
      send_to_graphic(server->ln.response, server);
    }
}

int	dead_ai(t_trantorian *hand, t_server *server)
{
  char	cmd_pdi[100] = {"pdi "};
  char	id_char[10];
  int	i;

  i = -1;
  sprintf(id_char, "%d", hand->socket);
  strcat(cmd_pdi, id_char);
  strcat(cmd_pdi, "\n");
  send_to_graphic(cmd_pdi, server);
  write(hand->socket, "mort\n", strlen("mort\n"));
  while (++i < 6)
    put_stones_in_map(hand->stones[i], i, server);
  return (-2);
}

int		check_dead_ia(t_server *server)
{
  t_trantorian	*ai;
  int		i;

  i = 0;
  ai = server->ln.AI;
  while (ai)
    {
      if (convert_to_micro(&server->ln.current_time) >= ai->time_death
	  && ai->is_graphic == 2)
	{
	  ai->is_dead = 1;
	  i = 1;
	}
      ai = ai->next;
    }
  if (!i)
    return (FALSE);
  return (TRUE);
}

void		kill_ai(t_server *server, t_select *s_select)
{
  t_trantorian	*ai;
  int		fd[(server->ln.allow_client + 1) * server->ln.nbr_team];
  int		i;

  memset(fd, 0, (server->ln.allow_client + 1) * server->ln.nbr_team);
  i = 0;
  ai = server->ln.AI;
  while (ai)
    {
      if (ai->is_dead == 1)
	{
	  dead_ai(ai, server);
	  fd[i] = ai->socket;
	  i++;
	}
      ai = ai->next;
    }
  fd[i] = -1;
  i = -1;
  while (fd[++i] != -1)
    close_fd(fd[i], s_select, server);
}
