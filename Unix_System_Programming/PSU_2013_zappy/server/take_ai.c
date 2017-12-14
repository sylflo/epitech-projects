/*
** take_ia.c for zappy in /home/duboy_m/zappy/buf/zappy
**
** Made by maxime duboy
** Login   <duboy_m@epitech.net>
**
** Started on  Fri Jun 27 14:10:47 2014 maxime duboy
** Last update Sun Jul 13 20:17:04 2014 
*/

#include "server.h"

int	can_take(int obj, t_trantorian *hand, t_server *server)
{
  int	pos;

  pos = hand->posX + (server->ln.width * hand->posY);
  if (obj >= 0)
    if (server->ln.map[pos].stones[obj] >= 1)
      {
	server->ln.map[pos].stones[obj]--;
	return (TRUE);
      }
  if (obj == -1)
    if (server->ln.map[pos].food >= 1)
      {
	server->ln.map[pos].food--;
	return (TRUE);
      }
  return (FALSE);
}

int		take_item(char *token, int fd, t_server *server)
{
  int		i;
  t_trantorian	*hand;
  char		*stone[6] = {"linemate", "deraumere", "sibur",
			     "mendiane", "phiras", "thystame"};

  i = 0;
  if ((hand = get_AI(fd, server)) == NULL)
    return (FALSE);
  while (i != 6)
    {
      if (strcmp(token, stone[i]) == 0)
	if (can_take(i, hand, server) == TRUE)
	  {
	    hand->stones[i]++;
	    return (i + 1);
	  }
      i++;
    }
  if (strcmp(token, "nourriture") == 0)
    if (can_take(-1, hand, server) == TRUE)
      {
	hand->food++;
	return (0);
      }
  return (FALSE);
}

int	take_func(char *buffer, int fd, t_server *server)
{
  char	*token;
  int	ret;

  token = strtok(buffer, " ");
  token = strtok(NULL, " ");
  if (token == NULL)
    return (FALSE);
  ret = take_item(token, fd, server);
  if (get_AI(fd, server))
    get_AI(fd, server)->time_death = find_time_death(get_AI(fd, server),
						     server);
  memset(server->ln.response, 0, 100);
  if (ret == FALSE)
    {
      write(fd, "ko\n", strlen("ko\n"));
      return (FALSE);
    }
  strcpy(server->ln.response, "ok\n");
  write(fd, server->ln.response, strlen(server->ln.response));
  call_write_server("pgt ", fd, ret, server);
  return (TRUE);
}
