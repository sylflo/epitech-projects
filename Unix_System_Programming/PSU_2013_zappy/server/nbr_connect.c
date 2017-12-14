/*
** command_2.c for zappy in /home/duboy_m/zappy/buf/zappy
**
** Made by maxime duboy
** Login   <duboy_m@epitech.net>
**
** Started on  Thu Jun 26 16:42:09 2014 maxime duboy
** Last update Sat Jul 12 19:59:21 2014 maxime duboy
*/

#include <unistd.h>
#include "server.h"

int		connect_nbr_func(__attribute__((unused))char *buf,
				 int fd, t_server *server)
{
  t_trantorian	*hand;

  hand = get_AI(fd, server);
  sprintf(server->ln.response, "%d\n",
	  left_slot(server->ln.team_name[hand->team], server));
  write(fd, server->ln.response, strlen(server->ln.response));
  memset(server->ln.response, 0, 2048);
  return (TRUE);
}
