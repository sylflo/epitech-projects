/*
** parsing.c for zappy in /home/duboy_m/zappy/zappy
**
** Made by maxime duboy
** Login   <duboy_m@epitech.net>
**
** Started on  Thu Jun 19 20:21:34 2014 maxime duboy
** Last update Sun Jul 13 21:52:20 2014 
*/

#include <time.h>
#include "server.h"

void	print_stone(int posCase, t_server *server)
{
  int	i;

  i = -1;
  printf("func print_stones\n");
  while (++i < 6)
    printf("%d ", server->ln.map[posCase].stones[i]);
}

int	full_map(t_server *server)
{
  int	i;
  int	z;

  i = 0;
  while (i != (server->ln.width * server->ln.height))
    {
      server->ln.map[i].food = rand() % 3;
      z = -1;
      while (++z < 6)
	server->ln.map[i].stones[z] = 0;
      if (i % 2 == 0)
	server->ln.map[i].stones[rand() % 6] = 1;
      i++;
    }
  return (TRUE);
}

int	init_map(t_server *server)
{
  if ((server->ln.map = malloc((server->ln.width * server->ln.height + 1)
			       * sizeof(t_case))) == NULL)
    {
      perror("Malloc");
      exit(FALSE);
    }
  srand(time(NULL));
  full_map(server);
  return (TRUE);
}
