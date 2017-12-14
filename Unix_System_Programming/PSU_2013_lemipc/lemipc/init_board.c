/*
** init_board.c for  in /home/chatea_s/project/unix/lemipc
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Sat Mar 29 19:52:49 2014 Sylvain Chateau
** Last update Sun Mar 30 19:00:40 2014 edouard mansuy
*/

#include "lemipc.h"

int	create_board(t_lemipc *lemipc)
{
  if ((lemipc->shm_id =
       shmget(lemipc->key, 100, IPC_CREAT | SHM_R | SHM_W)) == -1)
    {
      perror("shmget");
      return (0);
    }
  lemipc->addr = shmat(lemipc->shm_id, NULL, SHM_R | SHM_W);
  if (*(int *)lemipc->addr == -1)
    {
      perror("shmat");
      return (0);
    }
  sprintf((char *) lemipc->addr, "oooooooooooooooooooooooooooooooooooo");
  printf("Creating shm = %d\n", lemipc->shm_id);
  return (1);
}

int	create_map(t_lemipc *lemipc)
{
  int	i;
  int	k;

  if ((lemipc->map = malloc(sizeof(char *) * (7 + 1))) == NULL)
    {
      perror("malloc");
      return (0);
    }
  i = 0;
  k = 0;
  while (lemipc->addr[i])
    {
      if ((lemipc->map[k] = malloc(sizeof(char) * 8)) == NULL)
	{
	  perror("malloc");
	  return (0);
	}
      fill_map(lemipc, &k, &i);
    }
  lemipc->map[6] = NULL;
  return (1);
}

void	add_player_in_map(t_lemipc *lemipc)
{
  int	index;

  lemipc->access++;
  index = rand() % 36;
  while (lemipc->addr[index] != 'o')
    index = rand() % 36;
  lemipc->addr[index] = (char)lemipc->team;
  lemipc->pos_player = index;
}

void	fill_map(t_lemipc *lemipc, int *k, int *i)
{
  int	j;

  j = 0;
  while (j < 6)
    {
      lemipc->map[*k][j] = lemipc->addr[*i];
      (*i)++;
      j++;
    }
  lemipc->map[*k][j++] = '\0';
  (*k)++;
}

void	free_tab(char **map)
{
  int	i;

  i = -1;
  while (map[++i])
    free(map[i]);
  free(map);
}
