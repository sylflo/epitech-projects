/*
** command_2.c for zappy in /home/duboy_m/zappy/buf/zappy
**
** Made by maxime duboy
** Login   <duboy_m@epitech.net>
**
** Started on  Thu Jun 26 16:42:09 2014 maxime duboy
** Last update Sun Jul 13 19:17:40 2014 
*/

#include <unistd.h>
#include <sys/time.h>
#include <math.h>
#include "server.h"
#include "cmd_graphic.h"

int		send_to_graphic(char *msg, t_server *server)
{
  t_trantorian	*hand;

  hand = server->ln.AI;
  if (msg == NULL)
    return (FALSE);
  while (hand != NULL)
    {
      if (hand->is_graphic == 1)
	write(hand->socket, msg, strlen(msg));
      hand = hand->next;
    }
  memset(server->ln.response, 0, 2048);
  return (TRUE);
}

int		inv_func(__attribute__((unused))char *buffer, int fd,
			 t_server *server)
{
  t_trantorian *hand;
  char		tmp[100] = {0};

  memset(server->ln.response, 0, 2048);
  if ((hand = get_AI(fd, server)) == NULL)
    return (FALSE);
  hand->food = round((hand->time_death
  		      - convert_to_micro(&server->ln.current_time))
  		     / (((double)126 / server->ln.delay) * 1000000));
  if (sprintf(tmp, "{nourriture %d, linemate %d, deraumere %d, \
sibur %d, mendiane %d, phiras %d, thystame %d}\n", hand->food,
	      hand->stones[0], hand->stones[1], hand->stones[2],
	      hand->stones[3], hand->stones[4], hand->stones[5]) < 0)
    return (FALSE);
  strcat(server->ln.response, tmp);
  write(fd, server->ln.response, strlen(server->ln.response));
  memset(server->ln.response, 0, 2048);
  return (TRUE);
}

int	command_AI(char *buffer, int fd, t_server *server)
{
  int	i;
  char	*token;
  char	*command[12] = {"prend", "pose", "inventaire", "avance",
			"droite", "gauche", "incantation",
			"voir", "expulse", "fork", "broadcast",
			"connect_nbr"};

  token = strdup(buffer);
  token = strtok(token, " ");
  i = 0;
  while (i < 12 && strcmp(command[i], token))
    ++i;
  free(token);
  if (i < 12)
    return (server->ln.command_func[i](buffer, fd, server));
  strcpy(server->ln.response, "suc\n");
  return (TRUE);
}
