/*
** opponent.c for  in /home/chatea_s/project/unix/lemipc
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Sat Mar 29 19:57:07 2014 Sylvain Chateau
** Last update Sat Mar 29 21:35:52 2014 Sylvain Chateau
*/

#include <unistd.h>
#include "lemipc.h"

int	find_side_opponent(t_lemipc *lemipc, int pos_x, int pos_y,
			   char opponent)
{
  int	nb_opponent;

  nb_opponent = 0;
  if (pos_x < 5)
    {
      if (lemipc->map[pos_x + 1][pos_y] == opponent)
	nb_opponent++;
    }
  if (pos_x > 0)
    {
      if (lemipc->map[pos_x - 1][pos_y] == opponent)
	nb_opponent++;
    }
  if (pos_y > 0)
    {
      if (lemipc->map[pos_x][pos_y - 1] == opponent)
	nb_opponent++;
    }
  if (pos_y < 5)
    {
      if (lemipc->map[pos_x][pos_y + 1] == opponent)
	nb_opponent++;
    }
  return (nb_opponent);
}

int	find_diago_opponent(t_lemipc *lemipc, int pos_x, int pos_y,
			    char opponent)
{
  int	nb_opponent;

  nb_opponent = 0;
  if (pos_y > 0 && pos_x > 0)
    {
      if (lemipc->map[pos_x - 1][pos_y - 1] == opponent)
	nb_opponent++;
    }
  if (pos_x < 5 && pos_y > 0)
    {
      if (lemipc->map[pos_x + 1][pos_y - 1] == opponent)
	nb_opponent++;
    }
  if (pos_x > 0 && pos_y < 5)
    {
      if (lemipc->map[pos_x - 1][pos_y + 1] == opponent)
	nb_opponent++;
    }
  if (pos_x < 5 && pos_y < 5)
    {
      if (lemipc->map[pos_x + 1][pos_y + 1] == opponent)
	nb_opponent++;
    }
  return (nb_opponent);
}

int	find_opponent(t_lemipc *lemipc, int pos_x, int pos_y, char opponent)
{
  int	nb_opponent;

  if (sleep(1) != 0)
    return (-1);
  nb_opponent = find_side_opponent(lemipc, pos_x, pos_y, opponent);
  nb_opponent += find_diago_opponent(lemipc, pos_x, pos_y, opponent);
  return (nb_opponent);
  if (sleep(1) != 0)
    return (-1);
}

int	check_killing(t_lemipc *lemipc)
{
  int	pos_x;
  int	pos_y;
  char	opponent;
  int	ret;

  pos_x = lemipc->pos_player / 6;
  pos_y = lemipc->pos_player % 6;
  if (lemipc->team == '1')
    opponent = '2';
  else
    opponent = '1';
  if ((ret = find_opponent(lemipc, pos_x, pos_y, opponent)) >= 2)
    {
      lemipc->addr[lemipc->pos_player] = 'o';
      lemipc->team = 'o';
    }
  else if (ret == -1)
    return (0);
  return (1);
}
