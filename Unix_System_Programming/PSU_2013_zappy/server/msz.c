/*
** msz.c for  in /home/chatea_s/a/c/zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Thu Jun 26 18:34:55 2014
** Last update Sat Jul 12 19:39:33 2014 
*/

#include "server.h"

int	msz_func(__attribute__((unused))char *buffer, t_server *server)
{

  (void)buffer;
  sprintf(server->ln.response,
	  "msz %d %d\n", server->ln.width, server->ln.height);
  return (TRUE);
}
