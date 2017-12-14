/*
** lemipc.c for  in /home/chatea_s/project/unix/lemipc
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Sat Mar 29 20:01:46 2014 Sylvain Chateau
** Last update Sun Mar 30 19:03:03 2014 edouard mansuy
*/

#include <unistd.h>
#include "lemipc.h"

int	move(t_lemipc *lemipc)
{
  int	index;

  if (usleep(600000) == -1)
    {
      perror("usleep");
      return (0);
    }
  if (lemipc->team != 'o')
    {
       lemipc->addr[lemipc->pos_player] = 'o';
      index = rand() % 36;
      while (lemipc->addr[index] != 'o')
	index = rand() % 36;
      lemipc->addr[lemipc->pos_player] = 'o';
      lemipc->addr[index] = (char)lemipc->team;
      lemipc->pos_player = index;
    }
  return (1);
}

int	play_game(t_lemipc *lemipc)
{
  if (!create_map(lemipc))
    return (0);
  if (!check_killing(lemipc))
    return (0);
  if (!move(lemipc))
    return (0);
  if (nb_team_player(lemipc->addr, '1') == 0 ||
      nb_team_player(lemipc->addr, '2') == 0)
    {
      if (semctl(lemipc->sem_id, 0, IPC_RMID) == -1)
	{
	  perror("semctl");
	  return (0);
	}
      if (shmctl(lemipc->shm_id, IPC_RMID, NULL) == -1)
	{
	  perror("shmctl");
	  return (0);
	}
      return (2);
    }
  free_tab(lemipc->map);
  return (1);
}

int	func_lemipc(t_lemipc *lemipc)
{
  int	ret;

  while (1 && ret != 2)
    {
      if (!lock_sem(lemipc))
	return (0);
      if (lemipc->access == 0)
	choose_player(lemipc);
      if (lemipc->access == 1)
	add_player_in_map(lemipc);
      total_player(lemipc);
      if (lemipc->nb_players >= 3)
      	lemipc->can_play = 1;
      if (lemipc->can_play == 1)
	{
	  if ((ret = play_game(lemipc)) == 0)
	    return (0);
	}
      if (!unlock_sem(lemipc))
	return (0);
    }
  printf("out loop\n");
  return (1);
}

int	func_board(t_lemipc *lemipc)
{
  if ((lemipc->key = ftok("/dev", 0)) == -1)
    {
      perror("ftok");
      return (0);
    }
  lemipc->first = 0;
  if ((lemipc->shm_id = shmget(lemipc->key, 100, SHM_R | SHM_W)) == -1)
    {
      if (!create_board(lemipc) || !first_player(lemipc))
	return (0);
    }
  else
    {
      if (!next_player(lemipc))
	return (0);
    }
  return (1);
}
