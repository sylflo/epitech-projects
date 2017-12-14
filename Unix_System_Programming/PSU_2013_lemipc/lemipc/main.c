/*
** main.c for  in /home/chatea_s/project/unix/lemipc
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Wed Mar 26 17:04:02 2014 Sylvain Chateau
** Last update Sat Mar 29 20:53:58 2014 Sylvain Chateau
*/

#include <time.h>
#include "lemipc.h"

int		main(void)
{
  t_lemipc	lemipc;
  int		ret;

  lemipc.can_play = 0;
  lemipc.access = 0;
  srand(time(NULL));
  if ((ret = func_board(&lemipc)) == 0)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
