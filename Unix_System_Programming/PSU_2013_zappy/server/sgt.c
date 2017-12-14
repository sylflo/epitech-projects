/*
** sgt.c for  in /home/chatea_s/a/c/zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Thu Jun 26 18:35:17 2014
** Last update Tue Jul  8 16:50:01 2014 
*/

#include "server.h"

int	sgt_func(__attribute__((unused))char *buffer, t_server *server)
{
  char	delay[10];

  if (sprintf(delay, "%d", server->ln.delay) < 0)
    return (FALSE);
  strcpy(server->ln.response, "sgt ");
  strcat(server->ln.response, delay);
  strcat(server->ln.response, "\n");
  return (TRUE);
}
