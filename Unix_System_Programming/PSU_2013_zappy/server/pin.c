/*
** ppo.c for  in /home/chatea_s/zappy
**
** Made by
** Login   <chatea_s@epitech.net>
**
** Started on  Sun Jun 29 18:02:22 2014
** Last update Sun Jul 13 21:48:27 2014 
*/

#include <math.h>
#include "server.h"

void	fill_pos_pin(char id_char[10], char posX_char[10], char posY_char[10],
		     t_server *server)
{
  strcat(server->ln.response, id_char);
  strcat(server->ln.response, " ");
  strcat(server->ln.response, posX_char);
  strcat(server->ln.response, " ");
  strcat(server->ln.response, posY_char);
  strcat(server->ln.response, " ");
}

int	fill_pos_resource(t_trantorian *hand, t_server *server)
{
  int	i;
  char	food_char[10];
  char	stones_char[6][10];

  i = -1;
  if (sprintf(food_char, "%d", hand->food) < 0)
    return (FALSE);
  strcat(server->ln.response, food_char);
  while (++i < 6)
    {
      if (sprintf(stones_char[i], "%d", hand->stones[i]) < 0)
	return (FALSE);
      strcat(server->ln.response, " ");
      strcat(server->ln.response, stones_char[i]);
    }
  strcat(server->ln.response, "\n");
  return (TRUE);
}

int	fill_inventary(char *token, t_server *server)
{
  int	id_player;
  char	id_char[10];
  char	posX_char[10];
  char	posY_char[10];

  id_player = atoi(token);
  if (!get_AI(id_player, server))
    return (-2);
  if (get_AI(id_player, server)->is_graphic == 2)
    {
      if (sprintf(posX_char, "%d", get_AI(id_player, server)->posX) < 0 ||
	  sprintf(posY_char, "%d", get_AI(id_player, server)->posY) < 0 ||
	  sprintf(id_char, "%d", get_AI(id_player, server)->socket) < 0)
	return (FALSE);
      fill_pos_pin(id_char, posX_char, posY_char, server);
      if (fill_pos_resource(get_AI(id_player, server), server) == FALSE)
	return (FALSE);
      return (TRUE);
    }
  return (-2);
}

void		change_time_ai(t_server *server)
{
  t_trantorian	*ai;

  ai = server->ln.AI;
  while (ai)
    {
      if (ai->is_graphic == 2)
	{
	  ai->food = round((ai->time_death
	  		    - convert_to_micro(&server->ln.current_time))
	  		   / (((double)126 / server->ln.delay) * 1000000));

	}
      ai = ai->next;
    }
}

int	pin_func(char *buf, t_server *server)
{
  char	*token;
  int	i;
  int	ret;

  i = 0;
  token = strtok(buf, " ");
  while (token)
    {
      if (i == 0)
	strcpy(server->ln.response, "pin ");
      else if (i == 1)
	{
	  if ((ret = fill_inventary(token, server)) == FALSE)
	    return (FALSE);
	  else if (ret == -2)
	    return (-2);
	}
      token = strtok(NULL, " ");
      i++;
    }
  change_time_ai(server);
  if (i != 2)
    return (-2);
  return (TRUE);
}
