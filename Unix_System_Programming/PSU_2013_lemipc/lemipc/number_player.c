/*
** number_player.c for  in /home/chatea_s/project/unix/lemipc
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Sat Mar 29 20:00:55 2014 Sylvain Chateau
** Last update Sat Mar 29 20:01:13 2014 Sylvain Chateau
*/

#include "lemipc.h"

int	nb_team_player(char *map, char team)
{
  int	i;
  int	nb_players;

  i = -1;
  nb_players = 0;
  while (map[++i])
    {
      if (map[i] == team)
	nb_players++;
    }
  return (nb_players);
}

void	total_player(t_lemipc *lemipc)
{
  int	i;

  lemipc->nb_players = 0;
  i = -1;
  while (lemipc->addr[++i])
    {
      if (lemipc->addr[i] == '1' || lemipc->addr[i] == '2')
	lemipc->nb_players++;
    }
}
