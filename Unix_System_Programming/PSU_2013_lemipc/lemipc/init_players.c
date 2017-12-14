/*
** init_players.c for  in /home/chatea_s/project/unix/lemipc
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Sat Mar 29 19:53:06 2014 Sylvain Chateau
** Last update Sat Mar 29 19:54:14 2014 Sylvain Chateau
*/

#include "lemipc.h"

void	choose_player(t_lemipc *lemipc)
{
  lemipc->access++;
  if (nb_team_player(lemipc->addr, '1') <= nb_team_player(lemipc->addr, '2'))
    lemipc->team = '1';
  else
    lemipc->team = '2';
  printf("Player is in team = %c\n", lemipc->team);
}

int	first_player(t_lemipc *lemipc)
{
  if ((lemipc->sem_id = semget(lemipc->key, 1, IPC_CREAT | SHM_R | SHM_W))
      == -1)
    {
      perror("semget");
      return (0);
    }
  if (semctl(lemipc->sem_id, 0, SETVAL, 1) == -1)
    {
      perror("semctl firstplayer");
      return (0);
    }
  if (!func_lemipc(lemipc))
    return (0);
  return (1);
}

int	next_player(t_lemipc *lemipc)
{
  if ((lemipc->sem_id = semget(lemipc->key, 1, IPC_CREAT | SHM_R | SHM_W))
      == -1)
    {
      perror("semget");
      return (0);
    }
  lemipc->access = 0;
  lemipc->addr = shmat(lemipc->shm_id, NULL, SHM_R | SHM_W);
  if (*(int *)lemipc->addr == -1)
    {
      perror("shmat");
      return (0);
    }
  if (!func_lemipc(lemipc))
    return (0);
  return (1);
}
