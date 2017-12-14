/*
** lock_sem.c for  in /home/chatea_s/project/unix/lemipc
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Thu Mar 27 22:33:52 2014 Sylvain Chateau
** Last update Sat Mar 29 19:34:30 2014 Sylvain Chateau
*/

#include "lemipc.h"

int	lock_sem(t_lemipc *lemipc)
{
  lemipc->sops.sem_num = 0;
  lemipc->sops.sem_op = -1;
  lemipc->sops.sem_flg = 0;
  if (semctl(lemipc->sem_id, 0, GETVAL) == -1)
    {
      perror("semctl play_game");
      return (0);
    }
  if (semop(lemipc->sem_id, &(lemipc->sops), 1) == -1)
    {
      perror("semop");
      return (0);
   }
  return (1);
}

int	unlock_sem(t_lemipc *lemipc)
{
  lemipc->sops.sem_num = 0;
  lemipc->sops.sem_op = 1;
  lemipc->sops.sem_flg = 0;
  if (semop(lemipc->sem_id, &(lemipc->sops), 1) == -1)
    {
      perror("semop");
      return (0);
    }
  if (semctl(lemipc->sem_id, 0, GETVAL) == -1)
    {
      perror("semctl");
      return (0);
    }
  return (1);
}
