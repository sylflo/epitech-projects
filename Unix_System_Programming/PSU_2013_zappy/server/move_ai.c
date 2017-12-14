/*
** move_ia.c for move_ia in /home/duboy_m/zappy/buf/zappy
**
** Made by maxime duboy
** Login   <duboy_m@epitech.net>
**
** Started on  Fri Jun 27 15:04:45 2014 maxime duboy
** Last update Sun Jul 13 18:12:38 2014 maxime duboy
*/

#include "server.h"
#include "cmd_graphic.h"

void	do_move_y(t_trantorian *hand, t_server *server)
{
  if (hand->dir == SUD)
    {
      hand->posY += 1;
      if (hand->posY > server->ln.height - 1)
	hand->posY = 0;
    }
  if (hand->dir == NORD)
    {
      hand->posY -= 1;
      if (hand->posY < 0)
	hand->posY = server->ln.height - 1;
    }
}

void	do_move_x(t_trantorian *hand, t_server *server)
{
  if (hand->dir == EST)
    {
      hand->posX += 1;
      if (hand->posX > server->ln.width - 1)
	hand->posX = 0;
    }
  if (hand->dir == OUEST)
    {
      hand->posX -= 1;
      if (hand->posX < 0)
	hand->posX = server->ln.width - 1;
    }
}

void	move_ia(t_trantorian *hand, t_server *server)
{
  if (hand->dir == NORD || hand->dir == SUD)
    do_move_y(hand, server);
  if (hand->dir == EST || hand->dir == OUEST)
    do_move_x(hand, server);
}

int		move_func(__attribute__((unused))char *buffer, int fd,
			  t_server *server)
{
  t_trantorian	*hand;

  memset(server->ln.response, 0, 2048);
  write(fd, "ok\n\0", 4);
  if ((hand = get_AI(fd, server)) == NULL)
    return (FALSE);
  move_ia(hand, server);
  call_ppo(fd, server);
  return (TRUE);
}
