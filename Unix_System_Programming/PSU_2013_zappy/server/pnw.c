/*
** pnw.c for  in /home/chatea_s/zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Sat Jun 28 14:49:01 2014
** Last update Sat Jul 12 19:36:42 2014 
*/

#include "server.h"
#include "cmd_graphic.h"

int	pnw_cmd(t_trantorian *new, t_server *server)
{
  memset(server->ln.response, 0, 2048);
  sprintf(server->ln.response, "pnw %d %d %d %d %d %s\n", new->socket,
	  new->posX, new->posY, new->dir, new->level,
	  server->ln.team_name[new->team]);
  return (TRUE);
}

void	exec_pin(t_trantorian *hand, t_server *server)
{
  char	cmd_pin[10] = {"pin "};
  char	fd_char[10];

  memset(server->ln.response, 0, 2048);
  sprintf(fd_char, "%d", hand->socket);
  strcat(cmd_pin, fd_char);
  strcat(cmd_pin, "\n");
  pin_func(cmd_pin, server);
  send_to_graphic(server->ln.response, server);
  memset(server->ln.response, 0, 2048);
}
