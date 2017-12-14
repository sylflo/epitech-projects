/*
** expluse.c for expulse in /home/duboy_m/zappy/buf/zappy
**
** Made by maxime duboy
** Login   <duboy_m@epitech.net>
**
** Started on  Wed Jul  2 17:11:40 2014 maxime duboy
** Last update Sun Jul 13 20:24:58 2014 maxime duboy
*/

#include "server.h"
#include "cmd_graphic.h"

void	write_expulse(int fd, int dir_fd, int orientation, t_server *server)
{
  char	tmp[50] = {0};
  int	dir;
  int	ori;

  call_ppo(fd, server);
  dir = dir_fd;
  ori = orientation;
  while (dir != NORD)
    {
      dir++;
      ori++;
      if (dir == 5)
	dir = 1;
      if (ori == 5)
	ori = 1;
    }
  if (ori == NORD)
    sprintf(tmp, "deplacement: 5\n");
  if (ori == SUD)
    sprintf(tmp, "deplacement: 1\n");
  if (ori == EST)
    sprintf(tmp, "deplacement: 3\n");
  if (ori == OUEST)
    sprintf(tmp, "deplacement: 7\n");
  write(fd, tmp, strlen(tmp));
}

void		expulse(int fd, int posX, int posY, t_server *server)
{
  t_trantorian	*loop;
  t_trantorian	*hand;
  int		i;

  i = 0;
  hand = get_AI(fd, server);
  loop = server->ln.AI;
  posX = get_posX(posX, server);
  posY = get_posX(posY, server);
  while (loop != NULL)
    {
      if (loop->socket != hand->socket && loop->is_graphic == 2)
	if (loop->posX == hand->posX && loop->posY == hand->posY)
	  {
	    write_pex(i, fd, server);
	    loop->posX = posX;
	    loop->posY = posY;
	    write_expulse(loop->socket, loop->dir, hand->dir, server);
	    i = 1;
	  }
      loop = loop->next;
    }
  write_expulse_ser(i, server, fd);
}

int	expulse_func(char *buffer, int fd, t_server *server)
{
  t_trantorian *hand;

  (void)buffer;
  if ((hand = get_AI(fd, server)) == NULL)
    return (FALSE);
  if (hand->dir == NORD)
    expulse(fd, hand->posX, hand->posY - 1, server);
  if (hand->dir == SUD)
    expulse(fd, hand->posX, hand->posY + 1, server);
  if (hand->dir == EST)
    expulse(fd, hand->posX + 1, hand->posY, server);
  if (hand->dir == OUEST)
    expulse(fd, hand->posX - 1, hand->posY, server);
  return (TRUE);
}
