/*
** tna.c for  in /home/chatea_s/a/c/zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Thu Jun 26 18:36:00 2014
** Last update Tue Jul  8 16:49:40 2014 
*/

#include <unistd.h>
#include "server.h"

int	tna_func(__attribute__((unused))char *buffer, t_server *server)
{
  int	i;

  i = -1;
  while (server->ln.team_name[++i])
    {
      memset(server->ln.response, 0, 2048);
      strcpy(server->ln.response, "tna ");
      strcat(server->ln.response, server->ln.team_name[i]);
      strcat(server->ln.response, "\n");
      write(server->ln.client_fd, server->ln.response,
	    strlen(server->ln.response));
    }
  memset(server->ln.response, 0, 2048);
  return (TRUE);
}
