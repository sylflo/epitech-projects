/*
** map_and_pos.c for  in /home/chatea_s/project/unix/lemipc/display
**
** Made by Sylvain Chateau
** Login   <chatea_s@epitech.net>
**
** Started on  Sat Mar 29 20:13:45 2014 Sylvain Chateau
** Last update Sat Mar 29 20:15:28 2014 Sylvain Chateau
*/

#include <sys/shm.h>
#include "display.h"

char	*get_map(int key)
{
  int	shm_id;
  char	*adrr;

  if ((shm_id = shmget(key, 1, SHM_R | SHM_W)) == -1)
    {
      perror("shmget");
      return (NULL);
    }
  adrr = shmat(shm_id, NULL, SHM_R | SHM_W);
  if (*(int*)(adrr) == -1)
    {
      perror("shmat");
      return (NULL);
    }
  return ((char *)adrr);
}

void	print_map(char *map)
{
  int	i;

  i = -1;
  while (map[++i])
    {
      if (i % 6 == 0 && i )
	printf("\n");
      printf("%c", map[i]);
    }
  printf("\n");
}

void	get_pos(t_display *display, int pos)
{
  display->pos.x = (pos % 6) * 101;
  display->pos.y = (pos / 6) * 101;
}
