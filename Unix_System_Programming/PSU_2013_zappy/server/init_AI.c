/*
** init_AI.c for zappy in /home/duboy_m/PSU_2013_zappy
**
** Made by maxime duboy
** Login   <duboy_m@epitech.net>
**
** Started on  Sat Jul 12 19:57:05 2014 maxime duboy
** Last update Sun Jul 13 19:10:03 2014 maxime duboy
*/

#include <unistd.h>
#include <sys/time.h>
#include "server.h"

int			check_hatch_left(t_trantorian *hand, t_server *server)
{
  char			msg[15];
  struct timeval	cur_time;

  gettimeofday(&cur_time, NULL);
  if (!timercmp(&cur_time, &hand->hatch, <=))
    return (TRUE);
  if (hand->hatch_flag == 0 && !timercmp(&cur_time, &hand->hatch, <=))
    {
      sprintf(msg, "eht %d\n", hand->socket);
      send_to_graphic(msg, server);
      server->ln.allow_team[hand->team] += 1;
      hand->hatch_flag = 1;
    }
  return (FALSE);
}

int		left_slot(char *team, t_server *server)
{
  int		left;
  t_trantorian	*hand;

  if ((hand = server->ln.AI) == NULL)
    return (FALSE);
  left = server->ln.allow_team[hand->team];
  while (hand != NULL)
    {
      if (hand->is_graphic == 2)
	{
	  if (server->ln.team_name[hand->team] != NULL)
	    if (strncmp(team, server->ln.team_name[hand->team],
			strlen(team)) == 0)
	      left--;
	}
      else if (hand->is_graphic == 3)
	if (check_hatch_left(hand, server) == TRUE)
	  left++;
      hand = hand->next;
    }
  return (left);
}

int	init_AI_msg(t_trantorian *hand, t_server *server)
{
  char	tmp[50] = {0};

  if (left_slot(server->ln.team_name[hand->team], server) >= 0)
    {
      sprintf(tmp, "%d\n", left_slot(server->ln.team_name[hand->team],
				     server));
      write(hand->socket, tmp, strlen(tmp));
      memset(tmp, 0, 50);
      sprintf(tmp, "%d %d\n", server->ln.width, server->ln.height);
      write(hand->socket, tmp, strlen(tmp));
    }
  return (left_slot(server->ln.team_name[hand->team], server));
}
