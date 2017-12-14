/*
** first_cmd_all.c for  in /home/chatea_s/PSU_2013_zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Fri Jul 11 17:26:36 2014
** Last update Sun Jul 13 20:31:07 2014 
*/

#include "server.h"
#include "cmd_graphic.h"

int	check_if_team(char *buffer, t_trantorian *hand, t_server *server)
{
  int	i;

  i = 0;
  while (server->ln.team_name[i])
    {
      if (strcmp(server->ln.team_name[i], buffer) == 0)
	{
	  hand->team = i;
	  hand->is_graphic = 2;
	  if (init_AI_msg(hand, server) < 0)
	    return (FALSE);
	  return (TRUE);
	}
      i++;
    }
  return (FALSE);
}

int	first_in_client(char *buffer, t_server *server,
			t_trantorian *hand)
{
  hand->is_first = 1;
  if (strcmp(buffer, "GRAPHIC") == 0)
    {
      init_graphic(server);
      hand->is_graphic = 1;
      return (1);
    }
  if (check_if_team(buffer, hand, server) == TRUE)
    {
      check_egg_pop(hand->socket, server);
      hand->time_death = find_time_death(hand, server);
      pnw_cmd(hand, server);
      send_to_graphic(server->ln.response, server);
      exec_pin(hand, server);
      return (2);
    }
  return (FALSE);
}

int		first_command(char *buffer, int fd, t_server *server)
{
  t_trantorian	*hand;

  hand = get_AI(fd, server);
  if (hand != NULL)
    {
      if (hand->is_first == 0)
	return (first_in_client(buffer, server, hand));
      if (hand->is_graphic == 1 || hand->is_graphic == 2)
	return (0);
    }
  return (-1);
}
