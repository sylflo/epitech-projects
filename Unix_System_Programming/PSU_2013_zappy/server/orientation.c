/*
** move_ia.c for move_ia in /home/duboy_m/zappy/buf/zappy
**
** Made by maxime duboy
** Login   <duboy_m@epitech.net>
**
** Started on  Fri Jun 27 15:04:45 2014 maxime duboy
** Last update Sun Jul 13 20:32:00 2014 
*/

#include "server.h"
#include "cmd_graphic.h"

int		right_func(__attribute__((unused))char *buffer, int fd,
			   t_server *server)
{
  t_trantorian	*hand;

  memset(server->ln.response, 0, 2048);
  write(fd, "ok\n", 3);
  if ((hand = get_AI(fd, server)) == NULL)
    return (FALSE);
  hand->dir++;
  if (hand->dir > 4)
    hand->dir = 1;
  call_ppo(fd, server);
  return (TRUE);
}

int		left_func(__attribute__((unused))char *buffer, int fd,
			  t_server *server)
{
  t_trantorian	*hand;

  memset(server->ln .response, 0, 2048);
  write(fd, "ok\n", 3);
  if ((hand = get_AI(fd, server)) == NULL)
    return (FALSE);
  hand->dir--;
  if (hand->dir < 1)
    hand->dir = 4;
  call_ppo(fd, server);
  return (TRUE);
}
