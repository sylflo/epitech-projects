/*
** check_level_incantation_2.c for  in /home/chatea_s/PSU_2013_zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Sat Jul 12 20:22:35 2014
** Last update Sun Jul 13 21:51:22 2014 
*/

#include "server.h"
#include "cmd_graphic.h"

int	check_level_five_stones_and_players(int pos, int nb_players,
					    t_server *server)
{
  if (nb_players != 4)
    return (FALSE);
  if (server->ln.map[pos].stones[0] == 1 &&
      server->ln.map[pos].stones[1] == 2 &&
      server->ln.map[pos].stones[2] == 1 &&
      server->ln.map[pos].stones[3] == 3 &&
      server->ln.map[pos].stones[4] == 0 &&
      server->ln.map[pos].stones[5] == 0)
    return (TRUE);
  return (FALSE);
}

int	check_level_six_stones_and_players(int pos, int nb_players,
					   t_server *server)
{
  if (nb_players != 6)
    return (FALSE);
  if (server->ln.map[pos].stones[0] == 1 &&
      server->ln.map[pos].stones[1] == 2 &&
      server->ln.map[pos].stones[2] == 3 &&
      server->ln.map[pos].stones[3] == 0 &&
      server->ln.map[pos].stones[4] == 1 &&
      server->ln.map[pos].stones[5] == 0)
    return (TRUE);
  return (FALSE);
}

int	check_level_seven_stones_and_players(int pos, int nb_players,
					     t_server *server)
{
  if (nb_players != 6)
    return (FALSE);
  if (server->ln.map[pos].stones[0] == 2 &&
      server->ln.map[pos].stones[1] == 2 &&
      server->ln.map[pos].stones[2] == 2 &&
      server->ln.map[pos].stones[3] == 2 &&
      server->ln.map[pos].stones[4] == 2 &&
      server->ln.map[pos].stones[5] == 1)
    return (TRUE);
  return (FALSE);
}

int	check_level_case(t_trantorian *hand, t_server *server)
{
  int	nb_players;
  int	pos;
  int	tab_level[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int	(*check_stones_and_players[7])(int, int, t_server *);
  int	i;

  check_stones_and_players[0] = &check_level_one_stones_and_players;
  check_stones_and_players[1] = &check_level_two_stones_and_players;
  check_stones_and_players[2] = &check_level_three_stones_and_players;
  check_stones_and_players[3] = &check_level_four_stones_and_players;
  check_stones_and_players[4] = &check_level_five_stones_and_players;
  check_stones_and_players[5] = &check_level_six_stones_and_players;
  check_stones_and_players[6] = &check_level_seven_stones_and_players;
  check_stones_and_players[7] = NULL;
  i = -1;
  nb_players = nb_players_same_level_func(hand, server);
  pos = hand->posX + (hand->posY * server->ln.width);
  while (++i < 7)
    {
      if (hand->level == tab_level[i])
	if (check_stones_and_players[i](pos, nb_players, server) == FALSE)
	  return (FALSE);
    }
  return (TRUE);
}
