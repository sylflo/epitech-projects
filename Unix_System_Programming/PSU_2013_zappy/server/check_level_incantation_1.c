/*
** check_level_incantation_1.c for  in /home/chatea_s/PSU_2013_zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Sat Jul 12 20:21:16 2014
** Last update Sun Jul 13 21:50:32 2014 
*/

#include "server.h"
#include "cmd_graphic.h"

int	check_level_one_stones_and_players(int pos, int nb_players,
					   t_server *server)
{
  if (nb_players != 1)
    return (FALSE);
  if (server->ln.map[pos].stones[0] == 1 &&
      server->ln.map[pos].stones[1] == 0 &&
      server->ln.map[pos].stones[2] == 0 &&
      server->ln.map[pos].stones[3] == 0 &&
      server->ln.map[pos].stones[4] == 0 &&
      server->ln.map[pos].stones[5] == 0)
    return (TRUE);
  return (FALSE);
}

int	check_level_two_stones_and_players(int pos, int nb_players,
					   t_server *server)
{
  if (nb_players != 2)
    return (FALSE);
  if (server->ln.map[pos].stones[0] == 1 &&
      server->ln.map[pos].stones[1] == 1 &&
      server->ln.map[pos].stones[2] == 1 &&
      server->ln.map[pos].stones[3] == 0 &&
      server->ln.map[pos].stones[4] == 0 &&
      server->ln.map[pos].stones[5] == 0)
    return (TRUE);
  return (FALSE);
}

int	check_level_three_stones_and_players(int pos, int nb_players,
					     t_server *server)
{
  if (nb_players != 2)
    return (FALSE);
  if (server->ln.map[pos].stones[0] == 2 &&
      server->ln.map[pos].stones[1] == 0 &&
      server->ln.map[pos].stones[2] == 1 &&
      server->ln.map[pos].stones[3] == 0 &&
      server->ln.map[pos].stones[4] == 2 &&
      server->ln.map[pos].stones[5] == 0)
    return (TRUE);
  return (FALSE);
}

int	check_level_four_stones_and_players(int pos, int nb_players,
					    t_server *server)
{
  if (nb_players != 4)
    return (FALSE);
  if (server->ln.map[pos].stones[0] == 1 &&
      server->ln.map[pos].stones[1] == 1 &&
      server->ln.map[pos].stones[2] == 2 &&
      server->ln.map[pos].stones[3] == 0 &&
      server->ln.map[pos].stones[4] == 1 &&
      server->ln.map[pos].stones[5] == 0)
    return (TRUE);
  return (FALSE);
}
