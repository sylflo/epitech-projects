/*
** mct.c for  in /home/chatea_s/a/c/zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Thu Jun 26 18:40:21 2014
** Last update Sat Jul 12 19:40:11 2014 
*/

#include <unistd.h>
#include "server.h"
#include "cmd_graphic.h"

int	mct_func(__attribute__((unused))char *buffer, t_server *server)
{
  int	posX;
  int	posY;

  posX = -1;
  while (++posX < server->ln.width)
    {
      posY = -1;
      while (++posY < server->ln.height)
	{
	  object_in_case(posX, posY, server);
	  write(server->ln.client_fd, server->ln.response,
		strlen(server->ln.response));
	  memset(server->ln.response, 0, 2048);
	}
    }
  memset(server->ln.response, 0, 2048);
  return (TRUE);
}
