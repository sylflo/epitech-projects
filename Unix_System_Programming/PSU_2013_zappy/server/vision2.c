/*
** vision2.c for vision in /home/duboy_m/zappy/buf/zappy
**
** Made by maxime duboy
** Login   <duboy_m@epitech.net>
**
** Started on  Wed Jul  2 14:57:00 2014 maxime duboy
** Last update Sun Jul 13 21:53:26 2014 
*/

#include "server.h"

void	next_item_in_case(int pos, char *response, t_server *server)
{
  int	i;
  char	tmp[15] = {0};

  i = server->ln.map[pos].stones[3];
  strcpy(tmp, " mendiane");
  while (i-- != 0)
    strcat(response, tmp);
  i = server->ln.map[pos].stones[4];
  memset(tmp, 0, 15);
  strcpy(tmp, " phiras");
  while (i-- != 0)
    strcat(response, tmp);
  i = server->ln.map[pos].stones[5];
  memset(tmp, 0, 15);
  strcpy(tmp, " thystame");
  while (i-- != 0)
    strcat(response, tmp);
  memset(tmp, 0, 15);
  strcpy(tmp, ",");
  strcat(response, tmp);
}

void	item_in_case(int pos, char *response, int posX, int posY,
		     t_server *server)
{
  int	i;
  char	tmp[15] = {0};

  player_in_case(response, posX, posY, server);
  i = server->ln.map[pos].food;
  strcpy(tmp, " nourriture");
  while (i-- != 0)
    strcat(response, tmp);
  memset(tmp, 0, 15);
  i = server->ln.map[pos].stones[0];
  strcpy(tmp, " linemate");
  while (i-- != 0)
    strcat(response, tmp);
  memset(tmp, 0, 15);
  i = server->ln.map[pos].stones[1];
  strcpy(tmp, " deraumere");
  while (i-- != 0)
    strcat(response, tmp);
  memset(tmp, 0, 15);
  i = server->ln.map[pos].stones[2];
  strcpy(tmp, " sibur");
  while (i-- != 0)
    strcat(response, tmp);
  next_item_in_case(pos, response, server);
}

void		player_in_case(char *response, int x, int y, t_server *server)
{
  t_trantorian	*loop;
  char		tmp[8] = {0};

  strcpy(tmp, " joueur");
  if (y < 0)
    y = server->ln.height + y;
  if (y >= server->ln.height)
    y = y - server->ln.height;
  if (x < 0)
    x = server->ln.width + x;
  if (x >= server->ln.width)
    x = x - server->ln.width;
  loop = server->ln.AI;
  while (loop != NULL)
    {
      if (loop->posX == x && loop->posY == y)
	strcat(response, tmp);
      loop = loop->next;
    }
}
