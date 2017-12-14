/*
** take_ia.c for zappy in /home/duboy_m/zappy/buf/zappy
**
** Made by maxime duboy
** Login   <duboy_m@epitech.net>
**
** Started on  Fri Jun 27 14:10:47 2014 maxime duboy
** Last update Sun Jul 13 20:18:49 2014 
*/

#include "server.h"
#include "cmd_graphic.h"

int	can_drop(int obj, t_trantorian *hand, t_server *server)
{
  int	pos;

  pos = hand->posX + (server->ln.width * hand->posY);
  if (obj >= 0)
    if (hand->stones[obj] >= 1)
      {
	hand->stones[obj]--;
	server->ln.map[pos].stones[obj]++;
	return (TRUE);
      }
  if (obj == -1)
    if (hand->food >= 1)
      {
	hand->food--;
	if (hand->food == 0)
	  return (dead_ai(hand, server));
	server->ln.map[pos].food++;
	return (TRUE);
      }
  return (FALSE);
}

int		drop_item(char *token, int fd, t_server *server)
{
  int		i;
  int		ret;
  t_trantorian	*hand;
  char		*stone[6] = {"linemate", "deraumere", "sibur",
			     "mendiane", "phiras", "thystame"};

  i = 0;
  if ((hand = get_AI(fd, server)) == NULL)
    return (FALSE);
  while (i != 6)
    {
      if (strcmp(token, stone[i]) == 0)
	if (can_drop(i, hand, server) == TRUE)
	  return (i + 1);
      i++;
    }
  if (strcmp(token, "nourriture") == 0)
    {
      if ((ret = can_drop(-1, hand, server)) == TRUE)
	return (0);
      else if (ret == -2)
	return (-2);
    }
  return (FALSE);
}

int	drop_func(char *buffer, int fd, t_server *server)
{
  char	*token;
  int	ret;

  token = strtok(buffer, " ");
  token = strtok(NULL, " ");
  if (token == NULL)
    return (FALSE);
  if ((ret = drop_item(token, fd, server)) == -2)
    return (-2);
  if (get_AI(fd, server))
    get_AI(fd, server)->time_death = find_time_death(get_AI(fd, server),
						     server);
  memset(server->ln.response, 0, 2048);
  if (ret == FALSE)
    {
      write(fd, "ko\n", strlen("ko\n"));
      return (FALSE);
    }
  sprintf(server->ln.response, "ok\n");
  write(fd, server->ln.response, strlen(server->ln.response));
  call_write_server("pdr ", fd, ret, server);
  return (TRUE);
}
