/*
** move_ia.c for move_ia in /home/duboy_m/zappy/buf/zappy
**
** Made by maxime duboy
** Login   <duboy_m@epitech.net>
**
** Started on  Fri Jun 27 15:04:45 2014 maxime duboy
** Last update Sun Jul 13 20:16:35 2014 
*/

#include "server.h"

void	init_see(t_trantorian *hand, t_server *server)
{
  int	pos;

  pos = (hand->posY * server->ln.width) + hand->posX;
  memset(server->ln.response, 0, 2048);
  sprintf(server->ln.response, "{");
  item_in_case(pos, server->ln.response, hand->posX, hand->posY, server);
}

int	get_true_pos(int x, int y, t_server *server)
{
  int	pos;

  pos = 0;
  if (y < 0)
    y = server->ln.height + y;
  if (y >= server->ln.height)
    y = y - server->ln.height;
  if (x < 0)
    x = server->ln.width + x;
  if (x >= server->ln.width)
    x = x - server->ln.width;
  pos = (y * server->ln.width) + x;
  return (pos);
}

void	do_see_sud(int casX, int casY, t_trantorian *hand, int level,
		   t_server *server)
{
  if (hand->dir == SUD)
    {
      casY += level;
      casX += level;
      while (casX != (hand->posX - level - 1))
	{
	  item_in_case(get_true_pos(casX, casY, server), server->ln.response,
		       casX, casY, server);
	  casX--;
	}
    }
  if (hand->dir == EST)
    {
      casY -= level;
      casX += level;
      while (casY != (hand->posY + level + 1))
	{
	  item_in_case(get_true_pos(casX, casY, server), server->ln.response,
		       casX, casY, server);
	  casY++;
	}
    }
}

void	do_see(int level, t_trantorian *hand, t_server *server)
{
  int	casX;
  int	casY;

  casX = hand->posX;
  casY = hand->posY;
  if (hand->dir == NORD)
    {
      casY -= level;
      casX -= level;
      while (casX != (hand->posX + level + 1))
	{
	  item_in_case(get_true_pos(casX, casY, server), server->ln.response,
		       casX, casY, server);
	  casX++;
	}
    }
  if (hand->dir == OUEST)
    {
      casY += level;
      casX -= level;
      while (casY-- != (hand->posY - level - 1))
	item_in_case(get_true_pos(casX, casY, server), server->ln.response,
		     casX, casY, server);
    }
  do_see_sud(casX, casY, hand, level, server);
}

int		see_func(__attribute__((unused))char *buffer, int fd,
			 t_server *server)
{
  t_trantorian	*hand;
  int		level;

  if ((hand = get_AI(fd, server)) == NULL)
    return (FALSE);
  level = 0;
  init_see(hand, server);
  while (level != hand->level)
    {
      level++;
      do_see(level, hand, server);
    }
  server->ln.response[strlen(server->ln.response) - 1] = '}';
  strcat(server->ln.response, "\n");
  write(fd, server->ln.response, strlen(server->ln.response));
  memset(server->ln.response, 0, 2048);
  return (TRUE);
}
