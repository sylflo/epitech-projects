/*
** expluse.c for expulse in /home/duboy_m/zappy/buf/zappy
**
** Made by maxime duboy
** Login   <duboy_m@epitech.net>
**
** Started on  Wed Jul  2 17:11:40 2014 maxime duboy
** Last update Sun Jul 13 20:42:25 2014 maxime duboy
*/

#include "server.h"
#include "cmd_graphic.h"

void		write_expulse_ser(int i, t_server *server, int fd)
{
  memset(server->ln.response, 0, 2048);
  if (i == 1)
    sprintf(server->ln.response, "ok\n");
  if (i == 0)
    sprintf(server->ln.response, "ko\n");
  write(fd, server->ln.response, strlen(server->ln.response));
  memset(server->ln.response, 0, 2048);
}

int		get_posX(int posX, t_server *server)
{
  if (posX >= server->ln.width)
    posX = posX - server->ln.width;
  if (posX < 0)
    posX = server->ln.width + posX;
  return (posX);
}

int		get_posY(int posY, t_server *server)
{
  if (posY >= server->ln.height)
    posY = posY - server->ln.height;
  if (posY < 0)
    posY = server->ln.height + posY;
  return (posY);
}

void		write_pex(int i, int fd, t_server *server)
{
  char		fdi[20];

  if (i == 0)
    {
      sprintf(fdi, "pex %d\n", fd);
      send_to_graphic(fdi, server);
    }
}
